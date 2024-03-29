

<p align=center>
  <b> A* Algorithm Implementation </b>
</p>


<p align="center"> 
<img src="https://i.imgur.com/52d2nqk.png">
</p>

<p align = "center">
This is a test implementation of the A* pathfinding algorithm that I plan to use in a assignment. This project makes use of OpenGL and SDL2 to draw a grid on screen and recieve user input.
 I mostly follow  <a href="https://www.youtube.com/watch?v=-L-WgKMFuhE&list=PLFt_AvWsXl0cq5Umv3pMC9SPnKjfp9eGW">this</a>  tutorial for the  A* implementation.
 </p>

<p align="center">
  <a href="#grid-layout">Grid Layout</a> •
  <a href="#controls">Controls</a> •
  <a href="#building">Building</a> •
  <a href="#contributing">Contributing</a> •
  <a href="#license">License</a>
</p>


 
## Grid Layout
<b>Black Square • </b> Empty node

<b>Yellow Square • </b> Path from start node to end node

<b>Green Square • </b> Path start node

<b>Blue Square • </b> Path end node

<b>Red Square • </b> Selected grid square

<b>Grey Square • </b> Obstacle




## Controls
<b>W, A, S, D • </b> Moves the grid square selection up, left, down, or right respectively.

<b>I, J, K, L • </b> Moves the grid up, left, down, or right respectively.

<b>Z, X• </b> Sets the start and end location respectively. Sets to the currently selected grid location.

<b>Spacebar• </b> Toggles whether the currently selected grid square is traversable.

<b>Mouse Scroll• </b> Zooms in and out (currently no bounds checking)



## Building
### Tools
* macOS: [brew][brew-dl]
* Windows: [vcpkg][vcpkg-dl], [Visual Studio 2019][VS2019-dl]

### Dependencies
* macOS: `brew install cmake sdl2 sdl2_image sdl2_ttf sdl2_mixer glm`
* Linux: `sudo apt-get install cmake libsdl2-dev libsdl2-image-dev
    libsdl2-ttf-dev libsdl2-mixer-dev libglm-dev`
* Windows: `.\vcpkg.exe install --triplet x64-windows sdl2 sdl2-image sdl2-ttf
    sdl2-mixer glm`

### Cloning
```
git clone --recurse-submodules https://github.com/KieraG/A-Test.git
git submodule update --init
```

### Building
* Unix:
    ```
    cmake -S . -B build && cmake --build build && ./build/a-test
    ```
* Windows:
    * Open Visual Studio
    * In Visual Studio, select Open → CMake, select `CMakeLists.txt`
    * From the "Select Startup Item" menu, select appropriate exe

## Contributing
* Ensure your editor uses Unix line endings
    * Use the [Line Endings Unifier][leu-dl]
      plugin for Visual Studio
    * Here's the [suggested configuration][leu-config]
* Use **clang-format** to format your source code to the project standard
    * Install a clang-format extension to your text editor:
        * [vim][clang-format-vim]
        * [Atom][clang-format-atom]
        * [Visual Studio][clang-format-vs]
        * [Visual Studio Code][clang-format-vsc]

## License
This project is licensed under the ISC license. Please see the [`LICENSE`](LICENSE) file
for details.

[clang-format-vim]: https://github.com/rhysd/vim-clang-format
[clang-format-atom]: https://atom.io/packages/clang-format
[clang-format-vsc]: https://marketplace.visualstudio.com/items?itemName=xaver.clang-format
[clang-format-vs]: https://marketplace.visualstudio.com/items?itemName=mynkow.FormatdocumentonSave
[leu-config]: https://i.imgur.com/ZONPHau.png
[leu-dl]: https://marketplace.visualstudio.com/items?itemName=JakubBielawa.LineEndingsUnifier
[VS2019-dl]: https://visualstudio.microsoft.com/thank-you-downloading-visual-studio/?sku=Community&rel=16
[vcpkg-dl]: https://github.com/microsoft/vcpkg
[brew-dl]: https://brew.sh

