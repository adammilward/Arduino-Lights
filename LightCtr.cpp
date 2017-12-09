/*
 * LightCtr.cpp
 *
 *  Created on: 22 Feb 2017
 *      Author: Adam Milward
 */

#include "LightCtr.h"

Light LightCtr::Red(CONFIG::RED_PIN, 0);
Light LightCtr::Green(CONFIG::GREEN_PIN, 1);
Light LightCtr::Blue(CONFIG::BLUE_PIN, 2);

LightCtr::LightCtr() {

}

void LightCtr::setCom(SerialCom *inCom) {
    comPtr = inCom;
    Red.setCom(inCom);
    Green.setCom(inCom);
    Blue.setCom(inCom);
}

bool LightCtr::actionSerial(String* firstWordPtr, int arrayLength){
    bool actioned = false;
    if (1 == arrayLength) {
        actioned = actionOneWord(firstWordPtr);
    } else if (2 == arrayLength) {
        actioned = parseTwoWords(firstWordPtr);
    }
    if (!actioned) {
        help();
    }
    return actioned;
}

void LightCtr::help() {
    comPtr->out(F("Command not recognised, options are:"));
    comPtr->out(F("the name of a button on the remote"));
    comPtr->out(F(""));
    comPtr->out(F("- or"));
    comPtr->out(F("- Single Word Commands "));
    int i = oneWordLength;
    while (i--) {
       comPtr->out(oneWordCommands[i]);
    }
    comPtr->out(F(""));
    comPtr->out(F("- or"));
    comPtr->out(F("-   word + number "));
    i = wordAndFloatLength;
    while (i--) {
       comPtr->outWd(wordAndFloatCommands[i]);
        comPtr->out(F(" [nn]"));
    }
    comPtr->out(F("eg. 'report 10';"));
    comPtr->out(F(""));
    comPtr->out(F("- or"));
    comPtr->out(F("- Two Word Commands"));
    comPtr->out(F("all|red|green|blue|lower|upper|delay"));
    comPtr->out(F("+"));
    comPtr->out(F("up|down|top|bottom"));
    comPtr->out(F("eg. delay top"));
}

bool LightCtr::actionOneWord(String* word){
    int i = oneWordLength;
    while (i--) {
        if (oneWordCommands[i] == *word) {
            (this->*oneWordActions[i])();
            return true;
        }
    }
    i = remoteAliasLength;
    while (i--) {
        if (remoteAlias[i] == *word) {
            (this->*actions[ctrMode][i])();
            return true;
        }
    }
    return false;
}

bool LightCtr::parseTwoWords(String* firstWordPtr) {
    if (comPtr->isNum((firstWordPtr+1))) {
        float value = (firstWordPtr+1)->toFloat();
        return actionWordAndFloat(firstWordPtr, value);
    } else {
        return actionTwoWords(firstWordPtr);
    }
}

bool LightCtr::actionWordAndFloat(String* word, float value) {
    int i = oneWordLength;
    while (i--) {
        if (wordAndFloatCommands[i] == *word) {
            (this->*wordAndFloatActions[i])(value);
            return true;
        }
    }
    return false;
}

bool LightCtr::actionTwoWords(String* firstWordPtr) {
    int i = firstOfTwoLength;
    while (i --) {
        if (firstOfTwoCommands[i] == *firstWordPtr) {
            int j = secondOfTwoLength;
            while (j--) {
                if (secondOfTwoCommands[j] == *(firstWordPtr+1)) {
                    (this->*twoWordActions[i][j])();
                    return true;
                }
            }
        }
    }
    return false;
}

bool LightCtr::actionRemote(unsigned long inValue){
    for (int i = 0; i < 20; i++) {
        if (codes[i] == inValue) {
            (this->*actions[ctrMode][i])();
            comPtr->out(i);
            return true;
        }
    }
    return false;
}

void LightCtr::setReportDelay(float delaySeconds) {
    reportDelay = (unsigned int)(delaySeconds * 1000);
    waitMillisReport = millis() + reportDelay;
    report();
}

