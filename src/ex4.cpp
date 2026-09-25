#include "Arduino.h"

#define RED_LED_PIN 26
#define GREEN_LED_PIN 27
#define BLUE_LED_PIN 14
#define YELLOW_LED_PIN 12
#define LIGHT_PIN 33

/****************************************************/
void setAllLedsOff(void)
{
    digitalWrite(RED_LED_PIN, LOW);
    digitalWrite(GREEN_LED_PIN, LOW);
    digitalWrite(BLUE_LED_PIN, LOW);
    digitalWrite(YELLOW_LED_PIN, LOW);
}

/****************************************************/
void setup(void)
{
    Serial.begin(115200);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(LIGHT_PIN, INPUT);
    setAllLedsOff();
}

/****************************************************/
void loop(void)
{
    int lightValue = analogRead(LIGHT_PIN);
    const char* band = "RED";

    setAllLedsOff();

    if (lightValue >= 0 && lightValue <= 1023)
    {
        band = "BLUE";
        digitalWrite(BLUE_LED_PIN, HIGH);
    }
    else if (lightValue >= 1024 && lightValue <= 2047)
    {
        band = "GREEN";
        digitalWrite(GREEN_LED_PIN, HIGH);
    }
    else if (lightValue >= 2048 && lightValue <= 3071)
    {
        band = "YELLOW";
        digitalWrite(YELLOW_LED_PIN, HIGH);
    }
    else if (lightValue >= 3072 && lightValue <= 4095)
    {
        band = "RED";
        digitalWrite(RED_LED_PIN, HIGH);
    }

    Serial.print("band=");
    Serial.println(band);
    delay(500);
}
