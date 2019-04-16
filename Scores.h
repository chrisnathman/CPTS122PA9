#pragma once

#include <iostream>
#include <string>
#include <fstream>
using std::string;
using std::fstream;
using std::cout;
#include "List.h"

class score
{
public:
	score();
	~score();

	void importScore(fstream &score);
	void exportScore(fstream &score);
	void addScore(string score);
	
private:

	ScoreList highScore;

};