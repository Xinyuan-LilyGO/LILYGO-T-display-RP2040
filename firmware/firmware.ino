#include <TFT_eSPI.h> //Select #include <User_Setups/Setup135_ST7789.h> // Setup file for ESP8266 and ST7789 135 x 240 TFT
//https://github.com/Bodmer/TFT_eSPI
#include "picoImage.h"
/* 
#define TFT_MISO -1
#define TFT_MOSI 3
#define TFT_SCLK 2
#define TFT_CS 5  // Chip select control pin
#define TFT_DC 1  // Data Command control pin
#define TFT_RST 0 // Reset pin (could connect to RST pin) */
#define TFT_BL 4
#define PWR_ON 22
#define BOTTON1 6
#define BOTTON2 7
#define RedLED 25

#define dark()                   \
  for (int i = 0xff; i > 0; i--) \
  {                              \
    delay(10);                   \
    analogWrite(TFT_BL, i);      \
  }                              \
  digitalWrite(RedLED, !digitalRead(RedLED));

#define light()                  \
  for (int i = 0; i < 0xff; i++) \
  {                              \
    delay(10);                   \
    analogWrite(TFT_BL, i);      \
  }                              \
  digitalWrite(RedLED, !digitalRead(RedLED));

TFT_eSPI tft = TFT_eSPI();

void setup()
{
  pinMode(PWR_ON, OUTPUT);
  digitalWrite(PWR_ON, 1);

  pinMode(TFT_BL, OUTPUT);
  pinMode(RedLED, OUTPUT);
  digitalWrite(TFT_BL, 0);
  analogWrite(TFT_BL, 0);

  Serial.begin(115200);

  tft.init();
  tft.setRotation(1);
  tft.setSwapBytes(true);
  tft.pushImage(0, 0, 240, 135, pico);
  light();
  Serial.println("Hello Pico");
}

void loop()
{
  static bool select;
  dark();
  if (select)
    tft.pushImage(0, 0, 240, 135, Lilygo1);
  else
    tft.pushImage(0, 0, 240, 135, Lilygo2);
  light();
  select = !select;
}