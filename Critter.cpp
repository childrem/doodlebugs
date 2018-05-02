#include "Critter.hpp"

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


Critter::Critter(char enteredLetter)
{
	setBugLetter(enteredLetter);
	age = 0;	// Age always starts at 0
}

