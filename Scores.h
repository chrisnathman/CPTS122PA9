#pragma once

#include <iostream>
#include <string>
using std::string;
using std::fstream;
using std::cout;
#include "List.h";

class score
{
public:
	score();
	~score();

	void importScore(fstream score);
	void exportScore(fstream score);

	void setScore(string data);
	string getScore();

	
private:

	ScoreList highScore;

};