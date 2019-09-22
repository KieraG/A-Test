#include "Node.hpp"

Pathing::Node::Node() {
    x = 0, y = 0;
    child  = nullptr;
    parent = nullptr;
}

const int Pathing::Node::fCost() const {
    return this->gCost + this->hCost;
}

const bool Pathing::Node::operator<(const Node &rhs) const {
    
	/*if (this->fCost() < rhs.fCost() || this->fCost() == rhs.fCost()) {
        if (this->hCost <  rhs.hCost) {
            return false;
		}
	}
    return true;*/
	
	
	if (fCost() == rhs.fCost()) {
        return hCost < rhs.hCost;
    } else {
        return fCost() < rhs.fCost();
    }
}

const bool Pathing::Node::operator==(const Node &rhs) const {
    return (x == rhs.x && y == rhs.y);
}

auto Pathing::Node::toggleWalkable() -> void {
    this->walkable = (this->walkable) ? 0 : 1;
}