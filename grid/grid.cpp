#include "../utils/config.h"
#include "../utils/random.h"
#include "cell.h"
#include "grid.h"
#include <memory>
#include <raylib.h>

grid::grid(const size_t &height, const size_t &width, const size_t &border)
    : _height(height), _width(width) {
    size_t rows = height / CELL_SIZE;
    size_t columns = width / CELL_SIZE;
    size_t outside = border / CELL_SIZE;

    // create a list with all the cells in the grid
    for (size_t i = outside; i < rows + outside; i++) {
        for (size_t j = outside; j < columns + outside; j++) {
            std::unique_ptr<cell> tempcell(
                new cell(j * CELL_SIZE, i * CELL_SIZE));
            tempcell->setState(random(1000) % 20 == 0);
            _grid.emplace_back(std::move(tempcell));
        }
    }
}

void grid::draw(const bool &step, float &time) {
    // copy the state when we should moev
    if (step) {
        _grid2.clear();
        for (auto &c : _grid) {
            _grid2.emplace_back(std::make_unique<cell>(*c));
        }
    }

    // move
    if (step && time >= TIMESTAMP) {
        time = 0.0f;
        for (size_t i = 0; i < _grid.size(); i++) {

            auto neighbours = calculateNeighbours(i);

            // these are the rules:
            switch (neighbours) {

            // 2 neighbours does nothing:
            case 2:
                break;

            // 3 revives :
            case 3:
                _grid[i]->revive();
                break;

            // more than 3 or less than 2 kills:
            default:
                _grid[i]->kill();
                break;
            }
        }
    }

    // draw
    for (size_t i = 0; i < _grid.size(); i++) {
        _grid[i]->draw();
    }
};

int grid::calculateNeighbours(size_t cell) {
    // find the position of the cell (rows and columns)
    size_t cell_row = (cell / ROWSIZE);
    size_t cell_col = (cell % ROWSIZE);

    // neighbour positions:
    std::vector<int> positions;

    // total alive neighbours:
    int alive_neighbours = 0;

    // calculations to find each neighbour
    // top left:
    positions.emplace_back(((cell_row - 1) * ROWSIZE + cell_col - 1) *
                               (cell_row > 0 && cell_col > 0) -
                           (cell_row <= 0 || cell_col <= 0));
    // top middle:
    positions.emplace_back((cell_row - 1) * ROWSIZE + cell_col);
    // top right:
    positions.emplace_back(((cell_row - 1) * ROWSIZE + cell_col + 1) *
                               (cell_row > 0 && cell_col < (ROWSIZE - 1)) -
                           (cell_row <= 0 || cell_col >= (ROWSIZE - 1)));
    // left:
    positions.emplace_back(
        (cell_row * ROWSIZE + cell_col - 1) * (cell_col > 0) - (cell_col <= 0));
    // right:
    positions.emplace_back((cell_row * ROWSIZE + cell_col + 1) *
                               (cell_col < (ROWSIZE - 1)) -
                           (cell_col >= (ROWSIZE - 1)));
    // bottom left:
    positions.emplace_back(((cell_row + 1) * ROWSIZE + cell_col - 1) *
                               (cell_col > 0 && cell_row < (COLUMNSIZE - 1)) -
                           (cell_col <= 0 || cell_row >= (COLUMNSIZE - 1)));
    // bottom middle:
    positions.emplace_back((cell_row + 1) * ROWSIZE + cell_col);
    // bottom right:
    positions.emplace_back(
        ((cell_row + 1) * ROWSIZE + cell_col + 1) *
            (cell_col < (ROWSIZE - 1) && cell_row < (COLUMNSIZE - 1)) -
        (cell_col >= (ROWSIZE - 1) || cell_row >= (COLUMNSIZE - 1)));

    for (auto pos : positions) {
        if (pos >= 0 && pos <= ROWSIZE * COLUMNSIZE - 1)
            alive_neighbours += _grid2[pos]->alive();
    }

    return alive_neighbours;
}

void grid::revive(Vector2 pos) {
    std::cout << "x: " << pos.x << " and y: " << pos.y << std::endl;
}
