
/*
	CALCULATIONS
    
desired baud rate = 9600

desired baud rate = Fosc / 16(x+1)

x = (fosc/16*baud)  - 1

x = 103.1666

X is the value to be loaded to UBRR register.

*/

#include <avr/io.h>
#include <util/delay.h>

#define UBBRVAL 103


void usart_init(){  
  
  // override normal port operation
  UCSR0B |= (1<<RXEN0)|(1<<TXEN0); 
  
  UCSR0C &= ~((1<<UMSEL01)|(1<<UMSEL00)); // asynchronous mode
  UCSR0C &= ~((1<<UPM01)|(1<<UPM00)); // no parity
  
  UCSR0C &= ~(1<<USBS0); // one stop bit
  
  // 8 bit data frame
  UCSR0C &= ~(1<<UCSZ02);
  UCSR0C |= ((1<<UCSZ01)|(1<<UCSZ00));
  
  // setting baud rate 
  UBRR0H = (unsigned char)(UBBRVAL>>8); // set higher bits
  UBRR0L = (unsigned char)(UBBRVAL); // set lower bits
	 
}

void usart_send(char character) {
  
  // checking if register is ready to send data
  while((UCSR0A & (1<<UDRE0)) == 0); 
  UDR0 = character; // write to buffer
}


char usart_receive() { 
  
  // checking if register has data
  while((UCSR0A & (1<<RXC0)) == 0); 
  return UDR0; // return data 
}



// function for ceaser cipher
char ceaser(char character) {
    
    if(character >= 'a' && character <= 'z'){
        if(character + 3 > 'z'){
            character = character + 3 - 'z'+'a'-1;
        } 
        else {
            character = character + 3;
        }

    } 
    else if(character >= 'A' && character <= 'Z'){
        if(character + 3 > 'Z'){
            character = character + 3 - 'Z'+'A'-1;
        } 
        else {
            character = character + 3;
        }

    }
    return character;
}

int main() {
  DDRB |= (1<<0);  
  
  // initializing USART
  usart_init();
  
  char s;  // to hold the character
  char cip; // ciphered character
  
  while(s != '\r'){ // check if CR
    
  	s = usart_receive(); // receive character
    
    cip = ceaser(s); // apply ceaser cipher
    
    usart_send(cip); // send character
  } 
  
 
  
  return 0;
}


