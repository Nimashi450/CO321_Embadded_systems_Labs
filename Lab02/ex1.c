#include <avr/io.h>
#include<util/delay.h>


int main(void){
  
  DDRD &= ~(1<<7) ; //set bit 7(pin 7) of port D as input
  // set pin 8,9,10,11,12,13 as port B outputs
  DDRB |= 0x3F; 
      
 unsigned char count = 1; // initialized counter value

  
  while(1){
    
    if(PIND & (1<<7)){
    PORTB = count; // set leds to high according to count value
     count++; // increment the count 
 
    while(PIND & (1<<7)){
        //empty loop to run until the push button is released
    }
   }
    
 }
 return 0;
}