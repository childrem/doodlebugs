#include <iostream>
using std::cin;
using std::cout;
using std::endl;

#include "Critter.hpp"


// may not need this function, it's repeat of what's found in main
/*
void createBoard(Critter** gameBoardPtr, int numberOfRows, int numberOfColumns)
{
	// Each element in array is going to point to its own array of chars
	// + 2 is to accomodate a boarder around the game board
	gameBoardPtr = new Critter*[numberOfRows + 2];	// rows

	for (int row = 0; row < numberOfRows + 2; row++)
	{
		gameBoardPtr[row] = new Critter[numberOfColumns + 2];	// columns
	}
}

*/

/****************************************************************************
** Description: The printBoard function is used to print the board upon
completion of each step in the simulation. The 2D array is printed in
"square" format.
****************************************************************************/

void printBoard(Critter*** gameBoardPtr, int numberOfRows, int numberOfColumns)
{
	if (gameBoardPtr != NULL)
	{
		for (int row = 0; row < numberOfRows + 2; row++)
		{
			for (int col = 0; col < numberOfColumns + 2; col++)
			{
				cout << gameBoardPtr[row][col]->getBugLetter() << " ";
			}

			cout << endl;
		}

		cout << endl;
	}
}

std::ostream& operator<<(std::ostream& outStream, Critter bugToPrint)
{
	outStream << bugToPrint.getBugLetter();

	return outStream;
}