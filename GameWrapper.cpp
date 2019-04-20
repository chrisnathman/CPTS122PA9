#include "GameWrapper.h"

GameWrapper::GameWrapper() {
}
GameWrapper::~GameWrapper() {
}

void GameWrapper::runApp() {

	this->scores.importScore();
	this->difficulty = 4;
	this->scorePerBall = 2;

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

		case Difficulty:
			this->setDifficulty();
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

// displays the main menu
void GameWrapper::displayMenu() {
	std::cout << "Select an option:" << std::endl
		<< "1. Play Game" << std::endl
		<< "2. Instructions" << std::endl
		<< "3. Set Difficulty" << std::endl
		<< "4. View Highscores" << std::endl
		<< "5. Exit" << std::endl;
	
}

void GameWrapper::playGame() {

	// game window
	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Clickie Boi");
	window.setPosition(sf::Vector2i(560, 0));

	// moving part of the cannon
	Cannon shootyBoi(*(new sf::Vector2f(-50, -150)), sf::Color::Cyan,
		*(new sf::Vector2f(window.getSize().x/2, window.getSize().y)));
	shootyBoi.setOrigin(-25, 0);

	// decorative cannon base
	sf::CircleShape cannonStand(80.f);
	cannonStand.setFillColor(sf::Color::Cyan);
	cannonStand.setPosition(sf::Vector2f(window.getSize().x / 2 - cannonStand.getRadius(), window.getSize().y-cannonStand.getRadius()));
	
	// ball that gets fired
	Ball ammo(25.f);
	ammo.setOrigin(ammo.getRadius(), ammo.getRadius());
	this->resetAmmo(ammo, window.getSize().x, window.getSize().y);
	bool ammoFired = true; // flag for if game should look for user input

	// grid of all balls in play except ammo
	Grid grid(difficulty);

	while (window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// waiting for user to fire
		if (!ammoFired) {
			while (window.pollEvent(event)) {
				if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
					this->fireAmmo(ammo, shootyBoi);
				}
			}
		}
		// ammo hit the grid so need to reset
		else if(ammo.isDestroyed()){
			this->resetAmmo(ammo, window.getSize().x, window.getSize().y);
			ammoFired = false;
		}
		// check position of ammo for collisions
		else {
			ammo.move(ammo.getXVel(), ammo.getYVel());
			
		}

		window.clear();

		shootyBoi.rotateCannon();

		grid.drawGrid(window);
		window.draw(cannonStand);
		window.draw(shootyBoi);
		window.draw(ammo);
		window.display();
	}
}

// resets ammo so that it is ready to be fired again
void GameWrapper::resetAmmo(Ball & ammo, int windowXSize, int windowYSize){

	ammo.setPosition(windowXSize/2, windowYSize);

	int nextAmmoColor = rand() % difficulty;
	ammo.setFillColor(Grid::samples[nextAmmoColor]);

	ammo.unDestroy();
}

// fires the ammo based on cannon angle
void GameWrapper::fireAmmo(Ball & ammo, Cannon & kanone) {
	
}

// prints out the game instructions
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

// changes possible colors and score multiplier based on selected difficulty
void GameWrapper::setDifficulty() {
	std::cout << "Select a difficulty:" << std::endl
		<< "1. Easy   (4 colors, 1x score)" << std::endl
		<< "2. Medium (5 colors, 1.5x score)" << std::endl
		<< "3. Hard   (6 colors, 2x score)" << std::endl;
	this->difficulty = getMenuOption(1, 3) + 3; // add 3 to get number of colors
	this->scorePerBall = this->difficulty - 2;
}

// gets an integer from the user between the given values, usually used for selecting menu options
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