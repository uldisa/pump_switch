#include <Arduino.h>
#include <math.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <EEPROM.h>
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

int keymap[][3]{
	//min value, max value, char
	{643-5,643+5,'_'},
	{682-5,682+5,'^'},
	{743-5,743+5,'<'},
	{782-5,782+5,'o'},
	{796-5,796+5,'>'}
};
char last_key;
long key_debounce;
char getkey(int analog) {
	if(analog>796+5){
		return 0;
	}
	for(int i=0;i<5;i++) {
		if(analog>=keymap[i][0] && analog<=keymap[i][1]) {
			if(last_key==keymap[i][2]){
				if(key_debounce<millis()) {
					return (char)keymap[i][2];
				} else {
					return 0;
				}
			}
			last_key=keymap[i][2];
			key_debounce=millis()+10;
			break;
		}
	}
	return 0;	
}
void switch_action(){
// Manage drinkwater pump
//t1 - availabe temperature
//t2 - drinkwater temperature
//t_on - temperature, when pump is always on
//t_delta - minimum temperature difference for pump to switch on 


// Monitor boiler activity
//t3 - output
//t4 - return
//t_off_delta - temperature difference when switch boiler off
//t_off_max - max temp when allowed to switch off

}
//<Initial>-<Temp>-<Drinkwater>-<Boler>

// ID of the settings block
#define CONFIG_VERSION "FTW"

// Tell it where to store your config data in EEPROM
#define CONFIG_START 0 

// Example settings structure
struct StoreStruct {
  // The variables of your settings
  float t_on; //- temperature, when pump is always on
  float t_delta; //- minimum temperature difference for pump to switch on 
// Monitor boiler activity
  float t_off_delta; //- temperature difference when switch boiler off
  float t_off_max; //- max temp when allowed to switch off
  // This is for mere detection if they are your settings
  char version_of_program[4]; // it is the last variable of the struct
  // so when settings are saved, they will only be validated if
  // they are stored completely.
} settings = {
  // The default values
  70.0,
  10.0,
  0.5,
  70.0,
  CONFIG_VERSION
};

