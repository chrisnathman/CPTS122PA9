#ifndef GRID_H
#define GRID_H
#pragma once
#include "Ball.h"
#include <SFML/Window.hpp>

class Grid {

private:
	Ball arr[5][10];

public:
	Grid(int colors = 4);
	~Grid();

	void drawGrid(sf::RenderWindow & window);
};

#endif