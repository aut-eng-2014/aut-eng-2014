#ifndef KOVAX_H
#define KOVAX_H

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

/*
	ADC colocviu library.
	
	BASIC-TO-KNOWS:
	
	-DDR(Q): 
	if 0 then input
	if 1 then output

	-PORT(Q): 
	Used to output value, or for pull-resistors
	
	-PIN(Q):
	Contains the input value
	
	Operations:
	Q |= (1 << q) : sets the q-th bit to 1
	
	Q &= ~(1 << q) : sets the q-th bit to 0
	
	if ( Q & (1 << q) ) : if q-th bit is 1 then true
	if ( !(Q & (1 << q)) ) : if q-th bit is 0 then true
	
*/

typedef enum{
	false,
	true
} bool;

/*
	Check if the button is pressed or not:
	if(!(PINQ & (1 << Q))){             
            if(BP == 0){
                flag *= -1;
                BP = 1;
            }
		}
        else{
			BP = 0;
		}
*/

/*
	Timer:
	
	TCNT0 -> contains the value of the timer
	TCNT0 == 125 -> 1 milisecond
	
	OCR0 = 125 -> makes the counter count slower by 125 times
	
*/

/*
	Interrupts:
	
	DON'T FORGET ABOUT sei();
	
	ISR(TIMER0_COMP_vect){...} -> timer interrupt
*/

/*
	ADC:
	@TODO learn what the heck is happening...
*/

void init_7segment();
void displayChar(char,char);
void set7segment(int);

void init_Button();
bool buttonIsPressed();

void init_Lamp();
void shineLamp(bool);

void sleep(char);

void init_Timer();
void init_Timer_ms();
void reset_Timer();
int getTimerCounter();

void init_adc();
int adc(char);

#endif