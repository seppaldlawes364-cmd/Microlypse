cmake_minimum_required(VERSION 3.10)
project(main)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(external/SFML)
add_executable(main
    src/main.cpp 
    src/game.cpp
    src/State.cpp
    src/Menu.cpp
    src/Button.cpp
    src/Slider.cpp
    src/Game.cpp
)

target_link_libraries(main PRIVATE
    sfml-graphics
    sfml-audio
    sfml-window
    sfml-system
)