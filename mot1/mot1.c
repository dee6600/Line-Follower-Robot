#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
void main()
{
	DDRB=0x0f;
	while(1)
	{
		if((PINA & 0b00111000)==0b00001000)
		{
			PORTB=0b00001000;
		}	
		else
		{
			PORTB=0b00000001;
		}
	}

}































































































































