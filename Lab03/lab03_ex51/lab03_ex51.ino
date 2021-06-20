/*
highest prescalar 1:1024
counter clock time = 1024/16 = 64
timer counter overflows 256*64 = 16384 microseconds
                              = 16.384 ms

To generate a time delay of 100ms = 100ms/16.384ms 
                                  = 6.01
Therefore the counter TCNT0 has to overflow 7 times to generate a time delay of 100ms

*/



#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char count;

int main (void)

{

	DDRB |= (1<<5); //PB6 as output

	TCNT0 = 0; //load timer counter register
	count = 0; // initialize counter value to 0
  
	TCCR0A =0x00; //set the timer0 under normal mode
	TCCR0B =0x05; //set the timer0 to 1:1024 prescalar 

	TIMSK0 = (1<<TOIE0);//Set Timer OverFlow Interrupt TOIE0 bit of TIMSK register

	sei();//enable globle interrupt

while(1)  {}

}

 

ISR (TIMER0_OVF_vect){
  if (count == 7){//if timer0 overflows 7 times, then toggle the LED
 
     PORTB ^= (1<<5);
     count=0; //reset the timer0
  }
  
  else
     count++;// increment the counter value
 
}