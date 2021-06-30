
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

/*BAUD = 9600
FREQUENCY = 16MHz
UBRR = 16MHz/(16*BAUD-1)
	 = 103
*/



void usart_init(){
  	//enable usart transmitter and the reciever
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
  	//set asynchronus mode 
	UCSR0C &= ~((1 << UMSEL00)|(1 << UMSEL00));
  	//parity diabled
    UCSR0C &= ~((1 << UPM00) | (1 << UPM01));
  	//bit size of 8 bits
    UCSR0C &= ~(1 << UCSZ02);
  	UCSR0C |=  (1 << UCSZ00) | (1 << UCSZ01);
    //one stop bit
    UCSR0C &= ~(1 << USBS0);
  	//load the value to the ubrr register
	UBRR0L = 103;		
	UBRR0H = (103 >> 8);
}

unsigned char usart_recieve(){
  	// Wait till data is received 
	while ((UCSR0A & (1 << RXC0)) == 0);
	return(UDR0);			//Return the byte
}

void usart_send(char ch){
	while (! (UCSR0A & (1<<UDRE0)));	// Wait for empty transmit buffer
	UDR0 = ch ;			//transmit each byte of character
}

//function to send each character of a string
void usart_SendString(char *str){
	unsigned char j=0;
	
	while (str[j]!=0){
		usart_send(str[j]);	
		j++;
	}
}

int main(){
	char c;
	usart_init();
	
	usart_SendString("\n E/16/364 - Tharushi Suwaris \n E/16/039 - Nimashi Uthpala \n E/16/087 - Sachini Dissanayaka ");	
		
}