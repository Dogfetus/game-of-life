#pragma once

#include <iostream>
#include <raylib.h>
#include <vector>

#define CELL_SIZE 10

class cell {
  private:
    bool _state = false;
    Vector2 _position;

    // yes
  public:
    cell(Vector2 &poisition);
    cell(size_t &x, size_t &y);
    bool alive() { return _state; }
};
