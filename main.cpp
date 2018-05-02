#include "Critter.hpp"

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void printBoard(Critter*** gameBoardPtr, int numberOfRows, int numberOfColumns);

int main()
{
	Critter* testCritter = new Critter('X');

	cout << "Test critter's letter is: " << testCritter->getBugLetter() << endl;
	cout << "Test critter's starting age is: " << testCritter->getAge() << endl;

	Critter*** gameBoardPtr;
	int numberOfRows = 10;		// FOR TESTING!
	int numberOfColumns = 10;	// FOR TESTING!

	/********************************
	** Initialize the Board
	********************************/

	// Each element in array is going to point to its own array of chars
	// + 2 is to accomodate a boarder around the game board
	// USEABLE GAMESPACE IS FROM ROW 1 THROUGH NUMBER OF ROWS
	// USEABLE GAMESPACE IS FROM COL 1 THROUGH NUMBER OF COLS
	gameBoardPtr = new Critter**[numberOfRows + 2];	// rows

	for (int row = 0; row < numberOfRows + 2; row++)
	{
		gameBoardPtr[row] = new Critter*[numberOfColumns + 2];	// columns
	}

	/******************************************
	** Setup boarder critters and start with empty grid
	******************************************/
	for (int row = 0; row < numberOfRows + 2; row++)
	{
		for (int col = 0; col < numberOfColumns + 2; col++)
		{
			if (row == 0 || row == numberOfRows + 1)
			{
				gameBoardPtr[row][col] = new Critter('-');	// These critters are only used to display boarder
			}

			else if ((col == 0 && (row > 0 && row < numberOfRows + 1)) ||
				(col == numberOfColumns + 1 && (row > 0 && row < numberOfRows + 1)))
			{
				gameBoardPtr[row][col] = new Critter('|');
			}

			else
			{
				gameBoardPtr[row][col] = new Critter(' ');
			}
		}
	}

	gameBoardPtr[1][1] = testCritter;

	printBoard(gameBoardPtr, numberOfRows, numberOfColumns);


	/****************************
	** Delete Board when finished
	****************************/
	for (int row = 0;row < numberOfRows + 2; row++)		// Delete all Critter Type Objects
	{
		for (int col = 0; col < numberOfColumns + 2; col++)
		{
			delete gameBoardPtr[row][col];
		}
	}
	
	for (int row = 0; row < numberOfRows + 2; row++)
	{
		delete[] gameBoardPtr[row]; // Free each array of Critter pointers
	}

	delete[] gameBoardPtr; // Free array of Critter pointer pointers


	return 0;
}
