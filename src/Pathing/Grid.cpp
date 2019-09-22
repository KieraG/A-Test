#include "Grid.hpp"

using Pathing::Grid;
using Pathing::Node;

Grid::Grid() {
    this->resizeGrid(this->gridSizeX, this->gridSizeY);
}

Grid::Grid(int _gridSizeX, int _gridSizeY) {
    this->resizeGrid(_gridSizeX, _gridSizeY);
}

Node &Pathing::Grid::getStartNode(){
    return this->nodeGrid[pathStart[0]][pathStart[1]];
}

Node &Pathing::Grid::getEndNode() {
    return this->nodeGrid[pathEnd[0]][pathEnd[1]];
}

Node &Pathing::Grid::getSelectedNode() {
    return this->nodeGrid[selected[0]][selected[1]];
}

void Pathing::Grid::resetGridCosts() {
    for (auto x = 0; x < gridSizeX; x++) {
        for (auto y = 0; y < gridSizeY; y++) {
            nodeGrid[x][y].gCost = 0;
            nodeGrid[x][y].hCost = 0;
        }
    }
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

vector<Node *> Grid::getNeighbours(Node &node) {
    vector<Node *> newList;
    int nodeX = node.x;
    int nodeY = node.y;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x != 0 || y != 0) {
                if (!(nodeX + x <= -1 || nodeX + x >= gridSizeX ||
                      nodeY + y <= -1 || nodeY + y >= gridSizeY)) {
                    newList.push_back(&nodeGrid[nodeX + x][nodeY + y]);
                }
            }
        }
    }

    return newList;
}