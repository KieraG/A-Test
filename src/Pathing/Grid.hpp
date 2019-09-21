#pragma once
#include <vector>

#include "Node.hpp"

using std::vector;

namespace Pathing {
    class Grid {
      public:
        Grid(int _gridSizeX, int _gridSizeY);

		/// 2Dimensional Vector of nodes
        vector<vector<Node>> nodeGrid;

		///The number of columns of nodes
        int gridSizeX = 0;

		///The number of rows of nodes
        int gridSizeY = 0;


    };
};