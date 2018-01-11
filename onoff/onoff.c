#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
void main()
{
	DDRA=0;
	lcd_init();
	DDRB=0xff;
	while(1)
	{
		
		if((PINA & 0b00000010)==0b00000010)
		{
			lcd_gotoxy(1,0);
			lcd_printc("o1");	
		}
		else
		{
			lcd_gotoxy(1,0);
			lcd_printc("f1");
		}		

	}
}
