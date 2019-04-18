#include "GameWrapper.h"

GameWrapper::GameWrapper() {
}
GameWrapper::~GameWrapper() {
}

void GameWrapper::runApp() {

	this->scores.importScore();

	bool exit = false;
	while (!exit) {

		system("cls");

		this->displayMenu();

		switch (this->getMenuOption(1, 5)) {

		case Play:
			this->playGame();
			break;

		case Instructions:
			system("cls");
			this->printInstructions();
			system("pause");
			break;

		case Settings:
			break;

		case Highscores:
			system("cls");
			this->scores.printScores();
			system("pause");
			break;

		case Exit:
			exit = true;
			this->scores.exportScore();
			break;

		}
	}
}

void GameWrapper::displayMenu() {
	std::cout << "Select an option:" << std::endl
		<< "1. Play Game" << std::endl
		<< "2. Instructions" << std::endl
		<< "3. Settings" << std::endl
		<< "4. View Highscores" << std::endl
		<< "5. Exit" << std::endl;
	
}

void GameWrapper::playGame() {

	sf::RenderWindow window(sf::VideoMode(800,1000), "Clickie Boi");

	Cannon shootyBoi(*(new sf::Vector2f(-50, -150)), sf::Color::Cyan,
		*(new sf::Vector2f(325, 750)));

	Grid grid;

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		grid.drawGrid(window);
		window.draw(shootyBoi);
		window.display();
	}
}

void GameWrapper::printInstructions() {
	std::cout << "Bubble Shooter" << std::endl
		<< "Your goal is to clear all the bubble from the screen, scoring as many points as possible." << std::endl
		<< "You shoot at them with more bubbles, and when three or more of the same color come together, they all explode." << std::endl
		<< "The cannon holds the shooter bubble, and rotates on an axis."<< std::endl
		<< "When the cannon is pointing to where you want to shoot, press the space key and the bubble will be released." << std::endl
		<< "The more bubbles you blow up with one shot, the more points you can gain." << std::endl
		<< "If your shot fails to detonate any bubbles, you are given a strike.You lose the game when you reach your fifth strike." << std::endl
		<< "Your high score will automatically be saved, and will be displayed at the end of every game." << std::endl;

}

int GameWrapper::getMenuOption(int min, int max) {
	int choice = 0;
	std::cout << "enter your choice:" << std::endl;
	std::cin >> choice;

	while (std::cin.fail()) { // user did not enter an integer
		std::cin.clear();
		std::cin.ignore();
		std::cout << "invalid input, try again:" << std::endl;
		std::cin >> choice;
	}

	while (choice < min || choice > max) { // user did not enter a valid choice
		std::cout << "invalid choice, try again:" << std::endl;

		std::cin >> choice;

		while (std::cin.fail()) { // user did not enter an integer
			std::cin.clear();
			std::cin.ignore();
			std::cout << "invalid input, try again:" << std::endl;
			std::cin >> choice;
		}
	}

	return choice;
}