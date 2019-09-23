#pragma once

#include "Pathing/Grid.hpp"

using Pathing::Grid;
using Pathing::Node;

namespace GridDisplay {

    auto drawRectangle(float width, float height, bool wireframe) -> void;
    auto drawSquare(float size, bool wireframe) -> void;
    auto displayGrid(Grid &grid) -> void;
    auto displayPath(std::vector<Node *> path, Grid &grid) -> void;

};
