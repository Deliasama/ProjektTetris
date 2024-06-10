#pragma once

#include "Adafruit_NeoPixel.h"
#include "block.h"
#include "matrix.h"

#define buttonUp 7
#define buttonRight 8
#define buttonLeft 9
#define buttonDown 6

class Game {
  public:
  Game();
  ~Game();
  void drawPixel(uint8_t x, uint8_t y, uint8_t id);
  void drawPixel(Vector<uint8_t> vector, uint8_t id);
  void handleInputs();
  void drawBlock();
  void clearBlock();
  void lockBlock();
  void moveDown();
  bool isColliding();
  void clearRow(int row);
  void drawTiles();
  Block* getRandomBlock();
  void drawLine();
  void drawNextBlock();
  void gameOver();

  private:
  Adafruit_NeoPixel* pixels;
  Matrix* display;
  uint8_t tiles[8][16];
  Block* currentBlock;
  Block* nextBlock;
  bool isUpPressed, isLeftPressed, isRightPressed, isDownPressed = false;
};
