#include "List.h"

//Constructor
ScoreList::ScoreList()
{
	pHead = nullptr;
}

ScoreList::ScoreList(string name, string score)
{
	pHead->mScore = score;
	pHead->mName = name;
	pHead = nullptr;
}


ScoreList::~ScoreList()
{
	node* temp = this->pHead;
	while (temp != nullptr) {
		node* next = temp->mpNext;
		delete temp;
		temp = next;
	}

	this->pHead = nullptr;

}

//creates a node to be inserted into list
node* ScoreList::makeNode(string score, string name)
{
	node *pMem = new node;
	pMem->mScore = score;
	pMem->mName = name;
	pMem->mpNext = nullptr;

	return pMem;
}

//inserts items at front
void ScoreList::insert(node *newnode)
{
	if (pHead == nullptr)
	{
		pHead = newnode;
	}

	else
	{
		newnode->mpNext = pHead;
		pHead = newnode;
	}
}


void ScoreList::printList()
{
	node *pTraverse = this->pHead;
	int i = 1;
	while (pTraverse != nullptr)
	{
		cout <<i<<") "<< pTraverse->mName << " "<<pTraverse->mScore <<std::endl;
		i++;

		pTraverse = pTraverse->mpNext;
	}

}

bool ScoreList::isEmpty()
{
	if (pHead == nullptr)
	{
		return true;
	}
	return false;
}

node* ScoreList::getNode()
{
	return pHead;
}

bool node::isEmpty()
{
	if (this->mName[0] == '\0')return true;
	return false;
}

node::node()
{
	mScore[0] = '\0';
	mName[0] = '\0';
	mpNext = nullptr;
}