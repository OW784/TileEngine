#include "entity.hpp"
#include "level_system.hpp"

using ls = LevelSystem;

bool valid_move(sf::Vector2f pos) {
	float maze_width = ls::get_width() * 100.f;
	float maze_height = ls::get_height() * 100.f;

	if (pos.x < 0 || pos.x >= maze_width ||
		pos.y < 0 || pos.y >= maze_height) {
		return false;
	}

	return ls::get_tile_at(pos) != ls::WALL;
}

Entity::Entity(std::unique_ptr<sf::Shape> s) : _shape(std::move(s)){}

const sf::Vector2f Entity::get_position() { return _position; }

void Entity::set_position(const sf::Vector2f& pos) {
	_position = pos;
	_shape->setPosition(sf::Vector2f(_position));
}

void Entity::move(const sf::Vector2f& pos) { 
	sf::Vector2f new_position = _position + pos;

	if (valid_move(new_position)) {
		set_position(new_position);
	}
}

void Entity::update(const float& dt) {}