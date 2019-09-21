#pragma once

namespace Pathing {
    class Node {
      public:
        Node();
        Node(int _x, int _y) {
            x = _x, y = _y;
        };

		///X location in grid
        int x = 0;

		//Y location in grid
        int y = 0;

        /// If node is traversable then walkable == 1
        bool walkable = 1;
    };
};