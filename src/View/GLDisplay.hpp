#pragma once

#include <time.h>

#include <SDL2/SDL.h>

#include "Engine/Engine.hpp"

#include "View/GridDisplay.hpp"

using Pathing::Grid;

namespace View {

    class GLDisplay {

        int width    = 0;
        int height   = 0;
        double ratio = 0.0;

      public:
        GLDisplay();
        static auto get() -> GLDisplay &;
        auto display() -> void;
        auto handleKeyPress(SDL_Event &event) -> void;
        /*auto update(double dt) -> void;*/

        Grid testGrid;
    };

};