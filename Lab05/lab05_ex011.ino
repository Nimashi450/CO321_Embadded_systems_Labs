#include <avr/io.h>

int main(){

	DDRC = DDRC & ~(1<<2); // pin 2 of port c (ADC1) as input
    DDRD = 0xFF; // port d as output
      
    ADCSR = (1<<ADEN); // enable the ADC
    ADCSR = (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2); //clock freaquency with 128 division factor
    
    ADMUX = (1<<REFS1) | (1<<MUX1); // use AVCC as voltage referance
                                    // selsct MUX 4:0 according to the ADC channel input
  
    
    
    

}