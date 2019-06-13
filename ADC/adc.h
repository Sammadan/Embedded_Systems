void adc_init()
{
	ADCSRA|=(1<<ADEN);//enables adc
	ADMUX|=(1<<REFS0);//SELECTS VOLTAGE
	ADCSRA|=(1<<ADPS2)|(1<<ADPS1)|(1<<ADPS0);//DECIDES FREQUENCY
}

unsigned int adc_read(unsigned char ABC)
{	
	ADMUX=(0b01000000|ABC);//pinselect
	ADCSRA|=(1<<ADSC);
	while(ADCSRA&(1<<ADIF));//while (1)
	ADCSRA|=(1<<ADIF);//to make interupt flag 0 again
	return(ADC);//adc=adch+adcl
}
