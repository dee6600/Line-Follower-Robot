#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
int i=0;

void junction()
{
	//PORTB=0b00001001;
	while(1)
	{if((PINA & 0b00000111)==0b00000000)
	{
		i++;
		lcd_gotoxy(4,0);
		lcd_printnum(i);
		//_delay_ms(1000);
		break;
		return;
		
	}
	}
}

void main()
{
	DDRA=0;
	lcd_init();
	DDRB=0xff;
		lcd_gotoxy(4,1);
		lcd_printc("work");
	//	_delay_ms(1000);
	
	while(1)
	{
		if((PINA & 0b00000111)==0b00000001) 	
	

		{
			junction();
		}
	}
}
