#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
int j=0;
void fwd()
{
	lcd_gotoxy(4,0);
	lcd_printc("fwdd");
	PORTB=0b00001001;
}
void left()
{
	lcd_gotoxy(4,0);
	lcd_printc("left");
	PORTB=0b00001000;
}
void right()
{
	lcd_gotoxy(4,0);
	lcd_printc("rght");
	PORTB=0b00000001;
}
void stop()
{
	lcd_gotoxy(4,0);
	lcd_printc("fwd");
	PORTB=0b00000000;
}
void junction()
{
	while(1)
	{
		lcd_gotoxy(4,0);
		lcd_printc("junc");
		PORTB=0b00001001;
		_delay_ms(50);
		PORTB=0b00000000;
		_delay_ms(80);
		if((PINA & 0b00000111)==0b00000101)
		{
			j++;
			lcd_gotoxy(4,1);
			lcd_printnum(j);
			break;
			return;
		}	
	}
}
void back()
{
	while(1)
	{
		PORTB=0b00000110;
		lcd_gotoxy(4,0);
		lcd_printc("back");
		if((PINA & 0b00000111)!=0b00000111)
		break;
		
	}
}
void ontrackr()
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



void ontrackl()
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

void main()
{
	DDRA=0;
	lcd_init();
	DDRB=0xff;
	while(1)
	{
		if((PINA & 0b00000111)==0b00000000)
		{
			junction();	
		}
		if((PINA & 0b00000111)==0b00000001)
		{
			ontrackl();
		}
		if((PINA & 0b00000111)==0b00000010)
		{
			fwd();
		}
		if((PINA & 0b00000111)==0b00000011)
		{
			ontrackl();
		}
		if((PINA & 0b00000111)==0b00000100)
		{
			ontrackr();
		}
		if((PINA & 0b00000111)==0b00000101)
		{
			fwd();
		}
		if((PINA & 0b00000111)==0b00000110)
		{
			ontrackr();
		}
		if((PINA & 0b00000111)==0b00000111)
		{
		//	back();
			fwd();
		}
	}
}
