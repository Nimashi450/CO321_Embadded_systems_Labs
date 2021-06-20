/*
XTAL = 16 MHz --> 1/16 microseconds
Selected pre Scaler = 1:256
counter clock time = 256/16 = 16
increments = 2000/16 = 125
Initial counter value = 256-125 = 131

*/




#include <avr/io.h>

void delay_timer(){

  TCNT0 = 131;/*set the timer controler register to 131 according to 
               suitable prescaler value*/
   
  TCCR0A = 0x00; //set the timer 0 under normal mode 
  TCCR0B = 0x05; //set the timer0 in to 1:256 prescalar to make sure the increments are less than 255 
  
  while((TIFR0&0x01)==0);//wait till timer overflow
  
  	TCCR0A = 0x00;//clear thetimer settings
  	TCCR0B = 0x00;
  
  	TIFR0 = 0x01;//clear the TOV0 flag for the next round
                // inorder to clear we should have to write '1' to the TOV0 flag it is a rule usedddd in AVR chip

}

int main(void)
{
	//toggling proccess
	DDRB = DDRB | (1<<5);// set the pin 5 of portb as output
 	while(1){
  
    	PORTB |= (1<<5);// set the pin 5 of portb to high
    	delay_timer(); // delay
    
    	PORTB &= ~(1<<5);//set the pin 5 of portb to low
    	delay_timer();
  
  }   

}

/* the bulb is countinously light up, because 2ms dealy time is not enough to see
   the blinking of the bulb */