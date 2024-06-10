#include "game.h"
#include "Adafruit_NeoPixel.h"
#include "block.h"
#include "matrix.h"
#include "blocks.cpp"
#include "vector.h"
#include <Arduino.h>


//  cmake --build build -j -t upload-blink

void moveBlock(Block* block, uint8_t x, uint8_t y) {
  block->blockOffset->x += x;
  block->blockOffset->y += y;
}

Game::Game() {
  pixels = new Adafruit_NeoPixel(256, 10, NEO_RGB+NEO_KHZ800);
  pixels->setBrightness(20);
  display = new Matrix(pixels);

  for(int iy = 0; iy<16; iy++) {
    for(int ix = 0; ix<8; ix++) {
      tiles[ix][iy] = 0;
    }
  }
  
  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  drawNextBlock();
  drawLine();

  moveBlock(currentBlock, 3, 14);
}

Game::~Game() {

}

void Game::drawPixel(uint8_t x, uint8_t y, uint8_t id) {
  switch(id) {
    case 0:
      display->drawPixel(x, y, 0, 0, 0);
      break;
    case 1:
      display->drawPixel(x, y, 47, 230, 23);
      break;
    case 2:
      display->drawPixel(x, y, 232, 18, 18);
      break;
    case 3:
      display->drawPixel(x, y, 226, 116, 17);
      break;
    case 4:
      display->drawPixel(x, y, 237, 234, 4);
      break;
    case 5:
      display->drawPixel(x, y, 166, 0, 247);
      break;
    case 6:
      display->drawPixel(x, y, 21, 204, 209);
      break;
    case 7:
      display->drawPixel(x, y, 13, 64, 216);
      break;
  }
}

void Game::drawPixel(Vector<uint8_t> vector, uint8_t id) {
  switch(id) {
    case 0:
      display->drawPixel(vector.x, vector.y, 0, 0, 0);
      break;
    case 1:
      display->drawPixel(vector.x, vector.y, 47, 230, 23);
      break;
    case 2:
      display->drawPixel(vector.x, vector.y, 232, 18, 18);
      break;
    case 3:
      display->drawPixel(vector.x, vector.y, 226, 116, 17);
      break;
    case 4:
      display->drawPixel(vector.x, vector.y, 237, 234, 4);
      break;
    case 5:
      display->drawPixel(vector.x, vector.y, 166, 0, 247);
      break;
    case 6:
      display->drawPixel(vector.x, vector.y, 21, 204, 209);
      break;
    case 7:
      display->drawPixel(vector.x, vector.y, 13, 64, 216);
      break;
  }
}

void Game::handleInputs() {
  // UP
  if(digitalRead(buttonUp) == HIGH) {
    if(!isUpPressed) {
      isUpPressed = true;
      clearBlock();
      currentBlock->rotationState ++;
      if(currentBlock->rotationState >= 4)currentBlock->rotationState=0;

      if(isColliding()) {
        currentBlock->rotationState--;
        if(currentBlock->rotationState >= 128)currentBlock->rotationState = 3;
      }

      drawBlock();
    }
  } else {
    isUpPressed = false;
  }
  // DOWN
  if(digitalRead(buttonDown) == HIGH) {
    if(!isDownPressed) {
      isDownPressed = true;
      moveDown();
    }
  } else {
    isDownPressed = false;
  }
  // LEFT
  if(digitalRead(buttonLeft) == HIGH) {
    if(!isLeftPressed) {
      isLeftPressed = true;
      clearBlock();
      currentBlock->blockOffset->x --;

      if(isColliding()) {
        currentBlock->blockOffset->x ++;
      }

      drawBlock();
    } 
  } else {
    isLeftPressed = false;
  }
  // RIGHT
  if(digitalRead(buttonRight) == HIGH) {
    if(!isRightPressed) {
      isRightPressed = true;
      clearBlock();
      currentBlock->blockOffset->x ++;

      if(isColliding()) {
        currentBlock->blockOffset->x --;
      }

      drawBlock();
    } 
  } else {
    isRightPressed = false;
  }
}

void Game::drawBlock() {
  for(int i = 0; i<4; i++) {
    drawPixel(currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x, currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y, currentBlock->id);
  }
  pixels->show();
}

void Game::clearBlock() {
  for(int i = 0; i<4; i++) {
    drawPixel(currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x, currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y, 0);
  }
  pixels->show();
}

