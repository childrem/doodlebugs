#include "critter.hpp"

void Critter::setBugLetter(char enteredLetter)
{
	bugLetter = enteredLetter;
}

char Critter::getBugLetter()
{
	return bugLetter;
}



int Critter::getAge()
{
	return age;
}

void Critter::setYPosition(int y)
{
    position[1] = y;
}

void Critter::setXPosition(int x)
{
    position[0] = x;
}

Critter::Critter(char enteredLetter)
{
	setBugLetter(enteredLetter);
	age = 0;	// Age always starts at 0
}


