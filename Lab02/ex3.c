#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define BLINK_DELAY_MS 100
unsigned char count = 1; //get the counter value as a global variable

int main(){

  DDRD &= ~(1<<2);// set PD2 as input (INT0)
  // set PB0 to PB6 as output
  DDRB |= 0x3F;
  
  EICRA |= (1<<ISC01);//set for falling edge detection
  EICRA &= ~(1<<ISC00);
  
  sei();//enable interrupts globaly
  
  EIMSK |= (1<<INT0);//enable the hardware interrrupt 
  
  while(1){
  
  }
  return 0;

}

ISR(INT0_vect){ 
  
  PORTB = 0b11000000 & count; // (reset)clear first 6 bit of port B
  
  _delay_ms(BLINK_DELAY_MS); // set a delay value to observe the blinking clearly
  
  PORTB = PORTB | count; // set leds to high according to count value
  count++; //increment the counter value
   
   
  
  

}