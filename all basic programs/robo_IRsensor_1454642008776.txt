#include<avr/io.h>
#define F_CPU 16000000
#include<util/delay.h>
#include<i3indya/lcd16.h>
void fwd()
{
PORTB=0b00001001;
}
void left()
{
PORTB=0b00001000;
}
void right()
{
PORTB=0b00000001;
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
if((PINA & 0b00000011)==0b00000011)
{
fwd();
}
else if((PINA & 0b00000011)==0b00000001)
{
left();
}
else if((PINA & 0b00000011)==0b00000010)
{
right();
}
else if((PINA & 0b00000011)==0b00000000)
{
stop();
}
}
}
