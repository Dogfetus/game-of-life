#include "cell.h"
#include <raylib.h>

cell::cell(Vector2 &poisition)
    : _position(poisition), border({100, 100, 100, 100}) {}

cell::cell(size_t x, size_t y)
    : _position({(float)x, (float)y}), border({100, 100, 100, 100}) {}

void cell::draw() {
    // Draw the filled rectangle
    if (_state)
        DrawRectangle(_position.x, _position.y, CELL_SIZE, CELL_SIZE,
                      {255, 255, 255, 150});
    else
        DrawRectangle(_position.x, _position.y, CELL_SIZE, CELL_SIZE, BLACK);

    // Draw the border
    DrawRectangleLinesEx(
        Rectangle{_position.x, _position.y, CELL_SIZE, CELL_SIZE}, 1.0f,
        border);
}

void cell::redBorder() { border = RED; }
