#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>
#include <keypad.h>

void app_init();
unsigned int pass_entered = 0;

void main()
{
	DDRC = 0b11111111;
	DDRB = 0b11111111;
	DDRA = 0b00000000;
	PORTA = 0b11111111;
	DDRD = 0b11111111;

	lcd_init();
	
	dis_cmd(1);
	_delay_ms(10);

	dis_cmd(0x80);
	dis_string("CYBORG          ");
	dis_cmd(0xC0);
	dis_string("LABS...         ");
	_delay_ms(2000);
	dis_cmd(1);
	_delay_ms(10);
	
	dis_cmd(0x80);
	dis_string("PASSWORD PROTECT");
	dis_cmd(0xC0);
	dis_string("APPLICATION     ");
	_delay_ms(2000);
	dis_cmd(1);
	_delay_ms(10);

	unsigned int pass_enter_counter = 0;
	unsigned int wrong_pass_counter = 0;
	while(1)
	{
		unsigned char x = key();
		if((x>=0 && x<=9) && (pass_enter_counter < 4))
		{
			pass_entered = ((pass_entered*10)+x);
			dis_cmd(0x8f);
			dis_number(pass_entered);
			pass_enter_counter++;
		}

		if(x == 10)
		{
			dis_cmd(1);
			_delay_ms(10);
			dis_cmd(0x80);
			dis_string("VERIFYING...    ");	
			_delay_ms(1000);
			
			if(pass_entered == 9687)
			{
				PORTB = 0b11111111;
				dis_cmd(1);
				_delay_ms(10);
				dis_cmd(0x80);
				dis_string("ACCESS GRANTED  ");
				_delay_ms(3000);
				PORTB = 0b00000000;
				dis_cmd(1);
				_delay_ms(10);
				wrong_pass_counter = 0;
			}
			else
			{
				PORTB = 0b11110000;
				dis_cmd(1);
				_delay_ms(10);
				dis_cmd(0x80);
				dis_string("ACCESS DENIED   ");
				_delay_ms(3000);
				PORTB = 0b00000000;
				dis_cmd(1);
				_delay_ms(10);
				wrong_pass_counter++;
				if(wrong_pass_counter == 4)
				{
					while(1)
					{
						PORTC &= ~(1<<3);
						dis_cmd(1);
						_delay_ms(1000);
						dis_cmd(0x80);
						dis_string("SYSTEM DISABLED ");
						PORTC |= (1<<3);
						_delay_ms(1000);
					}
					
				}
			}
			app_init();
		}
	}
}

void app_init()
{
	dis_cmd(0x80);
	dis_string("ENTER YOUR      ");
	dis_cmd(0xC0);
	dis_string("4 DIGIT PASSCODE");
	_delay_ms(2000);
	dis_cmd(1);
	_delay_ms(10);
	pass_entered = 0;
}

