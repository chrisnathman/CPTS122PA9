#include "Grid.h"

sf::Color Grid::samples[]= { sf::Color::White, sf::Color::Yellow, sf::Color::Red, sf::Color::Blue,
										  sf::Color::Green, sf::Color::Magenta };

Grid::Grid(int colors) {

	int k = 0;

	this->rows = ((WINDOW_HEIGHT - (4 * WINDOW_BORDER)) / 100);
	this->columns = (WINDOW_WIDTH - (2 * WINDOW_BORDER)) / 50;

	int j = 0;
	while (j < this->rows) // row count
	{
		std::vector<Ball> newVector;
		// add 10 circles
		for (int i = 0; i < this->columns; i++)
		{

			k = rand() % colors;

			Ball newBall(25, Grid::samples[k], (i * 50) + (WINDOW_BORDER) + 25, (j * 50) + (3 * WINDOW_BORDER) + 25);
			newBall.setOrigin(newBall.getRadius(), newBall.getRadius());
			newVector.push_back(newBall);
		}
		this->arr.push_back(newVector);
		j++;

	}
}
Grid::~Grid() {
	
}

void Grid::drawGrid(sf::RenderWindow & window) {
	for (int i = 0; i < this->rows; i++) {
		for (int j = 0; j < this->columns; j++) {
			if (!this->arr[i][j].isDestroyed()) {
				window.draw(this->arr[i][j]);
			}
		}
	}
}