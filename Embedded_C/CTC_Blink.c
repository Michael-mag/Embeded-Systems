//CTC MODE

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL

int main(){

  //set the output
  DDRB |= (1<<PB0);//Set PBO = Pin 8 on UNO as output

  //set the starting value
  TCNT1 = 0;

  //set the compare value i.e the final value
  OCR1A = 15624;//count from 0-15624 to get 1 second delay

  //Setup the timer
  TCCR1B |= (1<<WGM12);//Set timer mode to CTC on Clear Timer Compare Match

  TCCR1B |= (1<<CS12) | (1<<CS10); //SET Prescaler to 1024 and start the timer

  TIMSK1 |= (1<<OCIE1A);//Set interrupt on compare match

  //enable interrupts
  sei();

  while(1){}

}
ISR(TIMER1_COMPA_vect){
    PORTB ^=(1<<PORTB0);//toggle port b on
    TCNT1 = 0;//counter starts here to obtain 1 second delay
}
