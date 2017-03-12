/*
 * Config.h
 *
 *  Created on: 11 Mar 2017
 *      Author: Adam Milward
 */

#ifndef CONFIG_H_
#define CONFIG_H_
class CONFIG {
public:
    const int DELAY = 20;
    static const int RED_PIN = 10;
    static const int GREEN_PIN = 9;
    static const int BLUE_PIN = 6;
    static const int IREC_PIN = 12;
};
#endif /* CONFIG_H_ */

#ifndef CONF_CH_UNO_H_
#define CONF_CH_UNO_H_
class CONF_CH_UNO : public CONFIG {
public:
    //static const int DELAY = 20;
    const int RED_PIN = 10;
    const int GREEN_PIN = 9;
    const int BLUE_PIN = 6;
    const int IREC_PIN = 12;
};
#endif /* CONF_CH_UNO_H_ */
