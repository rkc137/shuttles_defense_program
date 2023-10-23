#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class ship : public sf::Drawable, public sf::Transformable
{
public:
    ship();
    void update(float delta);
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

protected:
    sf::Vector2f velocity;
    sf::Texture texture;
    sf::Sprite sprite;
};