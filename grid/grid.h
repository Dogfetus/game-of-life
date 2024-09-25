#pragma once

#include "cell.h"
#include <iostream>
#include <memory>
#include <vector>

class grid {
  private:
    size_t _height, _width;
    std::vector<std::unique_ptr<cell>> _grid;

  public:
    grid(const size_t &height, const size_t &width);
    void draw();
};
