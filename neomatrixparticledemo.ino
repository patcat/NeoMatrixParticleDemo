// This #include statement was automatically added by the Spark IDE.
#include "neopixel/neopixel.h"

#define PIXEL_PIN D7
#define PIXEL_COUNT 64
#define PIXEL_TYPE WS2812B

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);
int waiting[PIXEL_COUNT]  = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 0, 0, 0,
  0, 0, 0, 1, 1, 0, 0, 0,
  0, 0, 0, 0, 0, 1, 0, 0
};
int smile[PIXEL_COUNT]  = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  1, 0, 0, 0, 0, 0, 0, 1,
  1, 0, 0, 0, 0, 0, 0, 1,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 0, 1, 1, 1, 1, 0, 0
};
int frown[PIXEL_COUNT]  = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0
};
int confused[PIXEL_COUNT]  = {
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 0, 1, 0, 1, 0,
  0, 1, 0, 1, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0
};
int angry[PIXEL_COUNT]  = {
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 0, 1, 0, 0, 1, 0, 0,
  0, 0, 0, 0, 0, 0, 0, 0,
  0, 0, 1, 1, 1, 1, 0, 0,
  0, 1, 0, 0, 0, 0, 1, 0,
  0, 1, 0, 0, 0, 0, 1, 0
};

int currentFace = 0;

void setup() {
  strip.begin();
  strip.show();
  
  Spark.function("setEmotion", setEmotion);
}

void loop() {
  setPixels(20);
}

void setPixels(uint8_t wait) {
  uint16_t i;

  for (i=0; i<PIXEL_COUNT; i++) {
    if (currentFace == 0) {
        if (waiting[i] == 1) {
          strip.setPixelColor(i, 255, 255, 255);
        } else {
          strip.setPixelColor(i, 255, 100, 0);
        }
    } else if (currentFace == 1) {
        if (smile[i] == 1) {
          strip.setPixelColor(i, 255, 255, 255);
        } else {
          strip.setPixelColor(i, 0, 255, 0);
        }
    } else if (currentFace == 2) {
        if (frown[i] == 1) {
          strip.setPixelColor(i, 255, 255, 255);
        } else {
          strip.setPixelColor(i, 0, 255, 255);
        }
    } else if (currentFace == 3) {
        if (confused[i] == 1) {
          strip.setPixelColor(i, 255, 255, 255);
        } else {
          strip.setPixelColor(i, 204, 102, 255);
        }
    } else if (currentFace == 4) {
      if (angry[i] == 1) {
        strip.setPixelColor(i, 255, 255, 255);
      } else {
        strip.setPixelColor(i, 255, 0, 0);
      }
    } else {
      strip.setPixelColor(i, 255, 100, 0);
    }
  }
  strip.setBrightness(30);
  strip.show();
  delay(wait);
}

int setEmotion(String emotion) {
  if (emotion == "happy") {
    currentFace = 1;
  } else if (emotion == "sad") {
    currentFace = 2;
  } else if (emotion == "confused") {
    currentFace = 3;
  } else if (emotion == "angry") {
    currentFace = 4;
  } else {
    currentFace = 0;
  }
  
  return currentFace;
}