#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

int main(void)
{

	DDRD = DDRD | (1<<6);// set the pin 6 of port d as output
  
    TCCR0B |= (1<<CS01)|(1<<CS00) ; // 1/64 prescalar
    TCCR0B &=  ~(1<<CS02); 
  
    TCCR0A |= (1<<COM0A1)|(1<<WGM00)|(1<<WGM01);//non inverting mode of  fast PWM mode
      
    
    while(1){
        //increase the intensity of th LED 
        for(int duty = 0 ; duty<255 ;duty++){
      		OCR0A = duty ;
            _delay_ms(10);
        }
        //decrease the intensity
        for(int duty = 255; duty>0 ;duty--){
      		OCR0A = duty ;
            _delay_ms(10);
      
        }
        
    }  
    
}


