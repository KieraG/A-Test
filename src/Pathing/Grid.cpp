#include "Grid.hpp"

using Pathing::Grid;

Grid::Grid(int _gridSizeX, int _gridSizeY) {
    nodeGrid.resize(_gridSizeX);

    for (auto &array : nodeGrid) {
        array.resize(_gridSizeY);
    }

    gridSizeX = _gridSizeX, gridSizeY = _gridSizeY;

    for (auto x = 0; x < gridSizeX; x++) {
        for (auto y = 0; y < gridSizeY; y++) {
            nodeGrid[x][y].x = x;
            nodeGrid[x][y].y = y;
        }
    }
}