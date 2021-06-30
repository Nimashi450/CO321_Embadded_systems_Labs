#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>


int main(void)
{
  
	DDRD = DDRD | (1<<6);// set the pin 6 of port d as output
    OCR0A |= 127;// obtained the value of OCR0A reg for 50% dutyCycle
     
      /*
    frequency can be changed by changing the generated freqency
    that can be changed by using different pre scalars
  
  
    pre scaler 1:8    --> 7812.5Hz
    pre scaler 1:64   --> 976.56Hz
    pre scaler 1:256  --> 244.14Hz
    pre scaler 1:1024 --> 61.03Hz
    
    CS00 , CS01, CS00\2 values for different pre scalars
    Decimal value corresponding to each scalar
    
    pre scaler 1:8    --> 2
    pre scaler 1:64   --> 3
    pre scaler 1:256  --> 4
    pre scaler 1:1024 --> 5
    */
    while(1){
    	unsigned int i = 5; //initialize the i value
  
    	while(i>1){
      	
        	TCCR0B = i;//declare the current prescalar value for the 
      
        	// set none-inverting mode
            TCCR0A |= (1 << COM0A1);
            TCCR0A |= (0 << COM0A0);  

            // set fast PWM Mode
            TCCR0A |= ((1 << WGM01) | (1 << WGM00));
	        TCCR0B |= (0 << WGM02) ;
          
            //set a delay of 1s
        	_delay_ms(1000);
    		i--;// decrement the i value
      
  		}
    }
    
    
}
