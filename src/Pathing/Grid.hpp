#pragma once
#include <vector>

#include "Node.hpp"

using std::vector;

namespace Pathing {
    class Grid {
      public:
        Grid();
        Grid(int _gridSizeX, int _gridSizeY);

        void resizeGrid(int x, int y);

        /// 2Dimensional Vector of nodes
        vector<vector<Node>> nodeGrid;

        /// The number of columns of nodes
        int gridSizeX = 5;

        /// The number of rows of nodes
        int gridSizeY = 5;

        int selected[2]  = {0, 0};
        int pathStart[2] = {0, 0};
        int pathEnd[2]   = {0, 0};

        vector<Node*> getNeighbours(Node &_node);
    };
};