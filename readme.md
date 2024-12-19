# Game of Life in C++

## Overview

This is a simple implementation of Conway's Game of Life in C++, using the Raylib library for rendering. The program provides a graphical interface where you can draw cells, start the simulation, and switch between a menu screen and the gameplay screen. The game features a grid-based world where cells follow the rules of Conway's Game of Life.

## Features

- **Interactive Grid**: Use the mouse to draw live cells on the grid.
- **Menu and Gameplay Modes**: Start the simulation from a menu screen.
- **Simulation Controls**:
  - Press **S** to start the simulation.
  - Hold **B** and use the mouse to draw cells. (not yet implemented)
  - Press **ESC** or **CAPS LOCK** to return to the main menu.

## Installation

### Prerequisites

- A C++ compiler (supporting C++11 or later)
- [Raylib](https://www.raylib.com/) installed on your system
- CMake (optional, for build automation)

### Build Instructions

1. Clone this repository:
   ```bash
   git clone https://github.com/Dogfetus/game-of-life-cpp.git
   cd game-of-life-cpp
   ```

2. Compile the project:
   ```bash
   g++ -std=c++11 -o game main.cpp -lraylib
   ```

3. Run the game:
   ```bash
   ./game
   ```

## Usage

1. Launch the game by running the compiled executable.
2. The game starts in the **Menu Screen**:
   - Press **ENTER** to switch to the gameplay screen.
3. In the **Gameplay Screen**:
   - Press **S** to start the Game of Life simulation.
   - Hold **B** and click to create live cells on the grid. (Not yet implemented)
   - Press **ESC** or **CAPS LOCK** to return to the menu.

## Code Structure

- **grid**: Manages the Game of Life grid, including cell states and rendering.
- **config**: Contains configurable constants such as `WINDOWSIZE` and `MAPBORDERSIZE`.
- **main.cpp**: The main entry point for the application, handling window management, game state transitions, and rendering.

## Technologies Used

- [Raylib](https://www.raylib.com/): A simple and easy-to-use library for game development.
- C++11: For modern C++ features and better memory management.

## Contributing

Feel free to fork this repository, create issues, and submit pull requests. All contributions are welcome!

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
