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
	int shiftOp = 1;   //  1 or -1  controlls the direction of shift
	float gain;		// for fading the lights
	float lower;   // lower limit 1 to 255
	float range;   // range/multiplier 0 to 1



	void calcPow();     // called from Slide()

public:

	enum fadeMode { // declare enum fro setting fade mode
		LIN, SIN, EXP, EXPSIN
	};
	static fadeMode fMode;

	float base; //the base value fro 0 to 1 from which the brightness is calculated
	int power; 			// led Power 1 to 255

	Light(int inPin,
			float inGain = DEF_GAIN,
			float inLower = 0,
			float inUpper = 1
			);
	void shift(int op, float shiftGain = DEF_GAIN);
	void set(bool flash = false, int setBase = -2);
	void slide();
	static void setMode(fadeMode inMode);
};

#endif /* LIGHT_H_ */
