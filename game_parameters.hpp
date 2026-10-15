#pragma once
#include "level_system.hpp"

using ls = LevelSystem;

struct Parameters {
    static constexpr float time_step = 1.f / 60.f;

    static constexpr const char* maze_1 = "res/levels/maze.txt";
    static constexpr const char* maze_2 = "res/levels/maze_2.txt";
    static constexpr const char* maze_3 = "res/levels/maze_3.txt";

    static inline const std::vector<std::string> mazes = {
        maze_1,
        maze_2,
        maze_3
    };
};