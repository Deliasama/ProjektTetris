#include "block.h"
#include "vector.h"

class LBlock : public Block {
  public:
    LBlock() {
      id = 1;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 2),Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 0),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 0),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 2),Vector<uint8_t>(1, 0),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 2)}; 
  }
};
class JBlock : public Block {
  public:
    JBlock() {
      id = 2;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 2),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 0),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 2)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 0),Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 0),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
  }
};
class SBlock : public Block {
  public:
    SBlock() {
      id = 3;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 0),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 2)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 0),Vector<uint8_t>(1, 0),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 2),Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
  }
};
class ZBlock : public Block {
  public:
    ZBlock() {
      id = 4;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 2),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 2),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 0),Vector<uint8_t>(1, 0),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 0),Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 2)}; 
  }
};
class TBlock : public Block {
  public:
    TBlock() {
      id = 5;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 2),Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 0),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 1),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
  }
};
class IBlock : public Block {
  public:
    IBlock() {
      id = 6;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(0, 2),Vector<uint8_t>(1, 2),Vector<uint8_t>(2, 2),Vector<uint8_t>(3, 2)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(2, 0),Vector<uint8_t>(2, 1),Vector<uint8_t>(2, 2),Vector<uint8_t>(2, 3)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(3, 1),Vector<uint8_t>(2, 1),Vector<uint8_t>(1, 1),Vector<uint8_t>(0, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 3),Vector<uint8_t>(1, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(1, 0)}; 
  }
};
class OBlock : public Block {
  public:
    OBlock() {
      id = 7;
      positions[0] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 2),Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[1] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 2),Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[2] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 2),Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
      positions[3] = new Vector<uint8_t>[4] {Vector<uint8_t>(1, 2),Vector<uint8_t>(2, 2),Vector<uint8_t>(1, 1),Vector<uint8_t>(2, 1)}; 
  }
};

