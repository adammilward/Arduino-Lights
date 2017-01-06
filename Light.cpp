/*
 * Light.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */


#include "Light.h"
#include "arduino.h"



//setLimit setLim = LOW;  // declare the enum for setting LED brightness

const float Light::DEF_GAIN = 0.2;     // default gain for use with Shift()
static Light::fadeMode fMode = Light::SIN;

Light::Light(int inPin){   // Constructor
	pin = inPin;            // sets the pin
}

//  change change power by a given gain or default
void Light::shift(int op, float gain) {
	base += op * gain;
	set();
}

//  called after a shift is made to the base, or directly to set brightness
void Light::set(bool flash, int inBase) {

	if (inBase > -2) { // default is -2 and nothing hapens
		base = inBase;
	}

	float exponant;

	if (base < 0) {
		base = 0;
		if (flash == true) {
			analogWrite(pin, (64)); //flash to eighth brightness
			delay(20);              // delay for flash
		}
		Serial.println("LOW");
		digitalWrite(pin, LOW);         //Set digital high
	} else if (base > 1) {
		base = 1;
		if (flash == true) {
			analogWrite(pin, (128));    //flash to half brightness
			delay(20);                  // delay for flash
		}
		Serial.println("HIGH");
		digitalWrite(pin, HIGH);           //Set digital high
	} else {
		exponant = 7.994353437 * base;
		power = int(pow(2, exponant));
		analogWrite(pin, (power));
	}
}

// used like a combination of shift + set, for fading lights
void Light::slide(float gain) {

	base = base + (shiftOp * gain);	    // update base

	// switch direction if required and return value between 1 and 255
	if (base >= 1) {
		shiftOp = -1;	        // apply direction change
		base = 1;		        // set base to max
		power = 255;	        // set power to maximum
	} else if (base <= 0) {
		shiftOp = 1;
		base = 0;
		power = 1;	        // set power to minimum
	} else {
		calcPow();	            // calculate led power 1 to 255
	}
	analogWrite(pin, (power));
}

// for fading lights, called by Slide()
void Light::calcPow() {

	float temp; // declare the temporary foloat for calculations

	switch (fMode) {
	case Light::LIN:
		power = base * 254 + 1;	        // calculate led power 1 to 255
		break;
	case Light::SIN:
		temp = 1 - base;                 // invert the base ( 0 -> 1, 1 -> 0)
		temp = cos(temp * 3.14159265);	// calculate the sine wave -1 to +1
		temp = temp + 1;                   // temp is sinusoidal from 0 to 2
		power = temp * 127 + 1;	            // modify led power 1 to 255
		break;
	case Light::EXP:
		temp = 7.994353437 * base;	    // set exponant 0 to 8ish
		power = pow(2, temp);	    // power = 2^temp
		break;
	case Light::EXPSIN:
		temp = 1 - base;               // invert the base ( 0 -> 1, 1 -> 0)
		temp = cos(temp * 3.14159265) + 1; 	// calculate the sine wave 0 to 2
		temp = temp * 7.994353437 / 2;      // calculate exponant ( 0 to 8ish)
		power = int(pow(2, temp));	// power = 2^temp
		break;
	default:

		break;
	}
}

void Light::setMode(fadeMode inMode){
	fMode = inMode;
}

/*
 Serial.print("gain   ");
 Serial.print(gain);
 Serial.print("expon   ");
 Serial.print(Red.exponant);
 Serial.print("op   ");
 Serial.println(op);
 */
//delay(20);
