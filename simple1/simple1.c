#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
void main()
{
DDRB=0x0f;
while(1)
{
PORTB=0b00001001; //forward
_delay_ms(50);
PORTB=0b00000000;
_delay_ms(80); //backward
}
}

