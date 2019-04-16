#pragma once

#include <iostream>
#include <string>
using std::string;
using std::cout;


struct node
{
	string mScore;
	node *mpNext;
};




class ScoreList
{
public:
	ScoreList();//constructor for linked list
	ScoreList(string data);//constructor for linked list
	~ScoreList();
	node* makeNode(string score);//creates node for list
	void insert(string score);//insert items into list
	void printList();
	

private:
	node *pHead;

};
