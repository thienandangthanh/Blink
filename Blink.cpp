#include "Arduino.h"
#include "Blink.h"

//<<constructor>>
Blink::Blink(byte _LEDpin, long _onTime, long _offTime)
{
	LEDpin = _LEDpin;
	onTime = _onTime;
	offTime = _offTime;
	pinMode(LEDpin, OUTPUT);
	LEDstate = LOW;
	previousMillis = 0;
}
//<<destructor>>
//no thing to destruct
void Blink::update()
{
	unsigned long currentMillis = millis();
	if ((LEDstate == HIGH) && (currentMillis - previousMillis >= onTime))
	{
		LEDstate = LOW;  // Turn it off
		previousMillis = currentMillis;  // Remember the time
		digitalWrite(LEDpin, LEDstate);  // Update the actual LED
	}
	else if ((LEDstate == LOW) && (currentMillis - previousMillis >= offTime))
	{
		LEDstate = HIGH;  // turn it on
		previousMillis = currentMillis;   // Remember the time
		digitalWrite(LEDpin, LEDstate);   // Update the actual LED
	}
}