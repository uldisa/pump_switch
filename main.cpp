#include <Arduino.h>
#include <math.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <PCD8544.h>
//#include <HardwareSerial.h>
#include <string.h>
#include "BIGSERIF.h"
#include "font5x8.h"

// SPI portb for LCD control.
// PINS 8,9,10,11,12,13
#define TEMP_PRECISION 11
#define TEMP_CONVERSION_DELAY 750 / (1 << (12 - TEMP_PRECISION))
PCD8544 LCD(9,10,8);
OneWire W1(7);
OneWire W2(6);
OneWire W3(5);
OneWire W4(A0);
DallasTemperature T1(&W1);
DallasTemperature T2(&W2);
DallasTemperature T3(&W3);
DallasTemperature T4(&W4);
float t1,t2,t3,t4;

#define DL_Timer1hz 15625	//Hz 16Mhz with 1024 prescale.
#define DL_period  1000		//Data Loggin (attempt) period in milliseconds
//#define DL_period  TEMP_CONVERSION_DELAY+10		//Data Loggin (attempt) period in milliseconds
//volatile unsigned int DL_periodOverflows = 0;
volatile unsigned int TS_conversionOverflows = 0;
/*void DL_startPeriod(void)
{
	//Calculate params for next wakup
	unsigned long periodTicks = (unsigned long)DL_Timer1hz * (unsigned int)DL_period / 1024 + OCR2A;	//Equal time intervals
	cli();
	OCR2A = periodTicks & 0xFF;
	DL_periodOverflows = periodTicks >> 8;
	if (DL_periodOverflows > 0) {
		// Disable OCR2A interrupt if must wait for overflows
		TIMSK2 &= ~0b00000010;
	} else {
		TIFR2 |= 0b00000010;
		TIMSK2 |= 0b00000010;
	}
	sei();
}*/
void TS_waitConversion(int conversionDelay)
{
	//Calculate params for nested wakup
	cli();
	unsigned long conversionTicks = (unsigned long)DL_Timer1hz * conversionDelay / 1000 + TCNT2;	// Timer starts relative to current time.
	OCR2B = conversionTicks & 0xFF;
	TS_conversionOverflows = conversionTicks >> 8;
	if (TS_conversionOverflows > 0) {
		// Disable OCR2A interrupt if must wait for overflows
		TIMSK2 &= ~0b00000100;
	} else {
		TIFR2 |= 0b00000100;
		TIMSK2 |= 0b00000100;
	}
	sei();
}
ISR(TIMER2_COMPA_vect)
{
	//DL_startPeriod();
	if (TIMSK2 & 0b00000100 || TS_conversionOverflows > 0) {
		// If Nested timer not done, skip the beat.
		return;
	}
 	T1.requestTemperatures();
  	T2.requestTemperatures();
  	T3.requestTemperatures();
  	T4.requestTemperatures();
	TS_waitConversion(TEMP_CONVERSION_DELAY);
}

ISR(TIMER2_COMPB_vect)
{
	cli();
	TIMSK2 &= ~0b00000100;	//Do it once
	sei();
	// Loop through each device, print out temperature data
	t1=T1.getTempCByIndex(0);
	t2=T2.getTempCByIndex(0);
	t3=T3.getTempCByIndex(0);
	t4=T4.getTempCByIndex(0);
 	T1.requestTemperatures();
  	T2.requestTemperatures();
  	T3.requestTemperatures();
  	T4.requestTemperatures();
	TS_waitConversion(TEMP_CONVERSION_DELAY);
}

