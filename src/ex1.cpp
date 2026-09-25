


#include "Arduino.h"

#define RED_LED_PIN 26

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT); // RED LED
}

/****************************************************/
void loop(void)
{
    digitalWrite(RED_LED_PIN, HIGH); // Turn RED ON
    Serial.println("RED ON");
    delay(500); // Wait for 500 ms

    digitalWrite(RED_LED_PIN, LOW); // Turn RED OFF
    Serial.println("RED OFF");
    delay(500); // Wait for 500 ms
}
