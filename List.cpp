#include "List.h"

//Constructor
ScoreList::ScoreList()
{
	pHead = nullptr;
}

ScoreList::ScoreList(string data)
{
	pHead->mScore = data;
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
node* ScoreList::makeNode(string score)
{
	node *pMem = new node;
	pMem->mScore = score;
	pMem->mpNext = nullptr;

	return pMem;
}

//inserts items at front
void ScoreList::insert(string score)
{
	node *pMem = makeNode(score);

	if (pHead == nullptr)
	{
		pHead = pMem;
	}

	else
	{
		pMem->mpNext = pHead;
		pHead = pMem;
	}
}


void ScoreList::printList()
{
	node *pTraverse = this->pHead;

	while (pTraverse != nullptr)
	{
		cout << pTraverse->mScore << " ";

		pTraverse = pTraverse->mpNext;
	}

}