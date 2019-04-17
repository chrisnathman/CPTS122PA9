#ifndef GRID_H
#define GRID_H
#pragma once
#include "Ball.h"
#include <SFML/Window.hpp>

class Grid {

private:
	std::vector<sf::CircleShape> myvector;

public:
	Grid();
	~Grid();

	void drawGrid(sf::RenderWindow & window);
};

#endif