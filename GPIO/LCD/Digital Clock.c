/*
LCD POSITIONS
---------------------------------------------------------------------------------
|0x80|0x81|0x82|0x83|0x84|0x85|0x86|0x87|0x88|0x89|0x8A|0x8B|0x8C|0x8D|0x8E|0x8F|
---------------------------------------------------------------------------------
|0xC0|0xC1|0xC2|0xC3|0xC4|0xC5|0xC6|0xC7|0xC8|0xC9|0xCA|0xCB|0xCC|0xCD|0xCE|0xCF|
---------------------------------------------------------------------------------

DIGITAL CLOCK FORMAT
---------------------------------
| | | | |H|H|:|M|M|:|S|S| | | | |
---------------------------------
|M|Y| |D|I|G|I|T|A|L| |C|L|O|C|K|
---------------------------------
*/

#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>

void main()
{
	DDRC = 0b11111111;
	lcd_init();
	unsigned int h,m,s = 0;
	dis_cmd(1);						//Clear the screen
	_delay_ms(10);
	dis_cmd(0xC0);
	dis_string("MY DIGITAL CLOCK");

	while(1)
	{
		dis_cmd(0x88);
		dis_number(m);

		dis_cmd(0x85);
		dis_number(h);

		dis_cmd(0x86);
		dis_data(':');

		dis_cmd(0x89);
		dis_data(':');

		while(s<60)
		{
			dis_cmd(0x8B);
			dis_number(s);
			_delay_ms(500);
			s++;
	
			dis_cmd(0x86);
			dis_data(' ');

			dis_cmd(0x89);
			dis_data(' ');

			_delay_ms(500);

			dis_cmd(0x86);
			dis_data(':');

			dis_cmd(0x89);
			dis_data(':');
		}
		s = 0;
		m++;
		if(m>59)
		{
			m = 0;
			h++;
		}
		if(h>24)
		{
			h = 0;
		}
	}
}
