#include "matrix.h"
#include "Adafruit_NeoPixel.h"

Matrix::Matrix(Adafruit_NeoPixel* pixels) {
  this->pixels = pixels;
}

Matrix::~Matrix() {
  delete[] pixels; 
}

void Matrix::drawPixel(uint8_t x, uint8_t y, uint8_t r, uint8_t g, uint8_t b) {
  uint16_t pixel;
  if(y%2 == 1) {
    pixel = (16*y) + (15-x);
  } else {
    pixel = (16*y) + x; 
  }
  pixels->setPixelColor(pixel, pixels->Color(g, r, b));
}


