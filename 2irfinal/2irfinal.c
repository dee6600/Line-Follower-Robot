#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
void fwd()
{
PORTB=0b00001001;
	_delay_ms(40);
	PORTB=0b00000000;
	_delay_ms(30);

}
void right()
{
	while(1)
		{
			lcd_gotoxy(4,0);
			lcd_printc("ontr");		
			PORTB=0b00000001;
			if((PINA & 0b00000111)==0b00000101)
			{
				break;
			}
		}
}
void left()
{
		while(1)
		{
			lcd_gotoxy(4,0);
			lcd_printc("ontl");
			PORTB=0b00001000;
			if((PINA & 0b00000111)==0b00000101)
			{
				break;
			}
		}
}
void stop()
{
	PORTB=0b00000000;
}
int main()
	{
	DDRA=0;
	lcd_init();
	DDRB=0xff;
	while(1)
	{
		if((PINA & 0b00000101)==0b00000101)
		{
			fwd();
		}
		if((PINA & 0b00000101)==0b00000001)
		{
			left();
		}
		if((PINA & 0b00000101)==0b00000100)
		{
			right();
		}
		if((PINA & 0b00000101)==0b00000000)
		{
			fwd();
		}
		if((PINA & 0b00000111)==0b00000111)
		{
			fwd();
		}
		if((PINA & 0b00000101)==0b00000101)
		{
			fwd();
		}
				
	}
}
