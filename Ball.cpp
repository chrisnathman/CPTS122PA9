#include "Ball.h"


Ball::Ball() : sf::CircleShape(50){
	this->destroyed = false;
}
Ball::Ball(float radius, const sf::Color &c, float posX, float posY) : sf::CircleShape(radius)
{
	this->destroyed = false;
	this->setFillColor(c);
	this->setPosition(posX, posY);
}

bool Ball::isDestroyed() {
	return this->destroyed;
}

void Ball::destroy() {
	this->destroyed = true;
}