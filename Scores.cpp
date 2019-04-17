//ifstream infile, table;
//fstream.open("Convert.txt");
//table.open("dictionary.txt");
//string a; //convert to char;
//string b;
//while (!table.eof())
//{
//	getline(table, a, ';');
//	getline(table, b);
//	morse.insert(a[0], b);
//}
#include "Scores.h"


score::score()
{

}	
score::~score()
{

}

void score::importScore(fstream &score)
{
	if (!score.is_open())
	{
		score.open("scores.csv");
	}

	while (!score.eof())
	{
		string readString;
		node* temp_node = new node;

		//name,score
		getline(score, readString, ',');//name
		temp_node->mName = readString;

		getline(score, readString);
		temp_node->mScore = readString;

		if (score.eof()) break;
		highScore.insert(temp_node);
	}

	if (!score.is_open())score.close();

}
void score::exportScore(fstream &score)
{
	if (!score.is_open())score.open("scores.csv");
	score.clear();

	node *temp = highScore.getNode();

	while (!temp->isEmpty())
	{
		score << temp->mName << "," << temp->mScore << std::endl;
		temp = temp->mpNext;
	}

	if (!score.is_open())score.close();
}

void score::addScore(string score)
{
	string name;
	cout << "Enter your Name" << std::endl;
	std::cin >> name;
	
	node* temp = new node;
	temp->mName = name;
	temp->mScore = score;

	highScore.insert(temp);
}