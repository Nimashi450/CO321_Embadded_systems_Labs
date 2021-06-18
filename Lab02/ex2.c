#include <avr/io.h>
#include <avr/interrupt.h>


int main(){

  DDRB &= ~(1<<2);// set PD2 as input (INT0)
  DDRB |= (1<<0); // set PB0 as output
  
  EICRA |= (1<<ISC01);//set for falling edge detection
  EICRA &= ~(1<<ISC00);
  
  sei();//enable interrupts globaly
  
  EIMSK |= (1<<INT0);//enable the hardware interrrupt
  
  while(1){
  
  }
  return 0;

}

ISR(INT0_vect){
  
  PORTB = PORTB ^ (1<<0);// toggle the value in PB0 of port B

}