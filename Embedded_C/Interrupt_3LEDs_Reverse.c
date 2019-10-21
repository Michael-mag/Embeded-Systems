#include<avr/io.h>
#include<util/delay.h>
#include<avr/interrupt.h>
#define F_CPU 16000000UL


int main(void){
//Deal with interrupt pins
  DDRD &=!(1<<PD3);//Clear PD3 =INT1
  PORTD |= (1<<PD3);//set PD3 high

//Set edges
  EICRA |= (1<<ISC10);//any logic change generates an interrupt request
  EIMSK |= (1<<INT1); //Turn INT1 on
  sei();//turn interrupt on
//Deal with output pints
  DDRB |=(1<<PB0);//SET PB0 = pin 8 as output on UNO
  DDRB |=(1<<PB4);//SET PB0 = pin 12 as output on UNO
  DDRB |=(1<<PB5);//SET PB0 = pin 13 as output on UNO

  //PORTB |= (1<<PB0);
  //Uncomment above if you want to start with the LED on
while(true){
  PORTB |=(1<<PB0);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB0);//Turn off LED
  _delay_ms(1000);
  //NOW YELLOW
  PORTB |=(1<<PB4);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB4);//Turn off LED
  _delay_ms(1000);
  //NOW RED
  PORTB |=(1<<PB5);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB5);//Turn off LED
  _delay_ms(1000);
}

}

//REVERSE THE ORDER
ISR(INT1_vect){
 //NOW RED
  PORTB |=(1<<PB5);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB5);//Turn off LED
  _delay_ms(1000);

  //NOW YELLOW
  PORTB |=(1<<PB4);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB4);//Turn off LED
  _delay_ms(1000);


   PORTB |=(1<<PB0);//Turn PORTB0 on.
  _delay_ms(1000); //delay for 3 seconds
  PORTB &=!(1<<PB0);//Turn off LED
  _delay_ms(1000);
}
