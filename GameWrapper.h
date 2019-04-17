#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H
#pragma once
#include "Cannon.h"
#include "Scores.h"
#include "Setting.h"
#include <SFML/Window.hpp>
#include "Grid.h"

enum MenuOptions { Play = 1, Instructions = 2, Settings = 3, Highscores = 4, Exit = 5};

class GameWrapper {
private:
	score scores;
	

public:
	GameWrapper();
	~GameWrapper();

	void runApp();
	void displayMenu();
	void playGame();
	int getMenuOption(int min, int max);
};

#endif