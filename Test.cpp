#include "Test.h"

void Test::testAddScore() {
	score scores;
	scores.addScore("100");
	scores.addScore("200");
	scores.addScore("50");
	scores.addScore("75");
	scores.printScores();
}

void Test::testExportScores() {
	score scores;
	scores.addScore("100");
	scores.addScore("50");
	scores.addScore("75");
	scores.addScore("200");
	scores.exportScore();
}

void Test::testImportScores() {
	score scores;
	scores.importScore();
	scores.printScores();
}