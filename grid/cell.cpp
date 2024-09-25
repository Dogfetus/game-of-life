#include "cell.h"

cell::cell(Vector2 &poisition) : _position(poisition) {}

cell::cell(size_t &x, size_t &y) : _position({(float)x, (float)y}) {}
