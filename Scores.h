#pragma once

#include <iostream>
#include <string>
using std::string;
using std::cout;
#include "List.h";

class score
{
public:
	score();
	~score();

	void importScore();
	void exportScore();

	void setScore(string data);
	string getScore();


private:

}