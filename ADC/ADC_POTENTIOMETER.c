#include <avr/io.h>
#include <util/delay.h>
#include <avr/lcd.h>
#include <avr/adc.h>

void main()
{
	DDRC = 0b11111111;
	lcd_init();
	adc_init();
	unsigned int adc_data = 0;
	while(1)
	{
		adc_data = adc_read(0);
		dis_cmd(0x8f);
		dis_number(adc_data);
		_delay_ms(200);
		dis_cmd(1);
		_delay_ms(1);
	}
}