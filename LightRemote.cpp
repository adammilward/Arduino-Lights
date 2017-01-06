/*
 * LightsRemote.cpp
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */

#include "LightRemote.h"
#include "Light.h"

	// the buttons
	unsigned long const IR_HOLD = 0xFFFFFF;

	unsigned long const IR_UP = 0xFFA05F; //
	unsigned long const IR_DOWN = 0xFF20DF; //
	unsigned long const IR_ON; //
	unsigned long const IR_OFF = 0xFFE01F; //

	unsigned long const IR_RED = 0xFF906F; //
	unsigned long const IR_GREEN = 0xFF10EF; //
	unsigned long const IR_BLUE = 0xFF50AF; //
	unsigned long const IR_WHITE = 0xFFD02F; //

	unsigned long const IR_ORANGE = 0xFFB04F; //
	unsigned long const IR_YELLOW = 0xFF30CF; //
	unsigned long const IR_CYAN = 0xFF708F; //
	unsigned long const IR_PURPLE = 0xFFF00F; //

	unsigned long const IR_JUMP3 = 0xFFA857; //
	unsigned long const IR_JUMP7 = 0xFF28D7; //
	unsigned long const IR_FADE3 = 0xFF6897; //
	unsigned long const IR_FADE4 = 0xFFE817; //

	unsigned long const IR_M1 = 0xFF9867; //
	unsigned long const IR_M2 = 0xFF18E7; //
	unsigned long const IR_M3 = 0xFF58A7; //
	unsigned long const IR_M4 = 0xFFD827; //


//LightRemote::lightMode mode = WHITE; // set initial remote mode to white


LightRemote::lightMode lMode = LightRemote::FADE;



LightRemote::LightRemote(){

}

//void LightRemote::timer(){
//	delayCount += 1;      // increment the counter for this interupt
//
//	switch (delayCount) {
//	case 1:
//		Red.slide(0.0050);
//		break;
//	case 2:
//		Green.slide(0.0053);
//		break;
//	case 3:
//		Blue.slide(0.0055);
//		break;
//	default:
//		delayCount = 0;
//		break;
//		//}
//	}
//}

void LightRemote::decode(unsigned long value) {


	switch (value) {
	case IR_UP:
		break;
	case IR_DOWN:
		break;
	case IR_OFF:
		Blue.base = 1;

		Red.set(true, -1);
		Green.set(-1);
		Blue.set(-1);
		break;
	case IR_RED:
		Red.shift(1);
		break;
	case IR_GREEN:
		Green.shift(1);
		break;
	case IR_BLUE:
		Blue.shift(1);
		break;
	case IR_WHITE:
		Red.shift(1);
		Green.shift(1);
		Blue.shift(1);
		break;
	case IR_ORANGE:
		Red.shift(-1);
		break;
	case IR_YELLOW:
		Green.shift(-1);
		break;
	case IR_CYAN:
		Blue.shift(-1);
		break;
	case IR_PURPLE:
		Red.shift(1);
		Green.shift(1);
		Blue.shift(1);
		break;
	case IR_JUMP3:

		break;
	case IR_JUMP7:

		break;
	case IR_FADE3:

		break;
	case IR_FADE4:
		lMode = FADE;
		Light::setMode(Light::LIN);
		break;
	case IR_M1:
		lMode = FADE;
		Light::setMode(Light::SIN);
		break;
	case IR_M2:
		lMode = FADE;
		Light::setMode(Light::EXP);
		break;
	case IR_M3:
		lMode = FADE;
		Light::setMode(Light::EXPSIN);
		break;
	case IR_M4:
		break;
	default:
		break;   // display it on serial monitor in hexadecimal
	}

}

void LightRemote::receive(unsigned long value,LightStruct LightSt) {

	static unsigned long lastValue;

	if (value != IR_HOLD) {
		lastValue = value;
		decode(value);
	} else {
		decode(value);
	}
}

void LightRemote::print(){
		Serial.print(Red.power);
		Serial.print("    ");
		Serial.print(Red.base * 100);
		Serial.print("    ");
		Serial.print(Green.power);
		Serial.print("    ");
		Serial.print(Green.base * 100);
		Serial.print("     ");
		Serial.print(Blue.power);
		Serial.print("     ");
		Serial.print(Blue.base * 100);
		Serial.println(" ");
}
