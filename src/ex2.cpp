#include "Arduino.h"

#define BUTTON_PIN 25
#define GREEN_LED_PIN 27

bool greenState = false;
bool lastButtonState = false;

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    digitalWrite(GREEN_LED_PIN, LOW);
}

/****************************************************/
void loop(void)
{
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState && !lastButtonState)
    {
        greenState = !greenState;
        digitalWrite(GREEN_LED_PIN, greenState ? HIGH : LOW);
        Serial.println(greenState ? "GREEN=1" : "GREEN=0");
    }

    lastButtonState = buttonState;
    delay(10);
}
