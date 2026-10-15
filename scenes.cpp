#include "scenes.hpp"
#include "player.hpp"
#include <memory>
#include "level_system.hpp"
#include "game_parameters.hpp"
#include <iostream>

using param = Parameters;
using ls = LevelSystem;

std::size_t _maze_index = 0;

std::shared_ptr<Scene> Scenes::maze = nullptr;

void MazeScene::load() {
    std::shared_ptr<Entity> player = std::make_shared<Player>();
    _entities.push_back(player);
    reset();
}

void MazeScene::reset() {

    // Load the current maze
    ls::load_level(_file_path, 100.f);

    // Calculate its size in pixels
    unsigned int maze_width = ls::get_width() * 100;
    unsigned int maze_height = ls::get_height() * 100;

    // Resize the game window to match
    GameSystem::resize_window(maze_width, maze_height);

    // Put the player at the new maze's start
    _entities[0]->set_position(ls::get_start_position());
}

void MazeScene::update(const float& dt) {
    Scene::update(dt);
    if (ls::get_tile_at(_entities[0]->get_position()) == ls::END) {
        ++_maze_index;

        if (_maze_index < param::mazes.size()) {
            _file_path = param::mazes[_maze_index];
            reset();
        }
        else {
            std::cout << "All mazes completed!" << std::endl;
        }
       
    }
}

void MazeScene::render(sf::RenderWindow& window) {
    ls::render(window);      // Draw the maze tiles
    Scene::render(window);   // Draw the entities (including the player)
}

void MazeScene::set_file_path(const std::string& file_path) {
    _file_path = file_path;
}