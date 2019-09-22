#include "GLDisplay.hpp"

#include <iostream>

#include <SDL2/SDL.h>
#include <glm/gtc/type_ptr.hpp>
#include <glm/vec3.hpp>

#include "Engine/Engine.hpp"
#include "Engine/OpenGL.hpp"

using View::GLDisplay;
using namespace GridDisplay;

GLDisplay::GLDisplay() {
    auto &engine = SDLEngine::Engine::get();

    SDL_GL_GetDrawableSize(engine.window.get(), &width, &height);
    GLDisplay::ratio = static_cast<double>(width) / static_cast<double>(height);

    testGrid.nodeGrid[1][0].walkable = 0;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, width, height);
    gluPerspective(60, GLDisplay::ratio, 1, 50000);
    glMatrixMode(GL_MODELVIEW);

    glClearColor(0.f, 0.f, 0.f, 1.f);

    gluLookAt(0.f, 0.f, 0.f, 0.f, 0.f, -1.f, 0.f, 1.f, 0.f);
}

auto GLDisplay::display() -> void {
    auto &engine = SDLEngine::Engine::get();
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);

    displayGrid(testGrid);

    glDisable(GL_DEPTH_TEST);
    SDL_GL_SwapWindow(engine.window.get());
}

auto View::GLDisplay::handleKeyPress(SDL_Event &event) -> void {
    switch (event.key.keysym.scancode) {
        case SDL_SCANCODE_W: {
            testGrid.selected[1] =
                ((testGrid.selected[1] + 1) % testGrid.gridSizeY);

        } break;
        case SDL_SCANCODE_S: {
            testGrid.selected[1] =
                ((testGrid.selected[1] - 1) % testGrid.gridSizeY);
            if (testGrid.selected[1] < 0) {
                testGrid.selected[1] = testGrid.gridSizeY - 1;
            }
        } break;
        case SDL_SCANCODE_A: {
            testGrid.selected[0] =
                ((testGrid.selected[0] - 1) % testGrid.gridSizeX);
            if (testGrid.selected[0] < 0) {
                testGrid.selected[0] = testGrid.gridSizeX - 1;
            }
        } break;
        case SDL_SCANCODE_D: {
            testGrid.selected[0] =
                ((testGrid.selected[0] + 1) % testGrid.gridSizeX);
        } break;
        case SDL_SCANCODE_SPACE: {
            int x = testGrid.selected[0];
            int y = testGrid.selected[1];

            testGrid.nodeGrid[x][y].toggleWalkable();
        } break;
        default: break;
    }
}

// auto GLDisplay::update(double dt) -> void {
//    // dt == delta time
//}

auto GLDisplay::get() -> GLDisplay & {
    static auto instance = GLDisplay{};

    return instance;
}
