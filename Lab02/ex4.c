#include <avr/io.h>
#include <avr/interrupt.h>
#include<util/delay.h>

#define BLINK_DELAY_MS 100

unsigned char count = 0;// initialized global variable for count

int main(){

  DDRD &= ~(1<<2);// set PD2 as input (INT0) External interrupt
  DDRD &= ~(1<<3);// set PD3 as input (INT1)
   // set PD0 to PD7 as output
  DDRB |= 0x3F;
  
  EICRA |= (1<<ISC01);//set for rising edge detection INT0
  EICRA |= (1<<ISC00);
  
  
  EICRA |= (1<<ISC11);//set for rising edge detection for INT1
  EICRA |= (1<<ISC10);
  
  sei();//enable interrupts globaly
  
  EIMSK |= (1<<INT0);//(for switch A)enable external interrrupt for INT0
  EIMSK |= (1<<INT1);//(for switch B)enable external interrrupt for INT1
  
  while(1){
  
  }
  return 0;

}

ISR(INT0_vect){
  
  PORTB = PORTB & ~(1<<count);// set the LED to low
  
  //_delay_ms(BLINK_DELAY_MS);// set delay of 1 second to press the button
  
  count ++; // increment the count to set the next LED's value
  
  //pattern is reset with the seventh press 
  if(count==7){
    PORTB = 0b11000000 & count;// reset
    count=0; //can use to chnge the given pattern 
  }
}

ISR(INT1_vect){
  
  PORTB = PORTB | (1<<count);// set the LED to high
  //_delay_ms(BLINK_DELAY_MS);
  count ++;
  if(count==7){
    PORTB = 0b11000000 & count;//reset
    count=0;
  }
}