void saveConfig() {
  for (unsigned int t=0; t<sizeof(settings); t++)
  { // writes to EEPROM
    EEPROM.update(CONFIG_START + t, *((char*)&settings + t));
    // and verifies the data
  //  if (EEPROM.read(CONFIG_START + t) != *((char*)&settings + t))
  //  {
      // error writing to EEPROM
  //  }
  }
}
void loadConfig() {
  // To make sure there are settings, and they are YOURS!
  // If nothing is found it will use the default settings.
  if (//EEPROM.read(CONFIG_START + sizeof(settings) - 1) == settings.version_of_program[3] // this is '\0'
      EEPROM.read(CONFIG_START + sizeof(settings) - 2) == settings.version_of_program[2] &&
      EEPROM.read(CONFIG_START + sizeof(settings) - 3) == settings.version_of_program[1] &&
      EEPROM.read(CONFIG_START + sizeof(settings) - 4) == settings.version_of_program[0])
  { // reads settings from EEPROM
    for (unsigned int t=0; t<sizeof(settings); t++)
      *((char*)&settings + t) = EEPROM.read(CONFIG_START + t);
  } else {
    // settings aren't valid! will overwrite with default settings
    saveConfig();
  }
}
char STATE;
char EDIT;
char ACTIVE_FIELD;
void input(char FIELD,float value){
	uint8_t cursorX;
	uint8_t cursorY;
	if(ACTIVE_FIELD==FIELD) {
		LCD.print('>');
		if(EDIT) {
			cursorX=LCD.cursorX;
			cursorY=LCD.cursorY;
			LCD.print("\x80\x80\x80\x80\x80");
			LCD.cursorX=cursorX;
			LCD.cursorY=cursorY;
			LCD.setMode(XOR);
		}

	} else {
		LCD.print(' ');
	}
	LCD.println(value);
	LCD.setMode(OVERWRITE);
}
void render(char key) {
	switch(STATE) {
	case 'I':
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.Clear();
		LCD.GoTo(0,0);
		LCD.println("git@githu");
		LCD.println("b.com:uld");
		LCD.println("isa/pump_");
		LCD.println("switch.git");
		LCD.Render();
		switch(key){
			case '>': STATE='T';EDIT=0;ACTIVE_FIELD=0; break;
			case '<': STATE='B';EDIT=0;ACTIVE_FIELD=0; break;
		}
		break;
	case 'T':
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		LCD.Clear();
		LCD.GoTo(0,0);
		LCD.println(t1);
		LCD.println(t2);
		LCD.println(t3);
		LCD.println(t4);
		LCD.println(key);
		LCD.Render();
		switch(key){
			case '>': STATE='D';EDIT=0;ACTIVE_FIELD=0; break;
			case '<': STATE='I';EDIT=0;ACTIVE_FIELD=0; break;
		}
		break;
	case 'D':
		LCD.Clear();
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		//LCD.GoTo(0,0);
		LCD.println("Drinkwater");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		//LCD.GoTo(0,8);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.println("Always on");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		input(0,settings.t_on);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.println("Delta on");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		input(1,settings.t_delta);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.print("t3 ");LCD.println(t3);
		LCD.print("t4 ");LCD.println(t4);
		LCD.Render();
		switch(key){
		case '>': STATE='B';EDIT=0;ACTIVE_FIELD=0; break;
		case '<': STATE='T';EDIT=0;ACTIVE_FIELD=0; break;
		case 'o': 
			  if(EDIT){
				  saveConfig();
				  EDIT=0;
			  } else {
				  EDIT=1;
			  }
			  break;
		case '^': 
			  if(EDIT){
				 if(ACTIVE_FIELD==0) {
					settings.t_on+=0.5;
				 } else {
					settings.t_delta+=0.5;
				 }	 
			  } else {
				 if(ACTIVE_FIELD==0) { ACTIVE_FIELD=1; }
				 else { ACTIVE_FIELD=0; }
			  }
			  break;
		case '_': 
			  if(EDIT){
				 if(ACTIVE_FIELD==0) {
					settings.t_on-=0.5;
				 } else {
					settings.t_delta-=0.5;
				 }	 
			  } else {
				 if(ACTIVE_FIELD==0) { ACTIVE_FIELD=1; }
				 else { ACTIVE_FIELD=0; }
			  }
			  break;
		}
		break;
	case 'B':
		LCD.Clear();
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		//LCD.GoTo(0,0);
		LCD.println("Boiler");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		//LCD.GoTo(0,8);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.println("Max delta off");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		input(0,settings.t_off_delta);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.println("Max temp off");
		LCD.setFont(&BIGSERIF[0][0],8,14,F_UP_DOWN);
		input(1,settings.t_off_max);
		LCD.setFont(&font5x8[0][0],5,8,F_LEFT_RIGHT);
		LCD.print("t1 ");LCD.println(t1);
		LCD.print("t2 ");LCD.println(t2);
		LCD.Render();
		switch(key){
		case '>': STATE='I';EDIT=0; break;
		case '<': STATE='D';EDIT=0; break;
		case 'o': 
			  if(EDIT){
				  saveConfig();
				  EDIT=0;
			  } else {
				  EDIT=1;
			  }
			  break;
		case '^': 
			  if(EDIT){
				 if(ACTIVE_FIELD==0) {
					settings.t_off_delta+=0.5;
				 } else {
					settings.t_off_max+=0.5;
				 }	 
			  } else {
				 if(ACTIVE_FIELD==0) { ACTIVE_FIELD=1; }
				 else { ACTIVE_FIELD=0; }
			  }
			  break;
		case '_': 
			  if(EDIT){
				 if(ACTIVE_FIELD==0) {
					settings.t_off_delta-=0.5;
				 } else {
					settings.t_off_max-=0.5;
				 }	 
			  } else {
				 if(ACTIVE_FIELD==0) { ACTIVE_FIELD=1; }
				 else { ACTIVE_FIELD=0; }
			  }
			  break;
		}
		break;
	}
}
int main(void) {
	cli();
	SPCR=0;//disable SPI
	sei();			//Enable interrupts
	pinMode(2,OUTPUT);
	pinMode(3,OUTPUT);
	pinMode(4,OUTPUT);
	digitalWrite(2,HIGH); //Relay off
	digitalWrite(4,HIGH); //Relay off
	init();
	Serial.begin(9600);
	LCD.begin();
	STATE='I'; //Init	
	loadConfig();
	T1.begin();
	T1.setResolution(TEMP_PRECISION);
	T1.setWaitForConversion(false);
	T2.begin();
	T2.setResolution(TEMP_PRECISION);
	T2.setWaitForConversion(false);
	T3.begin();
	T3.setResolution(TEMP_PRECISION);
	T3.setWaitForConversion(false);
	T4.begin();
	T4.setResolution(TEMP_PRECISION);
	T4.setWaitForConversion(false);
 	T1.requestTemperatures();
  	T2.requestTemperatures();
  	T3.requestTemperatures();
  	T4.requestTemperatures();
	LCD.println("delay");
	LCD.Render();
	delay(TEMP_CONVERSION_DELAY);
	
	LCD.println("go");
	LCD.Render();
	long Last_Temp=millis();
	long Last_Render=millis();
	char key=0;
	char key_prev=0;	
	char key_event=0;	
	while (1) 
	{
		if(millis()-Last_Temp>TEMP_CONVERSION_DELAY)
		{
			long Last_Temp=millis();
			t1=T1.getTempCByIndex(0);
			t2=T2.getTempCByIndex(0);
			t3=T3.getTempCByIndex(0);
			t4=T4.getTempCByIndex(0);
			T1.requestTemperatures();
			T2.requestTemperatures();
			T3.requestTemperatures();
			T4.requestTemperatures();
			// Pump switch calculations go here
		}

		char key=getkey(analogRead(A3));
		if(key && key!=key_prev) {
			key_event=key;
		} else {
			key_event=0;
		}
		key_prev=key;
		if(key_event) {
			tone(3,2000,100);
		}
		if(millis()-Last_Render>100) {
			switch_action();
			render(key_event);
			key_event=0; // Clear event
			if(Serial.available()>0) {
				Serial.print(t1,DEC);
				Serial.print(',');
				Serial.print(t2,DEC);
				Serial.print(',');
				Serial.print(t3,DEC);
				Serial.print(',');
				Serial.print(t4,DEC);
				Serial.print(',');
				Serial.print(digitalRead(8),DEC);
				Serial.print(',');
				Serial.print(digitalRead(7),DEC);
				Serial.print(',');
				Serial.print(digitalRead(6),DEC);
				Serial.print(',');
				Serial.print(digitalRead(5),DEC);
				Serial.print('\n');
				while(Serial.available()>0) {
					Serial.read();
				}
			}
		}
	}
}
