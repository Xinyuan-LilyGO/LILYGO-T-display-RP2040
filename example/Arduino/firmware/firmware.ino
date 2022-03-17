#include <TFT_eSPI.h> //Select #include <User_Setups/Setup135_ST7789.h> // Setup file for ESP8266 and ST7789 135 x 240 TFT
//https://github.com/Bodmer/TFT_eSPI
#include "picoImage.h"
#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/adc.h"

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
#define BatVol 26

#define dark()                   \
  for (int i = 0xff; i > 0; i--) \
  {                              \
    delay(5);                    \
    analogWrite(TFT_BL, i);      \
  }                              \
  digitalWrite(RedLED, !digitalRead(RedLED));

#define light()                  \
  for (int i = 0; i < 0xff; i++) \
  {                              \
    delay(5);                    \
    analogWrite(TFT_BL, i);      \
  }                              \
  digitalWrite(RedLED, !digitalRead(RedLED));

TFT_eSPI tft = TFT_eSPI();
const float conversion_factor = 3.3f / (1 << 12);

void setup()
{
  pinMode(PWR_ON, OUTPUT);
  digitalWrite(PWR_ON, 1);
  pinMode(BatVol, INPUT);
  pinMode(TFT_BL, OUTPUT);
  pinMode(RedLED, OUTPUT);
  digitalWrite(TFT_BL, 0);
  analogWrite(TFT_BL, 0);
  

  Serial.begin(115200);
  adc_init();
  adc_gpio_init(26);
  adc_select_input(0);
  tft.init();
  tft.setRotation(1);
  tft.setTextSize(2);
  tft.setSwapBytes(true);
  tft.pushImage(0, 0, 240, 135, pico);
  light();
  Serial.println("Hello Pico");
  Serial.available
  
}

void loop()
{
  static uint8_t select;
  dark();
  select += 1;
  switch (select)
  {
  case 1:
    tft.pushImage(0, 0, 240, 135, Lilygo1);
    break;
  case 2:
    tft.pushImage(0, 0, 240, 135, Lilygo2);
    break;
  case 3:
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(random(TFT_WHITE));
    tft.printf("Bat Voltage :%3.2fV", 2 * adc_read() * conversion_factor);
    break;
  default:
    select = 0;
    break;
  }
  light();
}