void LightCtr::report() {
    comPtr->outWd(F("Red      base: "));
    comPtr->outWd(Red.base);
    comPtr->outWd(F("  power: "));
    comPtr->out(Red.power);

    comPtr->outWd(F("Green  base: "));
    comPtr->outWd(Green.base);
    comPtr->outWd(F("  power: "));
    comPtr->out(Green.power);

    comPtr->outWd(F("Blue     base: "));
    comPtr->outWd(Blue.base);
    comPtr->outWd(F("  power: "));
    comPtr->out(Blue.power);

    comPtr->outWd(F("Red      gain: "));
    comPtr->out(Red.gain);

    comPtr->outWd(F("Green  gain: "));
    comPtr->out(Green.gain);

    comPtr->outWd(F("Blue     gain: "));
    comPtr->out(Blue.gain);

    comPtr->outWd(F("Red      lower: "));
    comPtr->outWd(Red.lower);
    comPtr->outWd(F("  range: "));
    comPtr->out(Red.range);

    comPtr->outWd(F("Green  lower: "));
    comPtr->outWd(Green.lower);
    comPtr->outWd(F("  range: "));
    comPtr->out(Green.range);

    comPtr->outWd(F("Blue     lower: "));
    comPtr->outWd(Blue.lower);
    comPtr->outWd(F("  range: "));
    comPtr->out(Blue.range);

    if (STATIC == ctrMode) {
        comPtr->outWd(F("Mode: STATIC"));
    } else {
        comPtr->outWd(F("FadeMode: "));
        comPtr->out(Light::fMode);
        comPtr->outWd(F("Delay: "));
        comPtr->out(fadeDelay);
    }
    comPtr->outWd(F("report delay millis= "));
    comPtr->out((int)reportDelay);
}

void LightCtr::interrupt(){
    static int counter = 0;  // increments each repetition
    switch (counter) {
    case 1:
        // slide should not be more than 0.002 for smootheness
        Red.slide();
        break;
    case 2:
        Green.slide();
        break;
    case 3:
        Blue.slide();
        break;
    default:
        counter = 0;
        break;
    }
    counter++;
}
void LightCtr::retrieveStore(colour inColour){
    //Serial.print("retrieveStore Colour: ");
    //Serial.println(inColour);
    tempStore[0] = Red.base;
    tempStore[1] = Green.base;
    tempStore[2] = Blue.base;
    //Serial.print("Stored Values: ");
    //Serial.print(colourStore[inColour][0]);
    //Serial.print(colourStore[inColour][1]);
    //Serial.println(colourStore[inColour][2]);
    Red.set(colourStore[inColour][0]);
    Green.set(colourStore[inColour][1]);
    Blue.set(colourStore[inColour][2]);
    ctrMode = STATIC;
}
void LightCtr::storeThis(colour inColour){
    //Serial.print("store New Colour ");
    //Serial.println(inColour);
    Red.set(tempStore[0]);
    Green.set(tempStore[1]);
    Blue.set(tempStore[2]);
    colourStore[inColour][0] = tempStore[0];
    colourStore[inColour][1] = tempStore[1];
    colourStore[inColour][2] = tempStore[2];
    //Serial.print("Stored Values: ");
    //Serial.print(colourStore[inColour][0]);
    //Serial.print(colourStore[inColour][1]);
    //Serial.println(colourStore[inColour][2]);
}

void LightCtr::allSet(float inBase) {
    Red.set((inBase * 0.11) - 0.1);
    Green.set((inBase * 0.11) - 0.1);
    Blue.set((inBase * 0.11) - 0.1);
}
void LightCtr::redSet(float inBase) {
    Red.set((inBase * 0.11) - 0.1);
}
void LightCtr::greenSet(float inBase) {
    Green.set((inBase * 0.11) - 0.1);
}
void LightCtr::blueSet(float inBase) {
    Blue.set((inBase * 0.11) - 0.1);
}

void LightCtr::fadeOff() {
    ctrMode = STATIC;
}

void LightCtr::allBot(){
    Red.set(0);
    Green.set(0);
    Blue.set(0);
}
void LightCtr::allTop(){
    Red.set(1);
    Green.set(1);
    Blue.set(1);
}
void LightCtr::redBot() { Red.set(0);}
void LightCtr::redTop() { Red.set(1);}
void LightCtr::redOff() { Red.set(-1);}
void LightCtr::greenBot() { Green.set(0);}
void LightCtr::greenTop() { Green.set(1);}
void LightCtr::greenOff() { Green.set(-1);}
void LightCtr::blueBot() { Blue.set(0);}
void LightCtr::blueTop() { Blue.set(1);}
void LightCtr::blueOff() { Blue.set(-11);}
void LightCtr::lowerBot() {
    Red.changeLower(-1, 1);
    Green.changeLower(-1, 1);
    Blue.changeLower(-1, 1);
}
void LightCtr::lowerTop() {
    Red.changeLower(1, 1);
    Green.changeLower(1, 1);
    Blue.changeLower(1, 1);
}
void LightCtr::upperBot() {
    Red.changeUpper(-1, 1);
    Green.changeUpper(-1, 1);
    Blue.changeUpper(-1, 1);
}
void LightCtr::upperTop() {
    Red.changeUpper(1, 1);
    Green.changeUpper(1, 1);
    Blue.changeUpper(1, 1);
}
void LightCtr::delayBot(){
    fadeDelay = CONFIG::DELAY_MIN-1;
    checkDelay();
}
void LightCtr::delayTop() {
    fadeDelay = CONFIG::DELAY_MAX+1;
    checkDelay();
}
void LightCtr::delaySet(float inDelay) {
    fadeDelay = (int)inDelay;
    checkDelay();
}

