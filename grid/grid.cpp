#include "cell.h"
#include "grid.h"
#include <memory>
#include <raylib.h>

grid::grid(const size_t &height, const size_t &width)
    : _height(height), _width(width) {
    size_t rows = height / CELL_SIZE;
    size_t columns = width / CELL_SIZE;
    std::unique_ptr<cell> tempcell(new cell());
    _grid.emplace_back(std::move(tempcell));
}

void grid::draw() {
    for (const auto &c : _grid) {
        DrawRectangle(10, 10, CELL_SIZE, CELL_SIZE, RED);
    }
};
