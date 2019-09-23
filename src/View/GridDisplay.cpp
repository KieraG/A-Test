#pragma once

#include "GridDisplay.hpp"

#include "Engine/OpenGL.hpp"

namespace GridDisplay {

    void displayGrid(Grid &grid) {
        for (int x = 0; x < grid.gridSizeX; x++) {
            for (int y = 0; y < grid.gridSizeY; y++) {
                glPushMatrix();
                glTranslatef(x - 0.5f * grid.gridSizeX,
                             y - 0.5f * grid.gridSizeY, 0);
                drawSquare(1, 1);
                if (!grid.nodeGrid[x][y].walkable) {
                    glPushMatrix();
                    glColor3f(0.7f, 0.7f, 0.7f);
                    glTranslatef(0.f, 0.f, -0.01f);
                    drawSquare(1.f, 0.f);
                    glColor3f(1.f, 1.f, 1.f);
                    glPopMatrix();
                }
                if (x == grid.selected[0] && y == grid.selected[1]) {
                    glColor3f(1.f, 0.f, 0.f);
                    drawSquare(0.8f, 0.f);
                    glColor3f(1.f, 1.f, 1.f);
                }
                if (x == grid.pathStart[0] && y == grid.pathStart[1]) {
                    glColor3f(0.f, 1.f, 0.f);
                    drawSquare(0.8f, 0.f);
                    glColor3f(1.f, 1.f, 1.f);
                }
                if (x == grid.pathEnd[0] && y == grid.pathEnd[1]) {
                    glColor3f(0.f, 0.f, 1.f);
                    drawSquare(0.8f, 0.f);
                    glColor3f(1.f, 1.f, 1.f);
                }
                glPopMatrix();
            }
        }
    }

    auto displayPath(std::vector<Node *> path, Grid &grid) -> void {
        for (auto n : path) {
            glPushMatrix();
            glTranslatef(n->x - 0.5f * grid.gridSizeX,
                         n->y - 0.5f * grid.gridSizeY, 0);
            glColor3f(1, 1, 0);
            drawSquare(0.7, 0);
            glColor3f(1, 1, 1);
			glPopMatrix();
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