ISR(TIMER2_OVF_vect)
{
/*	if (DL_periodOverflows) {
		DL_periodOverflows--;
		if (!DL_periodOverflows) {
			// clean compare flag to prevent immediate interrupt
			TIFR2 |= 0b00000010;
			// enable OCR2A interrupt if must wait for overflows
			TIMSK2 |= 0b00000010;
		}
	}
*/	if (TS_conversionOverflows) {
		TS_conversionOverflows--;
		if (!TS_conversionOverflows) {
			// clean compare flag to prevent immediate interrupt
			TIFR2 |= 0b00000100;
			// enable OCR2B interrupt if must wait for overflows
			TIMSK2 |= 0b00000100;
		}
	}
//	digitalWrite(HARTBEAT_LED,!digitalRead(HARTBEAT_LED));

}
//Revrite to Timer 0
/*unsigned long _tAC_time; // Used to track end note with timer when playing note in the background.

    #define PWMT1AMASK DDB1
    #define PWMT1BMASK DDB2
    #define PWMT1DREG DDRB
    #define PWMT1PORT PORTB
    
void noToneAC() {
  TIMSK1 &= ~_BV(OCIE1A);     // Remove the timer interrupt.
  TCCR1B  = _BV(CS11);        // Default clock prescaler of 8.
  TCCR1A  = _BV(WGM10);       // Set to defaults so PWM can work like normal (PWM, phase corrected, 8bit).
  PWMT1PORT &= ~_BV(PWMT1AMASK); // Set timer 1 PWM pins to LOW.
}

void toneAC(unsigned long frequency, unsigned long length) {
  if (frequency == 0) { noToneAC(); return; }                // If frequency is 0, turn off sound and return.
  
  PWMT1DREG |= _BV(PWMT1AMASK); // Set timer 1 PWM pins to OUTPUT (because analogWrite does it too).

  uint8_t prescaler = _BV(CS10);                 // Try using prescaler 1 first.
  unsigned long top = F_CPU / frequency / 2 - 1; // Calculate the top.
  if (top > 65535) {                             // If not in the range for prescaler 1, use prescaler 256 (122 Hz and lower @ 16 MHz).
    prescaler = _BV(CS12);                       // Set the 256 prescaler bit.
    top = top / 256 - 1;                         // Calculate the top using prescaler 256.
  }
  unsigned int duty = top >> 1;                      // 50% duty cycle (loudest and highest quality).

  if (length > 0) {                // Background tone playing, returns control to your sketch.
    _tAC_time = millis() + length; // Set when the note should end.
    TIMSK1 |= _BV(OCIE1A);         // Activate the timer interrupt.
  }

  ICR1   = top;                         // Set the top.
  if (TCNT1 > top) TCNT1 = top;         // Counter over the top, put within range.
  TCCR1B = _BV(WGM13)  | prescaler;     // Set PWM, phase and frequency corrected (top=ICR1) and prescaler.
  OCR1A  = OCR1B = duty;                // Set the duty cycle (volume).
  TCCR1A = _BV(COM1A1) ; // Inverted/non-inverted mode (AC).

}

ISR(TIMER1_COMPA_vect) { // Timer interrupt vector.
  if (millis() >= _tAC_time) noToneAC(); // Check to see if it's time for the note to end.
}
*/
void requestEvent(void) {
	// Send all data
//	Wire.write((const uint8_t *)TS.tempRaw,sizeof(uint16_t)*TS.count);
}
int main(void) {
	cli();
	SPCR=0;//disable SPI
	TCCR2A = 0b00000000;	//Normal Timer2 mode.
	TCCR2B = 0b00000111;	//Prescale 16Mhz/1024
	TIMSK2 = 0b00000001;	//Enable overflow interrupt
	sei();			//Enable interrupts
	pinMode(2,OUTPUT);
	pinMode(4,OUTPUT);
	digitalWrite(2,HIGH); //Relay off
	digitalWrite(4,HIGH); //Relay off
	init();
	T1.begin();
	T1.setWaitForConversion(false);
	T1.setResolution(TEMP_PRECISION);
	T2.begin();
	T2.setResolution(TEMP_PRECISION);
	T2.setWaitForConversion(false);
	T3.begin();
	T3.setResolution(TEMP_PRECISION);
	T3.setWaitForConversion(false);
	T4.begin();
	T4.setResolution(TEMP_PRECISION);
	T4.setWaitForConversion(false);
	LCD.begin();
	long start=millis();
	LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
	TS_waitConversion(TEMP_CONVERSION_DELAY);
//	DL_startPeriod();
	while (1) {
	LCD.Clear();
	LCD.GoTo(0,0);
	LCD.println(t1);
	LCD.println(t2);
	LCD.println(t3);
	LCD.println(t4);
	LCD.println(analogRead(A3));
     // 	toneAC(analogRead(A3),  10);
//	LCD.print("TPS ");
//	LCD.print((float)1000000.0/(millis()-start),4);
	LCD.Render();
	//digitalWrite(3,!(millis()&0x100));
	//digitalWrite(4,!(millis()&0x100));
	delay(100);
	}
}
