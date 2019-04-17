#include "GameWrapper.h"


int main(int argc, char *argv[])
{
	srand(time(NULL));

	GameWrapper g;
	g.playGame();
	return 0;
}


/*
Number of Ball colors 5| V2 add option to lower or increase color number
Rows need to alternate maybe have function evenRow...oddRow.
Have score life update on bottom right, with balls lift on bottom left



*/