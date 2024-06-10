#pragma once

#include "vector.h"
#include <Arduino.h>

class Block {
  public:
    Block();
    ~Block();
    uint8_t id;
    Vector<uint8_t>** positions = new Vector<uint8_t>*[4];
    uint8_t rotationState;
    Vector<int8_t>* blockOffset;

  private:
};
