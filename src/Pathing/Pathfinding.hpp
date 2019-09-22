#pragma once
#include "Grid.hpp"

namespace Pathing {
    class Pathfinding {
      public:
        static int findDistance(Node &nodeA, Node &nodeB);
        static void findPath(Grid &nodeGrid, Node &startNode, Node &endNode);

        static const int diagonalCost = 14;
        static const int straightCost = 10;

      private:
        Pathfinding();
    };
};