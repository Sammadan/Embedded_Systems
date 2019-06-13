#include <avr/io.h>
#include <util/delay.h>
#include <avr/lcd.h>

void main()
{
	DDRC = 0b11111111;
	lcd_init();
	while(1)
	{
		dis_cmd(1);						//Clear the screen
		_delay_ms(10);

		for(int i=0; i<=20; i++)
		{
			dis_cmd(0x8f);
			dis_number(i);
			_delay_ms(250);
		}
	}
}