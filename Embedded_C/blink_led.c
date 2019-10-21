/*
BLINK 3 LEDS attached to the same port

*/


#include<avr/io.h>
#define F_CPU 16000000UL //clock frequancy
#include<util/delay.h>

int main(){

  //set the desired port as output.
  DDRB |=(1<<PB0); //Set PB0 as output...PB0 = pin8 on UNO
  DDRB |=(1<<PB4); //Set PB4 as output...PB4 = pin12 on UNO
  DDRD |=(1<<PB1);//SET PIN 9 AS OUTPUT
  while(true){
    PORTB |=(1<<PB0);//Turn PORTB0 on.
    _delay_ms(3000); //delay for 3 seconds
    PORTB &=!(1<<PB0);//Turn off LED
    _delay_ms(1000);
    //_delay_ms(2000);
    PORTB |=(1<<PB4);//Turn on LED attached to pin 12
     _delay_ms(3000); //delay for 3 seconds
    PORTB &=!(1<<PB4);//Turn off LED attached to pin 12
    _delay_ms(1000);
    PORTB |=(1<<PB1);//Turn on LED attached to pin 9
     _delay_ms(3000); //delay for 3 seconds
    PORTB &=!(1<<PB1);//Turn off LED attached to pin 9
    _delay_ms(1000);
  }
}
