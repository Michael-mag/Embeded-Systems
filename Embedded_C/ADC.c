
//ADC

#include <avr/io.h>
#define F_CPU 1600000UL
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void){

  DDRB = 0xFF;
//set voltage reference = 5V, Choose an ADC input channel to be adc1
ADMUX |= (1<<REFS0) | (1<<ADLAR);

//Setup the conversion
ADCSRA |= (1<<ADEN) | (1<<ADATE) | (1<<ADIE) | (1<<ADPS0)|(1<<ADPS1);
ADCSRA |=(1<<ADSC);
  sei();




  while(1){

  }
}

ISR(ADC_vect){
  PORTB  = ADCH;
  ADCSRA |= (1<<ADSC);
}
