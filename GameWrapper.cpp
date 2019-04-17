#include "GameWrapper.h"

GameWrapper::GameWrapper() {
}
GameWrapper::~GameWrapper() {
}

void GameWrapper::playGame() {
	
	scores.importScore(); // load previous high scores

	sf::RenderWindow window(sf::VideoMode(800,1000), "Clickie Boi");

	Grid g1;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		g1.drawGrid(window);

		window.display();
	}
}