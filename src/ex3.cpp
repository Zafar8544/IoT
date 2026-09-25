#include "Arduino.h"

#define LIGHT_PIN 33

unsigned long lastSampleTime = 0;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(LIGHT_PIN, INPUT);
}

/****************************************************/
void loop(void)
{
    unsigned long now = millis();

    if (now - lastSampleTime >= 500)
    {
        lastSampleTime = now;
        int rawValue = analogRead(LIGHT_PIN);
        Serial.print("raw=");
        Serial.println(rawValue);
    }
}
