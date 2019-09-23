#pragma once

#include "Pathfinding.hpp"

#include <iostream>
#include <math.h>
#include <set>
#include <algorithm>

using Pathing::Pathfinding;
using Pathing::Node;

int Pathing::Pathfinding::findDistance(Node &nodeA, Node &nodeB) {
    int distanceX = abs(nodeA.x - nodeB.x);
    int distanceY = abs(nodeA.y - nodeB.y);

    if (distanceX > distanceY) {
        return diagonalCost * distanceY + straightCost * abs(distanceX - distanceY);
    } else {
        return diagonalCost * distanceX + straightCost * abs(distanceY - distanceX);
    }
}

bool Pathing::Pathfinding::containsNode(std::vector<Node*> &set, Node *node) {
    for (auto m : set) {
        if (node == m) {
            return true;
        }
    }
    return false;
}

std::vector<Node *> Pathing::Pathfinding::traceRoute(Node *endNode) {

    std::vector<Node *> path;
    Node *currentNode = endNode;

	while (currentNode->parent != nullptr) {
        path.push_back(currentNode);
        currentNode = currentNode->parent;
	}
    std::reverse(path.begin(), path.end());
    return path;
}

std::vector<Node*> Pathing::Pathfinding::findPath(Grid &nodeGrid, Node &startNode, Node &endNode) {
    std::vector<Node *> openSet;
    std::vector<Node *> closedSet;
    nodeGrid.resetGridCosts();

    openSet.push_back(&startNode);

    while (!openSet.empty()) {

        Node *currentNode = openSet[0];

        for (int i = 1; i < openSet.size(); i++) {
            if (openSet[i]->fCost() < currentNode->fCost()) {
                currentNode = openSet[i];
            }
        }

		// Remove current node from openSet
        for (auto it = openSet.begin(); it != openSet.end();) {
            if (*it == currentNode) {
                it = openSet.erase(it);
            } else {
                ++it;
            }
        }

		closedSet.push_back(currentNode);

		if (currentNode == &endNode) {
            std::cout << "Found Path\n";
            return traceRoute(&endNode);
		}

		for (auto neighbour : nodeGrid.getNeighbours(*currentNode)) {
        
			if (containsNode(closedSet, neighbour) || !neighbour->walkable) {
                continue;
			}

			neighbour->gCost = findDistance(*neighbour, *currentNode);
            neighbour->hCost = findDistance(*neighbour, endNode);
            neighbour->parent = currentNode;

			for (auto n : openSet) {
                if (neighbour == n && neighbour->gCost > n->gCost) {
                    continue;
				}
			}
            openSet.push_back(neighbour);
		}
    }
    std::cout << "No path\n";
    std::vector<Node *> emptyList;
    return emptyList;
}
