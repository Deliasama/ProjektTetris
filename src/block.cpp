#include "block.h"
#include "vector.h"

Block::Block() {
  rotationState = 0;
  blockOffset = new Vector<int8_t>(0, 0);
}

Block::~Block() {
  for(int i = 0; i<4; i++) {
    delete [] positions[i];
  }
  delete [] positions;
  delete blockOffset; 
}
