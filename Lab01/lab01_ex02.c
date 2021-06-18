#include <avr/io.h>
#include<util/delay.h>

#define BLINK_DELAY_MS 200

int main(void){

DDRB = 0xF;

while(1){
  PORTB = 1;
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
  PORTB = 2;
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
 
  PORTB = PORTB | (1<<2);
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
  
  PORTB = PORTB | (1<<3);
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
  
  PORTB = PORTB | (1<<2);
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
  
  PORTB = 2;
  _delay_ms(BLINK_DELAY_MS);
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);
  
  
}
return 0;
}