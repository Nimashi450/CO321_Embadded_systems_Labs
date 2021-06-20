
/*
Timer1 for 500ms delay

XTAL = 16 MHz --> 1/16 microseconds
Selected pre Scaler = 1:256
counter clock time = 256/16 = 16
increments = 500000/16 = 31250
Initial counter value = 65536-31250 = 34286

Timer0 for 50ms delay

highest prescalar 1:1024
counter clock time = 1024/16 = 64
timer counter overflows 256*64 = 16384 microseconds
                              = 16.384 ms

To generate a time delay of 50ms = 50ms/16.384ms 
                                  = 3.05
Therefore the counter TCNT0 has to overflow 4 times to generate a time delay of 100ms

*/
#include <avr/io.h>
#include <avr/interrupt.h>


unsigned char count;

int main(void){
 
DDRB |= (1<<5)|(1<<4); // set pin 4,5 of portb as outputs
  
//TIMER0  
TCNT0 = 0x00; // load timer0 counter register
count = 0; //initialize counter value
TCCR0A =0x00;//set timer0 under normal mode
TCCR0B =0x05; // prescalar of 1:1024

TIMSK0 |= (1<<TOIE0);//Set Timer OverFlow Interrupt TOIE0 bit of TIMSK register

//TIMER1  
TCNT1 = 34286;	//load timer counter register with initial value	
TCCR1A = 0x00;	//set timer1 under normal mode with 1:256 prescaler
TCCR1B = 0x04;

TIMSK1 |= (1 << TOIE1); //Set Timer OverFlow Interrupt TOIE1 bit of TIMSK register 
  
sei();// enable global interrupt

while(1)  {}

}


ISR (TIMER0_OVF_vect){
  
if (count ==4 )//if timer0 overflows 4 times, then toggle the LED
{
    PORTB ^= (1<<4);
    count=0;//reset the timer
}
else
    count++; 
}


ISR(TIMER1_OVF_vect){
	PORTB ^= (1 << 5);
  	TCNT1 = 34286;	   //reload the initial vlue
}

