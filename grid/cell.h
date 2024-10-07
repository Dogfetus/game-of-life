#pragma once

#include "../utils/config.h"
#include <iostream>
#include <raylib.h>
#include <vector>

class cell {
  private:
    // state: either alive or dead
    bool _state = false;

    // position: position
    Vector2 _position;

    // border color:
    Color border;

    // yes
  public:
    cell(Vector2 &poisition);
    cell(size_t x, size_t y);

    bool alive() { return _state; }
    void kill() { _state = false; }
    void setState(const bool state) { _state = state; }
    void revive() { _state = true; }
    void draw();

    // purly for visualisation
    void redBorder();
};
