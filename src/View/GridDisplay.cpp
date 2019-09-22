#pragma once

#include "GridDisplay.hpp"

#include "Engine/OpenGL.hpp"

namespace GridDisplay {

    void displayGrid(Grid &grid) {
        for (int x = 0; x < grid.gridSizeX; x++) {
            for (int y = 0; y < grid.gridSizeY; y++) {
                glPushMatrix();
                glTranslatef(x - 0.5f * grid.gridSizeX,
                             y - 0.5f * grid.gridSizeY, -20);
                drawSquare(1, 1);
                if (!grid.nodeGrid[x][y].walkable) {
                    glPushMatrix();
                    glTranslatef(0, 0, -0.01);
                    drawSquare(1, 0);
                    glPopMatrix();
                }

                if (x == grid.selected[0] && y == grid.selected[1]) {

                    glColor3f(1, 0, 0);
                    drawSquare(1, 0);
                    glColor3f(1, 1, 1);

                }
                glPopMatrix();
            }
        }
    }
    void drawSquare(float size, bool wireframe) {
        drawRectangle(size, size, wireframe);
    }

    auto drawRectangle(float _width, float _height, bool wireframe) -> void {
        if (wireframe) {
            glBegin(GL_LINE_LOOP);
        } else {
            glBegin(GL_POLYGON);
        }
        glVertex3f(-0.5f * _width, 0.5f * _height, 0);
        glVertex3f(0.5f * _width, 0.5f * _height, 0);
        glVertex3f(0.5f * _width, -0.5f * _height, 0);
        glVertex3f(-0.5f * _width, -0.5f * _height, 0);
        glEnd();
    }
}