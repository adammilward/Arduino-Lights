/*
 * Light.h
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */



#ifndef Light_h_
#define Light_h_

class Light{
private:

	static const float DEF_GAIN;     // default gain for use with Shift()

	int pin;            // the pin for this colour
	int shiftOp = 1;    //  1 or -1  controls the direction of shift
	float gain;         // for fading the lights <= 0.002
	float lower;        // lower limit 1 to 255
	float range;        // range/multiplier 0 to 1

	void calcPow();     // called from Slide()

public:

	// mode for automatic fading
    enum fadeMode { STATIC, LIN, SIN, EXP, EXPSIN };
    static fadeMode fMode;

	float base;     // the base value <1, for deriving power <0 is off
	int power;      // led Power 1 to 255 derived from base

	Light(
		int inPin,
		float inGain = DEF_GAIN,
		float inLower = 0,
		float inUpper = 1
		);
	void shift(int op, float shiftGain = DEF_GAIN);
	void set(float setBase, bool flash = false);
	void slide();
	static void setMode(fadeMode inMode);
};

#endif /* LIGHT_H_ */
