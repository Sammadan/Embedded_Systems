#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRB=0b11111111;
        DDRC = 0b11111111;
	while(1)
	{	
		PORTB = 0b11110000;
		_delay_ms(100);
		PORTB = 0b00001111;
		_delay_ms(100);
	}	
}
