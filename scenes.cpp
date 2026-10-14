#include "scenes.hpp"
#include "player.hpp"
#include <memory>

std::shared_ptr<Scene> Scenes::maze = nullptr;

void MazeScene::load() {
    std::shared_ptr<Entity> player = std::make_shared<Player>();
    _entities.push_back(player);
    reset();
}

void MazeScene::reset() {
    _entities[0]->set_position(sf::Vector2f(100.f, 100.f));
}

void MazeScene::update(const float& dt) {
    Scene::update(dt);
}

void MazeScene::render(sf::RenderWindow& window) {
    Scene::render(window);
}

void MazeScene::set_file_path(const std::string& file_path) {
    _file_path = file_path;
}