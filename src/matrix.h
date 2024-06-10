#pragma once

#include <Arduino.h>
#include <Adafruit_NeoPixel.h>
#include "vector.h"

class Matrix {
  private:
  Adafruit_NeoPixel* pixels;

  public:
  Matrix(Adafruit_NeoPixel* pixels);
  ~Matrix();
  void drawPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b);
  void drawPixel(Vector<int8_t> vector, uint8_t r, uint8_t g, uint8_t b);
  void clear();
  void show();
};
