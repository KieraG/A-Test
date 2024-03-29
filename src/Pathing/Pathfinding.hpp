#pragma once
#include "Grid.hpp"
#include <vector>

namespace Pathing {
    class Pathfinding {
      public:
        static int findDistance(Node &nodeA, Node &nodeB);
        static std::vector<Node*> findPath(Grid &nodeGrid, Node &startNode, Node &endNode);
        static bool containsNode(std::vector<Node*> &set, Node *node);
		

        static const int diagonalCost = 14;
        static const int straightCost = 10;

      private:
        static std::vector<Node *> traceRoute(Node *endNode);
        Pathfinding();
    };
};