#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRB = 0b11111111;					//PORTB is outut
	while(1)
	{
		unsigned int a = 0b00000001;	//Declare initial data
		for (int i=0; i<=7; i++)
		{
			PORTB = a;					//Put data in PORTB register
			_delay_ms(250);				//Delay for 250 milliseconds
			a = a<<1;					//Shift a to left by 1
		}
	}
}