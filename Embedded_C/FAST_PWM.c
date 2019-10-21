

//FAST PWM

#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>
#include <avr/interrupt.h>
int main (void){
  cli(); // clear all interrupts
  DDRD = 0xFF; // Output to DDRD
  //Setting the corresponding registers for ADC conversion
  ADMUX |= (1<<REFS0) | (1<<ADLAR);
  ADCSRA |= (1<<ADEN) | (1<<ADATE) |(1<<ADIE) | (1<<ADPS0) |(1<<ADPS1);// | (1<<ADPS2);
  ADCSRA |= (1<<ADSC); // start the AD conversion
  sei(); // set global interrupt
  while (1){
  }
}
// Interrupt service routine for the ADC completion
ISR (ADC_vect) {
PORTD = ADCH; // Set output on PORTD equal to values in ADCH register
ADCSRA |= (1<<ADSC); //Set ADSC in ADCSRA (0x7A) to start another ADC conversion
}
