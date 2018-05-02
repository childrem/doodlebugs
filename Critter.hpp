#ifndef CRITTER_HPP
#define CRITTER_HPP

#include <iostream>

class Critter
{
private:
	char bugLetter;		// X in doodlebug class, O in ant class
	int age;		// Increments each step. Used to determine breeding and death
	

public:

	void setBugLetter(char);
	char getBugLetter();

	int getAge();

	Critter(char);		// Constructor sets letter and step number variable values
	Critter()
	{
		age = 0;	// All bugs start at age 0
	}

	virtual void move()
	{
		// To be overridden in derived classes
	}

	virtual void breed()
	{
		// To be overridden in derived classes
	}


	friend std::ostream& operator<<(std::ostream&, Critter);


};

#endif