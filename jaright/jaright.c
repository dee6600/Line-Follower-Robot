#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
void fwd()
{
PORTB=0b00001001;
_delay_ms(50);
PORTB=0b00000000;
_delay_ms(100);
}
void left()
{
PORTB=0b00000001;
_delay_ms(50);
PORTB=0b00000000;
_delay_ms(100);
}
void ontrackr()
	{
	while(1)
		{
		
			PORTB=0b00001000;
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
		
			PORTB=0b00000001;
			if((PINA & 0b00000111)==0b00000101)
			{
				break;
			}
		}
	}



void right()
	{
	PORTB=0b00001000;
	_delay_ms(50);
	PORTB=0b00000000;
	_delay_ms(100);
	}
void stop()
{
PORTB=0b00000000;
}
void main()
{
	DDRA=0;
	lcd_init();
	DDRB=0xff;
	while(1)
	{
		if((PINA & 0b00010000)==0b00000000)
		{
			//line follow
			lcd_gotoxy(4,0);
			lcd_printc("line");
			while(1)
			{
				if((PINA & 0b00010000)==0b00010000)
				{
					break;
				}
				if((PINA & 0b00000111)==0b00000000)
				{
					fwd();
				}
			
				if((PINA & 0b00000111)==0b00000011)
				{
					right();
				}
			
				if((PINA & 0b00000111)==0b00000101)
				{
					fwd();
				}
				if((PINA & 0b00000111)==0b00000110)
				{
					right();
				}
				if((PINA & 0b00000111)==0b00000111)
				{
					fwd();
				}
				if((PINA & 0b00000111)==0b00000100)
				{
					ontrackl();
				}
				if((PINA & 0b00000111)==0b00000001)
				{
					ontrackr();
				}
				if((PINA & 0b00000111)==0b00000010)
				{
					ontrackr();
				}									
			
			
			}
		}
		if((PINA & 0b00010000)==0b00010000)
		{
			//obstacle ahead
			lcd_gotoxy(4,0);
			lcd_printc("obsta");
			while(1)
			{
				while(1)
				{
					_delay_ms(100);
					if((PINA & 0b00001000)==0b00000000)	//termitate when turned 90 deg flawww
					break;								
					right();
					
				}
				//now wall follow
				while(1)
				{
					if((PINA & 0b00000111)==0b00000101) //till it return on line
					break;
					if((PINA & 0b00001000)==0b00001000)
					{
						right();
					}	
					else
					{
						left();
					}	
				}
				if((PINA & 0b00000111)==0b00000101) //till it return on line
				{
					break;
				}
			}
		}
	}
}

