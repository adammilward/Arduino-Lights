/*
 * Light.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */


#include "Light.h"
#include "Arduino.h"

Light::fadeMode Light::fMode = Light::STATIC;

Light::Light(
        int inPin,
		float inGain,
		float inLower,
		float inUpper)
{
    pin = inPin;            // sets the pin
	gain = inGain;
	range = inUpper - inLower; // range between 0 and 1
	lower = inLower * 254 + 1;
	base = inLower;
	set(2);
}

//  change change power by a given gain or default
// int op = -1 or 1
// float shiftGain < 1
void Light::shift(int op, float shiftGain) {
	float setBase = base + op * shiftGain;
	set(setBase, true);
}

//  called after a shift is made to the base, or directly to set brightness
// float setBase <=1 (0 is lowest possible, < 0 is off);
// bool flash, true if you want to flash for extremes (0 or 1)
void Light::set(float setBase, bool flash) {
    // default is -2 and lights are set from what ever the base is set to
	if (setBase > -2) {
		base = setBase;
	}

	float exponant;

	if (setBase < 0) {
		base = -1;
		if (flash == true) {
			analogWrite(pin, (64)); //flash to eighth brightness
			delay(20);              // delay for flash
		}
		power = 0;
		Serial.println("LOW");
		digitalWrite(pin, LOW);         //Set digital high
	} else if (setBase > 1) {
		base = 2;
		if (flash == true) {
			analogWrite(pin, (128));    //flash to half brightness
			delay(20);                  // delay for flash
		}
		power = 255;
		Serial.println("HIGH");
		digitalWrite(pin, HIGH);           //Set digital high
	} else {
	    base = setBase;
		exponant = 8 * base;
		power = int(pow(2, exponant));
		Serial.print("set base to ");
		Serial.println(setBase);
		analogWrite(pin, (power));
	}
	Serial.print("fMode ");
	Serial.print(fMode);
	Serial.print("   base ");
	Serial.print(base);
	Serial.print("   power ");
	Serial.println(power);
}

// change power of light automatically
// using built in data members shiftOp and gain
void Light::slide() {
	base = base + (shiftOp * gain);	    // update base

	// switch direction if required and return value between 1 and 255
	if (base >= 1) {
		shiftOp = -1;	        // apply direction change
		base = 1;		        // set base to max
	} else if (base <= 0) {
		shiftOp = 1;
		base = 0;
	} else {
	}
	calcPow();	            // calculate led power 1 to 255
	analogWrite(pin, (power));
}

// for fading lights, called by Slide()
void Light::calcPow() {
	float temp; // declare the temporary float for calculations
	temp = base;

	switch (fMode) {
	case LIN:
		temp = temp * 254;	        // calculate led power 1 to 255
		break;
	case SIN:
		temp = 1 - temp;                 // invert the base ( 0 -> 1, 1 -> 0)
		temp = cos(temp * 3.14159265);	// calculate the sine wave -1 to +1
		temp = temp + 1;            // temp is sinusoidal from 0 to 2
		temp = temp * 127;	            // modify led power 1 to 255
		break;
	case EXP:
		temp = 7.994353437 * temp;	    // set exponant 0 to 8ish
		temp = pow(2, temp);	    // power = 2^temp
		break;
	case EXPSIN:
		temp = 1 - temp;               // invert the base ( 0 -> 1, 1 -> 0)
		temp = cos(temp * 3.14159265) + 1; 	// calculate the sine wave 0 to 2
		temp = temp * 7.994353437 / 2 ;      // calculate exponant ( 0 to 8ish)
		temp = int(pow(2, temp));	// power = 2^temp
		break;
	default:
		break;
	}

	power = temp * range + lower;

	//Serial.print("fMode   ");
	//Serial.print(fMode);
	//Serial.print(" base   ");
	//Serial.print(base);
	//Serial.print(" power   ");
	//Serial.println(power);

}
// called when resetting fade
// sets the base to half, calculates the power of lights
// and writes to pin
void Light::half() {
    base = 0.5;
    calcPow();
    analogWrite(pin, (power));
    // randomly set the rate and directions

}
void Light::setFadeMode(fadeMode inMode){
	fMode = inMode;
}


