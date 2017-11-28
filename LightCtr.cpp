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
    comPtr->debug("array length = "+String(arrayLength));
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
    comPtr->out("Command not recognised, options are:");
    comPtr->out("the name of a button on the remote");
    comPtr->out("");
    comPtr->out("- or");
    comPtr->out("- Single Word Commands ");
    int i = oneWordLength;
    while (i--) {
       comPtr->out(String(oneWordCommands[i]));
    }
    comPtr->out("");
    comPtr->out("- or");
    comPtr->out("-   word + number ");
    i = wordAndFloatLength;
    while (i--) {
       comPtr->out(String(wordAndFloatCommands[i])+" [nn]");
    }
    comPtr->out("eg. 'report 10';");
    comPtr->out("");
    comPtr->out("- or");
    comPtr->out("- Two Word Commands");
    comPtr->out("all|red|green|blue|lower|upper|delay");
    comPtr->out("+");
    comPtr->out("up|down|top|bottom");
    comPtr->out("eg. delay top");
}

bool LightCtr::actionOneWord(String* word){
    int i = oneWordLength;
    while (i--) {
        comPtr->debug("single words index = "+String(i));
        if (oneWordCommands[i] == *word) {
            (this->*oneWordActions[i])();
            return true;
        }
    }
    i = remoteAliasLength;
    while (i--) {
        comPtr->debug("mode= "+String(ctrMode)+" index= "+String(i));
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
    comPtr->debug("first word: "+*word);
    comPtr->debug("value= "+String(value));
    int i = oneWordLength;
    while (i--) {
        comPtr->debug("single words index = "+String(i));
        if (wordAndFloatCommands[i] == *word) {
            comPtr->debug("processing word with float");
            (this->*wordAndFloatActions[i])(value);
            return true;
        }
    }
    return false;
}

bool LightCtr::actionTwoWords(String* firstWordPtr) {
    int i = firstOfTwoLength;
    while (i --) {
        comPtr->debug("first word index= "+String(i));
        if (firstOfTwoCommands[i] == *firstWordPtr) {
            int j = secondOfTwoLength;
            while (j--) {
                comPtr->debug("second word index index= "+String(j));
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
            return true;
        }
    }
    return false;
}

void LightCtr::setReportDelay(float delaySeconds) {
    comPtr->debug("LightCtr::setReportDelay() ");
    comPtr->debug(String(delaySeconds));
    reportDelay = (unsigned int)(delaySeconds * 1000);
    waitMillisReport = millis() + reportDelay;
    report();
}

void LightCtr::report() {
    comPtr->out("Red      base: "+String(Red.base)+
        "  power: "+String(Red.power));
    comPtr->out("Green  base: "+String(Green.base)+
        "  power: "+String(Green.power));
    comPtr->out("Blue     base: "+String(Blue.base)+
        "  power: "+String(Blue.power));
    comPtr->out("Red      gain: "+String(Red.gain));
    comPtr->out("Green  gain: "+String(Green.gain));
    comPtr->out("Blue     gain: "+String(Blue.gain));
    comPtr->out("Red      lower: "+String(Red.lower)+
        "  range: "+String(Red.range));
    comPtr->out("Green  lower: "+String(Green.lower)+
        "  range: "+String(Green.range));
    comPtr->out("Blue     lower: "+String(Blue.lower)+
        "  range: "+String(Blue.range));
    if (STATIC == ctrMode) {
        comPtr->out("Mode: STATIC");
    } else {
        comPtr->outWd("FadeMode: ");
        comPtr->outWd(Light::fadeModes[Light::fMode]);
        comPtr->out("Delay: "+String(fadeDelay));
    }
    comPtr->out("report delay millis= "+String(reportDelay));
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
comPtr->debugWd(String(Red.base * 100)+"    "+String(Red.power)+"    ");
comPtr->debugWd(String(Green.base * 100)+"    "+String(Green.power)+"    ");
comPtr->debug(String(Blue.base * 100)+"    "+String(Blue.power)+"    ");
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
    comPtr->out("delay= "+String(fadeDelay));
}
void LightCtr::delayTop() {
    fadeDelay = CONFIG::DELAY_MAX+1;
    checkDelay();
    comPtr->out("delay= "+String(fadeDelay));
}
void LightCtr::delaySet(float inDelay) {
    fadeDelay = (int)inDelay;
    checkDelay();
    comPtr->out("delay= "+String(fadeDelay));
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
    comPtr->out("delay= "+String(fadeDelay));
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
}
void LightCtr::null(){};
