#include "Adafruit_NeoPixel.h"
#include "Arduino.h"
#include "matrix.h"
#include "vector.h"
#include "game.h"
#include <avr/eeprom.h>

Adafruit_NeoPixel pixels(256, 10, NEO_BGR + NEO_KHZ800);
Matrix* matrix;
uint16_t EEMEM eeAddress = 0;

void setup() {
  pinMode(buttonUp, INPUT);
  pinMode(buttonLeft, INPUT);
  pinMode(buttonRight, INPUT);
  pinMode(buttonDown, INPUT);
  pixels.begin();
  pixels.setBrightness(1);
  pixels.clear();

  matrix = new Matrix(&pixels);

  Game game;
  
  long timeUntilNextMove = 400l*1000l;
  long startTime = micros();

  // get random seed
  randomSeed(millis());

  for(;;) {
    game.handleInputs();
    
    if(timeUntilNextMove <= 0) {
      game.moveDown();
      timeUntilNextMove = 400l*1000l;
    }
    timeUntilNextMove-=micros()-startTime;
    startTime=micros();
  }
}

void loop() {}