void LightCtr::allUp(){
    Red.shift(+1);
    Green.shift(+1);
    Blue.shift(+1);
}

void LightCtr::allDown(){
    Red.shift(-1);
    Green.shift(-1);
    Blue.shift(-1);
}
void LightCtr::on (){ //off
    Red.set(0.5);
    Green.set(0.5);
    Blue.set(0.5);
}
void LightCtr::off (){ //off
    Red.set(-1);
    Green.set(-1);
    Blue.set(-1);
}
void LightCtr::redUp   () { Red.shift(+1);}
void LightCtr::greenUp () { Green.shift(+1); }
void LightCtr::blueUp () { Blue.shift(+1); }
void LightCtr::redDown() { Red.shift(-1); }
void LightCtr::greenDown() { Green.shift(-1); }
void LightCtr::blueDown() { Blue.shift(-1); }
void LightCtr::store1 () {
    if (holdCount == 0) {
        retrieveStore(RED);
    } else if (holdCount == 4) {
        storeThis(RED);
    }
    ctrMode = STATIC;
}
void LightCtr::store2 () {
    if (holdCount == 0) {
        retrieveStore(GREEN);
    } else if (holdCount == 4) {
        storeThis(GREEN);
    }
    ctrMode = STATIC;
}
void LightCtr::store3 () {
    if (holdCount == 0) {
        retrieveStore(BLUE);
    } else if (holdCount == 4) {
        storeThis(BLUE);
    }
    ctrMode = STATIC;
}
void LightCtr::store4 () {
    if (holdCount == 0) {
        retrieveStore(WHITE);
    } else if (holdCount == 4) {
        storeThis(WHITE);
    }
    ctrMode = STATIC;
}
void LightCtr::lin    () {
    ctrMode = FADE;
    Light::fMode = Light::LIN;
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::sin    () {
    ctrMode = FADE;
    Light::fMode = Light::SIN;
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::exp    () {
    ctrMode = FADE;
    Light::fMode = Light::EXP;
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}
void LightCtr::sinExp    () {
    ctrMode = FADE;
    Light::fMode = Light::EXPSIN;
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
}

void LightCtr::red_f(){
    Red.changeLower(+1, 0.2);
    Green.changeLower(+1, 0.2);
    Blue.changeLower(+1, 0.2);
}
void LightCtr::orange_f (){
    Red.changeLower(-1, 0.2);
    Green.changeLower(-1, 0.2);
    Blue.changeLower(-1, 0.2);
}
void LightCtr::green_f (){
    Red.changeUpper(+1, 0.2);
    Green.changeUpper(+1, 0.2);
    Blue.changeUpper(+1, 0.2);
}
void LightCtr::yellow_f(){
    Red.changeUpper(-1, 0.2);
    Green.changeUpper(-1, 0.2);
    Blue.changeUpper(-1, 0.2);
}
void LightCtr::white_f(){
    fadeDelay *= 4;
    checkDelay();
}
void LightCtr::purple_f(){
    fadeDelay /= 4;
    checkDelay();
}
void LightCtr::checkDelay(){
    if (fadeDelay > CONFIG::DELAY_MAX) {
        fadeDelay = CONFIG::DELAY_MAX;
        Red.flashHalf();
        Green.flashHalf();
        Blue.flashHalf();
    } else if (fadeDelay < CONFIG::DELAY_MIN) {
        fadeDelay = CONFIG::DELAY_MIN;
        Red.flashHalf();
        Green.flashHalf();
        Blue.flashHalf();
    }
    Red.flashOff();
    Green.flashOff();
    Blue.flashOff();
    Serial.println(fadeDelay);
    comPtr->outWd(F("delay= "));
    comPtr->out(fadeDelay);
}
void LightCtr::null(){};
