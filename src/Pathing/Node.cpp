#include "Node.hpp"

Pathing::Node::Node() {
    x = 0, y = 0;
}
auto Pathing::Node::toggleWalkable() -> void {
    this->walkable = (this->walkable) ? 0 : 1;
}