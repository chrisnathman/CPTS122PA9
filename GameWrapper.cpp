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

		window.display();
	}
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