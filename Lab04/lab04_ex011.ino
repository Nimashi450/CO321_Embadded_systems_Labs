/* N = 16MHz/(256*976.56)
     = 64
     
   OCR0 = 0.5*256 - 1
        = 127
*/


#include <avr/io.h>
int main(void)
{

	DDRD = DDRD | (1<<6);// set the pin 6 of port d as output
    OCR0A |= 127;// obtained the value of OCR0A reg as 127
    TCCR0B |= (1<<CS01)|(1<<CS00) ; // 1/64 prescalar
    TCCR0B &=  ~(1<<CS02);
  
    TCCR0A |= (1<<COM0A1)|(1<<WGM00)|(1<<WGM01);//non inverting mode of  fast PWM mode
                       
     
    while(1){
    
    }  
    

}