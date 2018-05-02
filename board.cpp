#include "board.hpp"
#include "critter.hpp"
#include "yomu.hpp"

#include <random>
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void Board::initBoard(){

    std::cout << "Would you like to choose the size of the board?" << std::endl;
    std::cout << "1. Yes" << std::endl;
    std::cout << "2. No" << std::endl;

    int userChoice = intYomu(1, 2, "strict");

    if (userChoice == 1) {
      std::cout << "How big is the board? (Format: X by Y tiles)" << std::endl;    
      std::cout << "X: " << std::endl;
      numberOfColumns = intYomu(20);  //My input validator reads this as: "input must be 20 or greater to be valid"
      std::cout << "Y: " << std::endl;
      numberOfRows = intYomu(20);
      customBoard = true;
      
    }

    else {
      std::cout << "Okay, the board will be 20x20." << std::endl;
      numberOfColumns = 20;
      numberOfRows = 20;
    }

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
	** Setup border critters and start with empty grid
	******************************************/
	for (int row = 0; row < numberOfRows + 2; row++)
	{
		for (int col = 0; col < numberOfColumns + 2; col++)
		{
			if (row == 0 || row == numberOfRows + 1)
			{
				gameBoardPtr[row][col] = new Critter('-');	// These critters are only used to display border
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

    Critter* testCritter = new Critter('X');
   
    std::uniform_int_distribution<int> customBoardDistX(1, numberOfRows);
        std::uniform_int_distribution<int> customBoardDistY(1, numberOfColumns);
        int testRow = customBoardDistX(theTwister);
        int testCol = customBoardDistY(theTwister);
        gameBoardPtr[testRow][testCol] = testCritter; 

    //randomSpawnPoint(testCritter);
}

void Board::randomSpawnPoint(Critter* critter) 
    {   
    if (customBoard)
        {
        std::uniform_int_distribution<int> customBoardDistX(1, numberOfRows);
        std::uniform_int_distribution<int> customBoardDistY(1, numberOfColumns);
        int testRow = customBoardDistX(theTwister);
        int testCol = customBoardDistY(theTwister);
        
        //critter -> setXPosition(customBoardDistX(theTwister));
        //critter -> setYPosition(customBoardDistY(theTwister));
        }    
    else    
        {    
        std::uniform_int_distribution<int> standardBoardDist(1, 20);
        critter -> setXPosition(standardBoardDist(theTwister));
        critter -> setYPosition(standardBoardDist(theTwister));
        }  
    }
/****************************************************************************
** Description: The printBoard function is used to print the board upon
completion of each step in the simulation. The 2D array is printed in
"square" format.
****************************************************************************/
void Board::printBoard()
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

bool Board::isCustom() 
{
    return customBoard;
}

int Board::getXLimit() 
{
    return numberOfRows;
}

int Board::getYLimit()
{
    return numberOfColumns;
}
Board::~Board() {
	/****************************
	** Delete Board when finished
	****************************/
	for (int row = 0; row < numberOfRows + 2; row++)
	{
		delete[] gameBoardPtr[row]; // Free each array of Critter pointers
	}

	delete[] gameBoardPtr; // Free array of Critter pointer pointers

}
