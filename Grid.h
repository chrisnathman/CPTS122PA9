#ifndef GRID_H
#define GRID_H
#pragma once
#include "Ball.h"
#include <SFML/Window.hpp>
#include <vector>
#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 800
#define WINDOW_BORDER 25

class Grid {

	

private:
	std::vector<std::vector<Ball>> arr;
	int rows;
	int columns;

public:
	Grid(int colors = 4);
	~Grid();

	static sf::Color samples[6];

	void drawGrid(sf::RenderWindow & window);
};

#endif