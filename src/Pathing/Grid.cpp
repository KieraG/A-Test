#include "Grid.hpp"

using Pathing::Grid;
using Pathing::Node;

Grid::Grid() {
    this->resizeGrid(this->gridSizeX, this->gridSizeY);
}

Grid::Grid(int _gridSizeX, int _gridSizeY) {
    this->resizeGrid(_gridSizeX, _gridSizeY);
}

void Grid::resizeGrid(int _gridSizeX, int _gridSizeY) {
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

vector<Node> Grid::getNeighbours(Node &node) {
    vector<Node> newList;
    auto nodeX = node.x;
    auto nodeY = node.y;

    for (auto x = -1; x <= 1; x++) {
        for (auto y = -1; y <= 1; y++) {
            if (x != 0 && y != 0) {
                if (nodeGrid[nodeX + x][nodeY + y].walkable) {
                    newList.push_back(nodeGrid[nodeX + x][nodeY + y]);
                }
            }
        }
    }

	return newList;
}