//NORMAL MODE

#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL

int main(void){

  //Set output pin
  DDRB |= (1<<PB0);//Set PORTB0 = Pin 8 as output on UNO

  //set the timer/counter control register
  TCCR1B |= (1<<CS12) | (1<<CS10);//Prescaler set to 1024
  //CS12 = 1

  //SET THE counter to start at this value to achieve a 1 second delay
  TCNT1 = 49910;


  TIMSK1 |= (1<<TOIE1);
  sei();//enable global interrupt

  while (1) {
    /* code */
  }

}

ISR(TIMER1_OVF_vect){
  PORTB ^=(1<<PORTB0);//toggle port b on
  TCNT1 = 49910;//counter starts here to obtain 1 second delay
}
