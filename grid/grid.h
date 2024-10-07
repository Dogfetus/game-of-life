#pragma once

#include "../utils/config.h"
#include "cell.h"
#include <iostream>
#include <memory>
#include <vector>

class grid {
  private:
    // size of the grid
    size_t _height, _width;
    std::vector<std::unique_ptr<cell>> _grid;
    std::vector<std::unique_ptr<cell>> _grid2;

    int calculateNeighbours(size_t cell);

  public:
    grid(const size_t &height, const size_t &width, const size_t &border);
    void revive(Vector2 pos);
    void step();
    void draw(const bool &step, float &time);
};
