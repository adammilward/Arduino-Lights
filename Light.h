/*
 * Light.h
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */


#ifndef LIGHT_H_
#define LIGHT_H_

class Light{
private:

	static const float DEF_GAIN;     // default gain for use with Shift()

	int pin;            // the pin for this color
	int shiftOp = -1;   //  1 or -1  controlls the direction of shift
	float lower = 0;   // the Power limits 0-1
	float upper = 8;   // 0000

	void calcPow();     // called from Slide()

public:

	enum fadeMode { // declare enum fro setting fade mode
		LIN, SIN, EXP, EXPSIN
	};

	float base = 0.5; //the base value fro 0 to 1 from which the brightness is calculated
	int power = 1; 			// led Power 1 to 255

	Light(int inPin);   // constructor
	void shift(int op, float gain = DEF_GAIN);
	void set(bool flash = false, int inBase = -2);
	void slide(float gain = 0.02);
	static void setMode(fadeMode inMode);
};

#endif /* LIGHT_H_ */
