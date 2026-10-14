#pragma once
#include "entity.hpp"
#include <SFML/Graphics.hpp>


class Player : public Entity {
public:
	void update(const float& dt) override;
	Player();
	void render(sf::RenderWindow& window) const override;

private:
	static constexpr float _radius = 25.f;
	static constexpr float _speed = 200.f;
};