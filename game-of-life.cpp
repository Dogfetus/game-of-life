#include "grid/grid.h"
#include "utils/config.h"
#include <raylib.h>

enum GameSceen { Menu, Settings, Gameplay };

int main(void) {
    InitWindow(WINDOWSIZE + (2 * MAPBORDERSIZE),
               WINDOWSIZE + (2 * MAPBORDERSIZE), "Game of life");

    // sets the max fps
    SetTargetFPS(60);

    // timer to help visualise stuff
    float timer = 0;

    // variable to tell if the game of life has started
    bool running = false;

    // create the level
    std::unique_ptr<grid> level(
        new grid(WINDOWSIZE, WINDOWSIZE, MAPBORDERSIZE));

    // create the start sceen
    GameSceen sceen = Menu;

    while (!WindowShouldClose()) {

        // sceen selection / window selection
        switch (sceen) {

        // this is the main menu sceen
        case Menu:
            if (IsKeyPressed(KEY_ENTER)) {
                sceen = Gameplay;
                level.reset(new grid(WINDOWSIZE, WINDOWSIZE, MAPBORDERSIZE));
            }
            break;

        // this is the settings sceen
        case Settings:
            break;

        // this is the gameplay sceen
        case Gameplay:
            if (IsKeyPressed(KEY_ESCAPE) || IsKeyPressed(KEY_CAPS_LOCK))
                sceen = Menu;
            break;
        }

        // this is where the drawing appears:
        // First clear the background
        BeginDrawing();
        ClearBackground({44, 44, 44, 255});

        // actual action:
        switch (sceen) {
        case Menu:
            running = false;
            DrawText("MENU SCREEN", (WINDOWSIZE + MAPBORDERSIZE) / 2 - 100,
                     (WINDOWSIZE + MAPBORDERSIZE) / 2 - 50, 40, DARKBLUE);
            DrawText("Press ENTER to Start",
                     (WINDOWSIZE + MAPBORDERSIZE) / 2 - 100,
                     (WINDOWSIZE + MAPBORDERSIZE) / 2 + 10, 20, DARKGRAY);
            break;
        case Settings:
            break;

        case Gameplay:
            DrawText("Press ESC to go to quit", 10, 10, 20, DARKGRAY);
            DrawText("Press S to start", 10, 30, 20, DARKGRAY);
            DrawText("Press B to draw", 10, 50, 20, DARKGRAY);

            if (IsKeyDown(KEY_B)) {
                Vector2 mousePos = GetMousePosition();
                level->revive(mousePos);
            }
            if (IsKeyPressed(KEY_S))
                running = true;
            level->draw(running, timer += GetFrameTime());
            break;
        }

        // then we end the drawing session
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
