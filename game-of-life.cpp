#include "grid/grid.h"
#include <raylib.h>

int main(void) {
    InitWindow(800, 450, "Game of life");

    // sets the max fps
    SetTargetFPS(60);

    // create the level
    std::unique_ptr<grid> level(new grid(500, 500));

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground({44, 44, 44, 255});
        level->draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
