#ifndef BALL_H
#define BALL_H
#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
public:
	Ball(float radius, const sf::Color &c, float posX, float posY);
};

#endif