#include "Grid.h"

Grid::Grid(int colors) {
	int k = 0;

	sf::Color samples[6] = { sf::Color::White, sf::Color::Yellow, sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Magenta };

	int j = 0;
	while (j < 5) // row count
	{
		// add 10 circles
		for (int i = 0; i < 10; i++)
		{
			k = rand() % colors;
			this->arr[j][i].setRadius(50);
			this->arr[j][i].setPosition(i * 100, 25 + 100 * j);
			this->arr[j][i].setFillColor(samples[k]);
		}

		j++;

	}
}
Grid::~Grid() {

}

void Grid::drawGrid(sf::RenderWindow & window) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (!this->arr[i][j].isDestroyed()) {
				window.draw(this->arr[i][j]);
			}
		}
	}
}