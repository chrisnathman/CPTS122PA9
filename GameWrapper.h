#ifndef GAMEWRAPPER_H
#define GAMEWRAPPER_H
#pragma once
#include "Ball.h"
#include "Cannon.h"
#include "Scores.h"
#include "Setting.h"
#include <SFML/Window.hpp>

class GameWrapper {
private:
	score scores;
	

public:
	GameWrapper();
	~GameWrapper();

	void playGame();
};

#endif