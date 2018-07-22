#include <Blink.h>
//Test.Blink.Library.ino
Blink led13(13,100,100); //declare LEDpin is 13, on time is 100ms, off time is 100ms
void setup() {
  // put your setup code here, to run once
}

void loop() {
  // put your main code here, to run repeatedly
    led13.update();
}
