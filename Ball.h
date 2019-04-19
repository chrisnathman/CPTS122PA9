#ifndef BALL_H
#define BALL_H
#pragma once

#include <SFML/Graphics.hpp>

class Ball : public sf::CircleShape
{
private:
	bool destroyed; // used to determine what balls in the grid have been destroyed

public:
	Ball(float radius = 50.f);
	Ball(float radius, const sf::Color &c, float posX, float posY);

	bool isDestroyed();
	void destroy();
	void unDestroy();
};

#endif