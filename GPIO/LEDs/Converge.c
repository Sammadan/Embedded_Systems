#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRB = 0b11111111;
	unsigned int a = 0;
	unsigned int b = 0;
	while(1)
	{
		a = 0b00000001;
		b = 0b10000000;
		for(int i=0; i<=3; i++)
		{
			PORTB = (a|b);
			delay_ms(250);
			a = a<<1;
			b = b>>1;
		}
	}
}