#include <avr/io.h>
#include <util/delay.h>
#include <lcd.h>

void main()
{
	DDRC = 0b11111111;
	lcd_init();
	custom_character();
	unsigned char i = 0;
	while(1)
	{
		dis_cmd(0x80);
		for(i=0; i<8; i++)
			dis_data(i);
	}
}

void custom_character()
{
	dis_cmd(0x40);
	dis_data(0b00011111);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00011111);
	dis_data(0b00000000);

	dis_cmd(0x48);
	dis_data(0b00001010);
	dis_data(0b00010101);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00001010);
	dis_data(0b00000100);
	dis_data(0b00000000);
	dis_data(0b00000000);

	dis_cmd(0x50);
	dis_data(0b00000000);
	dis_data(0b00001010);
	dis_data(0b00000000);
	dis_data(0b00000000);
	dis_data(0b00010001);
	dis_data(0b00001110);
	dis_data(0b00000000);
	dis_data(0b00000000);

	dis_cmd(0x58);
	dis_data(0b00001110);
	dis_data(0b00011111);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00011111);
	dis_data(0b00011111);
	dis_data(0b00011111);
	dis_data(0b00000000);

	dis_cmd(0x60);
	dis_data(0b00000001);
	dis_data(0b00000111);
	dis_data(0b00001001);
	dis_data(0b00010001);
	dis_data(0b00010001);
	dis_data(0b00011011);
	dis_data(0b00011011);
	dis_data(0b00000000);

	dis_cmd(0x68);
	dis_data(0b00000000);
	dis_data(0b00001110);
	dis_data(0b00010001);
	dis_data(0b00011111);
	dis_data(0b00011011);
	dis_data(0b00011011);
	dis_data(0b00011111);
	dis_data(0b00000000);

	dis_cmd(0x70);
	dis_data(0b00000001);
	dis_data(0b00000001);
	dis_data(0b00000101);
	dis_data(0b00000101);
	dis_data(0b00010101);
	dis_data(0b00010101);
	dis_data(0b00010101);
	dis_data(0b00000000);

	dis_cmd(0x78);
	dis_data(0b00011111);
	dis_data(0b00010101);
	dis_data(0b00001110);
	dis_data(0b00000100);
	dis_data(0b00000100);
	dis_data(0b00000100);
	dis_data(0b00000100);
	dis_data(0b00000000);
}
