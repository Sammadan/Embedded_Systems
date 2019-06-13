#define lcd_port PORTC

void lcd_cmd(unsigned char a)
{
	lcd_port = a;
	lcd_port &= ~(1<<0);
	lcd_port &= ~(1<<1);
	lcd_port |= (1<<2);
	_delay_ms(1);
	lcd_port &= ~(1<<2);
}

void lcd_data(unsigned char a)
{
	lcd_port = a;
	lcd_port |= (1<<0);
	lcd_port &= ~(1<<1);
	lcd_port |= (1<<2);
	_delay_ms(1);
	lcd_port &= ~(1<<2);
}

void dis_cmd(unsigned char a)
{
	unsigned char div=0;
	div = (a & 0xF0);
	lcd_cmd(div);
	div = ((a<<4)&(0xF0));
	lcd_cmd(div);
}

void dis_data(unsigned char a)
{
	unsigned char div=0;
	div = (a & 0xF0);
	lcd_data(div);
	div = ((a<<4)&(0xF0));
	lcd_data(div);
}

void lcd_init()
{
	dis_cmd(0x02);
	dis_cmd(0x28);
	dis_cmd(0x0C);
	dis_cmd(0x06);
}

void dis_string(unsigned char *str)
{
	unsigned char i =0;
	while(str[i]!='\0')
	{
		dis_data(str[i]);
		i++;
	}
}

void dis_number( unsigned int num)
{
	unsigned int a = 0;
	dis_cmd(0x04);
	if(num==0)
	{
		dis_data('0');
		dis_data('0');	
	}
	while (num!=0)
	{		
		a = (num%10);
		dis_data(a+48);
		num = (num/10);
	}
	dis_cmd(0x06);
}