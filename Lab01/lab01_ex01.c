#include <avr/io.h>
#include<util/delay.h>

#define BLINK_DELAY_MS 1000

int main(void){

DDRB = 0x0F;

while(1){
  PORTB = 15;
  _delay_ms(BLINK_DELAY_MS);
  
  PORTB = 0;
  _delay_ms(BLINK_DELAY_MS);

}
return 0;
}