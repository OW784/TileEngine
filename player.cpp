#include "player.hpp"
#include "entity.hpp"

using namespace sf;
using namespace std;


void Player::update(const float& dt) {
    if (Keyboard::isKeyPressed(Keyboard::A)) {
        move(Vector2f(-_speed * dt, 0.f));
    }
    if (Keyboard::isKeyPressed(Keyboard::D)) {
        move(Vector2f(_speed * dt, 0.f));
    }
    if (Keyboard::isKeyPressed(Keyboard::W)) {
        move(Vector2f(0.f, -_speed * dt));
    }
    if (Keyboard::isKeyPressed(Keyboard::S)) {
        move(Vector2f(0.f, _speed * dt));
    }
    
        Entity::update(dt);
}

Player::Player()
    : Entity(make_unique<CircleShape>(_radius)) {
    _shape->setFillColor(Color::Magenta);
    _shape->setOrigin(sf::Vector2f(_radius, _radius));
}

void Player::render(sf::RenderWindow& window) const {
    window.draw(*_shape);
}