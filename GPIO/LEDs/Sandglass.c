#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRB=0b11111111;
	while(1)
	{	
		int b=0b00000000;
		for(int i=7; i>=0; i--)
		{
			int a=0b00000001;
			for(int j=0; j<=i; j++)
			{
				PORTB=a+b;	
				_delay_ms(100);
				a=a<<1;
			}
			b=PORTB;
		}
	}	
}