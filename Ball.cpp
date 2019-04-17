#include "Ball.h"
Ball::Ball(float radius, const sf::Color &c, float posX, float posY) //: sf::CircleShape(radius)
{
	this->setFillColor(c);
	this->setPosition(posX, posY);
}