void Game::moveDown() {
  clearBlock();
  currentBlock->blockOffset->y --;

  // check collision with floor
  for(int i = 0; i<4; i++) {
    if((int) currentBlock->blockOffset->y + currentBlock->positions[currentBlock->rotationState][i].y < 0) {
      currentBlock->blockOffset->y ++;
      lockBlock();
      return;
    }
    if(tiles[currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x][currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y] != 0) {
      currentBlock->blockOffset->y ++;
      lockBlock();
      return;
    }
  }
  
  drawBlock();
}

bool Game::isColliding() {
  for(int i = 0; i<4; i++) {
    if(tiles[currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x][currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y] != 0)return true;
    if((int) currentBlock->blockOffset->x + currentBlock->positions[currentBlock->rotationState][i].x < 0 || (int) currentBlock->blockOffset->x + currentBlock->positions[currentBlock->rotationState][i].x >= 8)return true;
  }
  return false;
}

void Game::gameOver() {
  pixels->clear();
  for(int x = 0; x<8; x++) {
    for(int y = 0; y<16; y++) {
      tiles[x][y] = 0;
    }
  }
  delete nextBlock;
  delete currentBlock;

  currentBlock = getRandomBlock();
  nextBlock = getRandomBlock();
  drawTiles();
  drawNextBlock();
  drawLine();

  moveBlock(currentBlock, 3, 14);
  pixels->show();
}

void Game::lockBlock() {
  if(currentBlock->blockOffset->y >= 14) {
    gameOver();
    return;
  }
  pixels->clear();
  bool hasToClear = false;
  int highestCompleteRow = 0;
  for(int i = 0; i<4; i++) {
    drawPixel(currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x, currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y, currentBlock->id);
    tiles[currentBlock->positions[currentBlock->rotationState][i].x + currentBlock->blockOffset->x][currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y] = currentBlock->id;

    bool isRowFull = true;
    for(int ix = 0; ix<8; ix++) {
      if(tiles[ix][currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y] == 0)isRowFull = false;
    }
    if(isRowFull) {
      if(currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y > highestCompleteRow)highestCompleteRow = currentBlock->positions[currentBlock->rotationState][i].y + currentBlock->blockOffset->y;
      hasToClear = true;
    }
  }

  // clear highest line and the 3 below that
  if(hasToClear) {
    for(int i = 0; i<4; i++) {
      if(highestCompleteRow-i >= 0) {
        bool isRowFull = true;
        for(int ix = 0; ix<8; ix++) {
          if(tiles[ix][highestCompleteRow-i] == 0)isRowFull = false;
        }
        if(isRowFull) clearRow(highestCompleteRow-i);
      }
    }
  }
  drawTiles();
  drawLine();
  pixels->show();

  // free Memory for the new Block
  delete currentBlock;
  // set new Block
  currentBlock = nextBlock;
  nextBlock = getRandomBlock();
  // draw the new nextBlock on the right and set the currentBlock position
  drawNextBlock();
  moveBlock(currentBlock, 3, 14);
  drawBlock();
}

void Game::clearRow(int row) {
  for(int i = row; i<16; i++) {
    for(int ix = 0; ix<8; ix++) {
      if(i+1 < 16)tiles[ix][i] = tiles[ix][i+1];
      if(i+1 >= 16)tiles[ix][i] = 0;
    }
  } 
}

void Game::drawTiles() {
  pixels->clear();
  for(int ix = 0; ix<8; ix++) {
    for(int iy = 0; iy<16; iy++) {
      drawPixel(ix, iy, tiles[ix][iy]);
    }
  }
}

Block* Game::getRandomBlock() {
  randomSeed(micros());
  switch(random(7)) {
    case 0: return new LBlock;
    case 1: return new JBlock;
    case 2: return new SBlock;
    case 3: return new ZBlock;
    case 4: return new TBlock;
    case 5: return new IBlock;
    case 6: return new OBlock;
  }
  return nullptr;
}

void Game::drawLine() {
  for(int i = 0; i<16; i++) {
    display->drawPixel(8, i, 64, 64, 64);
  }
}

void Game::drawNextBlock() {
  for(int i = 0; i<4; i++) {
    drawPixel(nextBlock->positions[0][i].x + 11, nextBlock->positions[0][i].y + 11, nextBlock->id);
  }
  pixels->show();
}
