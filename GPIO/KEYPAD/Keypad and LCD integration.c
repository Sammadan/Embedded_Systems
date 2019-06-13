#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>
#include <keypad.h>

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
	
	unsigned char value = 0;
	
	while(1)
	{
		dis_cmd(0x80);
		dis_string("PRESS A BUTTON  ");
		
		value = key();

		dis_cmd(1);
		_delay_ms(10);

		dis_cmd(0x8f);
		dis_number(value);
		PORTB = value;

		_delay_ms(2000);
	}
}
