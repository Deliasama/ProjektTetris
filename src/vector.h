#pragma once

template<typename T>
class Vector {
  public:
  T x;
  T y;
  
  Vector(T x, T y) : x(x), y(y) {}
  ~Vector() {};
  Vector<T> add(Vector<T> otherVector) {
    return Vector<T>(x + otherVector.x, y+otherVector.y);
  }
};
