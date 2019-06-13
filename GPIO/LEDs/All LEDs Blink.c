#include <avr/io.h>
#include <util/delay.h>

void main()
{
	DDRB = 0b11111111;				//PORTB output
	while(1)
	{
		PORTB = 0b11111111;			//5V output from PORTB
		_delay_ms(500); 			//Delay of 500 milliseconds
		PORTB = 0b00000000;			//0V out from PORTB
		_delay_ms(500);				//Delay of 500 milliseconds
	}
}