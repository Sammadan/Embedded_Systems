#include <avr/io.h>
#include <util/delay.h>
#include <avr/lcd.h>

void main()
{
	DDRB = 0b11111111;
	DDRC = 0b11111111;
	lcd_init();
	while(1)
	{
		dis_cmd(0x80);
		dis_string("FORWARD MOTION  ");
		PORTB = 0b00001010;
		_delay_ms(2000);

		dis_cmd(0x80);
		dis_string("BACKWARD MOTION ");
		PORTB = 0b00000101;
		_delay_ms(2000);

		dis_cmd(0x80);
		dis_string("LEFT MOTION     ");
		PORTB = 0b00001001;
		_delay_ms(2000);

		dis_cmd(0x80);
		dis_string("RIGHT MOTION    ");
		PORTB = 0b00000110;
		_delay_ms(2000);

		dis_cmd(0x80);
		dis_string("STOP            ");
		PORTB = 0b00000000;
		_delay_ms(2000);
	}
}