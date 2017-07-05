#ifndef UNIT_TEST
#include <Arduino.h>
#endif
#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ir_Daikin.h>

IRDaikinESP dakinir(12);  // An IR LED is controlled by GPIO pin 4 (D2)
bool on_off_flag = false;

void setup() {
  dakinir.begin();
  Serial.begin(115200);
}


void loop() {
  Serial.println("Sending...");
  Serial.print("Now flag");
  Serial.print(on_off_flag);

  if(on_off_flag == 0){
    dakinir.on();
    dakinir.setFan(1);
    dakinir.setMode(DAIKIN_COOL);
    dakinir.setTemp(25);
    dakinir.setSwingVertical(0);
    dakinir.setSwingHorizontal(0);
    }
  
  on_off_flag = 1;

  // Set up what we want to send. See ir_Daikin.cpp for all the options.
  // Now send the IR signal.
  dakinir.send();

  delay(20000);
}
