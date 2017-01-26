// Blink Library version 2.0
// extend some functions
#ifndef Blink_h
#define Blink_h

#include "Arduino.h"
class Blink {
public:
	Blink(byte _LEDpin, long _onTime, long _offTime);
	Blink(byte _LEDpin);
	void update();
	void update(long _onTime, long _offTime);
	void on();
	void on(long _onTime);
	void off();
	void off(long _offTime);

private:
	byte LEDpin, _LEDpin;
	long onTime, _onTime;
	long offTime, _offTime;
	boolean LEDstate;
	unsigned long previousMillis;
	unsigned long currentMillis = millis();
};

#endif