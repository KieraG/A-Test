#pragma once

#include <time.h>

#include <SDL2/SDL.h>
#include <glm/vec3.hpp>

#include "Engine/Engine.hpp"
#include "Pathing//Pathfinding.hpp"
#include "View/GridDisplay.hpp"

using Pathing::Grid;

namespace View {

    class GLDisplay {

        int width                 = 0;
        int height                = 0;
        double ratio              = 0.0;
        glm::vec3 gridTranslation = {0, 0, -20.f};

      public:
        struct Camera {
            glm::vec3 position = {0.f, 0.f, 0.f};
            glm::vec3 look     = {0.f, 0.f, -1.f};
            glm::vec3 up       = {0.f, 1.f, 0.f};
        } camera;
        GLDisplay();
        static auto get() -> GLDisplay &;
        auto updateCamera() -> void;
        auto display() -> void;
        auto handleKeyPress(SDL_Event &event) -> void;
        auto handleMouseWheel(SDL_Event &event) -> void;
        /*auto update(double dt) -> void;*/

        Grid testGrid;
    };

};