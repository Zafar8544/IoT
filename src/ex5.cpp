#include "Arduino.h"

#define BUTTON_PIN 25
#define YELLOW_LED_PIN 12
#define LIGHT_PIN 33

bool lastButtonState = false;

/****************************************************/
void flashYellowAck(void)
{
    digitalWrite(YELLOW_LED_PIN, HIGH);
    delay(100);
    digitalWrite(YELLOW_LED_PIN, LOW);
}

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(BUTTON_PIN, INPUT);
    pinMode(LIGHT_PIN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    digitalWrite(YELLOW_LED_PIN, LOW);
}

/****************************************************/
void loop(void)
{
    bool buttonState = digitalRead(BUTTON_PIN);

    if (buttonState && !lastButtonState)
    {
        int snapshotValue = analogRead(LIGHT_PIN);
        Serial.print("snapshot=");
        Serial.println(snapshotValue);
        flashYellowAck();
    }

    lastButtonState = buttonState;
    delay(10);
}
