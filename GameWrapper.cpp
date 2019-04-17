#include "GameWrapper.h"

GameWrapper::GameWrapper() {
}
GameWrapper::~GameWrapper() {
}

void GameWrapper::playGame() {
	
	std::fstream input;
	scores.importScore(input); // load previous high scores

	sf::Window window(sf::VideoMode(800,1000), "Clickie Boi");
	window.display();
}