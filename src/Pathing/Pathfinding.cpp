#pragma once

#include "Pathfinding.hpp"

#include <iostream>
#include <math.h>
#include <set>

using Pathing::Pathfinding;

int Pathing::Pathfinding::findDistance(Node &nodeA, Node &nodeB) {
    int distanceX = abs(nodeA.x - nodeB.x);
    int distanceY = abs(nodeA.y - nodeB.y);

    if (distanceX > distanceY) {
        return diagonalCost * distanceY + straightCost * abs(distanceX - distanceY);
    } else {
        return diagonalCost * distanceX + straightCost * abs(distanceY - distanceX);
    }
}

void Pathing::Pathfinding::findPath(Grid &nodeGrid, Node &startNode, Node &endNode) {
    std::set<Node> openSet;
    std::set<Node> closedSet;

    nodeGrid.resetGridCosts();
    openSet.insert(startNode);

    while (!openSet.empty()) {
        Node currentNode = *openSet.begin();
        openSet.erase(currentNode);
        closedSet.insert(currentNode);

        if (currentNode == endNode) {
            std::cout << "Path found" << std::endl;
            break;
        }
        for (auto neighbour : nodeGrid.getNeighbours(currentNode)) {
            if (neighbour->walkable ||
                closedSet.find(currentNode) == closedSet.end()) {

                int newMovementCostToNeighbour =
                    currentNode.gCost + findDistance(currentNode, *neighbour);

                std::cout << newMovementCostToNeighbour << std::endl;

                if (newMovementCostToNeighbour < neighbour->gCost ||
                    openSet.find(*neighbour) == openSet.end()) {

                    neighbour->gCost  = newMovementCostToNeighbour;
                    neighbour->hCost  = findDistance(*neighbour, endNode);
                    neighbour->parent = &currentNode;

                    if (openSet.find(*neighbour) == openSet.end()) {
                        openSet.insert(*neighbour);
                    }
                }
            }
        }
    }
}
