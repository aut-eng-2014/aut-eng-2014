#include <kovax.h>

void init_7segment(){
	DDRA |= 0b00101111;  
	DDRB |= 0b01111111;  
}

void displayChar(char nr, char value){

	PORTA &= 0B11110000;
	PORTB |= 0B01111111;

	switch(value){
     case 0: PORTB &= 0B11000000; break;
     case 1: PORTB &= 0B11111001; break;
     case 2: PORTB &= 0B10100100; break;
     case 3: PORTB &= 0B10110000; break;
     case 4: PORTB &= 0B10011001; break; 
     case 5: PORTB &= 0B10010010; break;
     case 6: PORTB &= 0B10000010; break;
     case 7: PORTB &= 0B11111000; break;
     case 8: PORTB &= 0B10000000; break;
     case 9: PORTB &= 0B10010000; break;
	 default: PORTB &= 0B10000110; break;
	}
	
	nr %= 4;
 	switch(nr){ 
		case 1: PORTA |= 0B00001000; break;
		case 2: PORTA |= 0B00000100; break;
		case 3: PORTA |= 0B00000010; break;
  		case 4: PORTA |= 0B00000001; break;
	}
}

void set7segment(int a){
	if(a < 0){
		int i;
		for (i = 1; i <= 4; i++){
			displayChar(i,23);
		}
	}
	displayChar(1,a % 10);
	displayChar(2,(a / 10) % 10);
	displayChar(3,(a / 100) % 10);
	displayChar(4,a / 1000);
}

void init_Button(){
	DDRB &= ~(1 << 7);
	PORTB |= (1 << 7);
}

bool buttonIsPressed(){
	if(!(PINB & (1 << 7))){
		return true;
	}
	else{ 
		return false;
	}
}

bool init_Lamp(){
	DDRA |= (1 << 5);
}

void shineLamp(bool shine){
	if (shine){
		PORTA |= (1 << 5);
	}
	else{
		PORTA &= ~(1 << 5);
	}
}

void sleep(char s){
	_delay_ms(s);
}

void reset_Timer(){
	TCNT0 = 0; // The counter will be set to 0
}

void init_Timer(){
	TCCR0  = 0B00000011;
	reset_Timer();
}

void init_Timer_ms(){
	init_Timer();
	OCR0 = 125;
	TIMSK |= (1 << 2); //activeaza intreruperea de Output Compare Match (comparare la iesire)
}

int getTimerCounter(){
	return TCNT0;
}

void init_adc(){
	ADMUX |= 0B01000000;
	ADCSRA |= 0B10000111;
}

int adc(char a){
	ADMUX &= 0B11100000;
	ADMUX |= a;
	ADCSRA |= (1 << 6);
	while (ADCSRA & (1 << 6));
	return ADC;
}

