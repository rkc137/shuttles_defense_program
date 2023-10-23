#include "ship.hpp"

ship::ship()
{
    if(!texture.loadFromFile("res/base_ship.png"))
        std::cout << "\nbaseship load fall\n";
    sf::Vector2u s_size = texture.getSize();

    sprite.setTexture(texture);
    sprite.setOrigin(s_size.x / 2, s_size.y / 2);

    velocity = {100, 100};
}

void ship::update(float delta)
{
    move(velocity * delta);
    sprite.setPosition(this->getPosition());
}

void ship::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sprite, states);
}