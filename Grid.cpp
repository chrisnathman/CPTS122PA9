#include "Grid.h"

Grid::Grid() {
	int k = 0;

	sf::Color samples[6] = { sf::Color::White, sf::Color::Yellow, sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Magenta };

	int j = 0;
	while (j < 5) // row count
	{
		// add 10 circles
		for (int i = 0; i < 10; i++)
		{
			k = ((rand() % 5) + 1);

			sf::CircleShape shape(50);
			// draw a circle every 100 pixels
			shape.setPosition(i * 100, 25 + 100 * j);
			shape.setFillColor(samples[k]);

			// copy shape to vector
			myvector.push_back(shape);
		}

		j++;

	}
}
Grid::~Grid() {

}

void Grid::drawGrid(sf::RenderWindow & window) {
		//draw shapes
		// iterate through vector
		for (std::vector<sf::CircleShape>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		{
			// draw all circles
			window.draw(*it);
		}
}