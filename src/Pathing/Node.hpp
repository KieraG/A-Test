#pragma once

namespace Pathing {
    class Node {
      public:
        Node();
        Node(int _x, int _y) {
            x = _x, y = _y;
            parent = nullptr;
        };

        Node *parent = nullptr;

        /// gCost + hCost;
        const int fCost() const;
        /// Distance from end node
        int hCost = 0;
        /// Distance from starting node
        int gCost = 0;
        /// X location in grid
        int x = 0;
        // Y location in grid
        int y = 0;
        /// If node is traversable then walkable == 1
        bool walkable = 1;

        const bool operator<(const Node &rhs) const;
        const bool operator==(const Node &rhs) const;

        auto toggleWalkable() -> void;


    };
};
