// LocalPart.cpp - LocalPart validation class implementation
// Written by Berty Ruan
#pragma once

#include "LocalPart.h"
#define INVALID_CHARACTERS ":<>\" (),;[]\|"
#define LENGTH_OF_INVALID_CHARACTERS 12
#define DOT '.'
#define SHORT_DASH '-'
#define LONG_DASH '_'

//x.
//.x
//-x
//x..x
//x--x
//space, []
//>63

// Takes the address and stores into the Address data member
void LocalPart::Set(const string& address)
{
	Address = address;
}


bool LocalPart::CheckAdjacentDuplicates(const char character) const
{
	bool isInvalid = false;

	int dot = Address.find(character);

	while(dot != string::npos)
	{
		if (Address.find(character, dot + 1) == (dot + 1))
			return isInvalid;
		else
			dot = Address.find(character, dot + 1);
	}

	return !isInvalid;
}

// Returns true when the Address is valid or false otherwise
bool LocalPart::IsValid()
{

	bool isInvalid = false;
	// 1. Check the length: must be 1..64

	if (Address.size() < 1 || Address.size() > 64)
		return isInvalid;


	// 2. Check for valid characters
	//Address.find_first_not_of()

	for (int i = 0; i < Address.size(); i++)
	{
		for (int j = 0; j < LENGTH_OF_INVALID_CHARACTERS; j++)
		{
			if (Address[i] == INVALID_CHARACTERS[j])
				return isInvalid;
		}
	}


	// 3. Check the dot rule


	if (CheckAdjacentDuplicates(DOT) == false)
		return isInvalid;


	// 4. Check dash rule

	if (CheckAdjacentDuplicates(SHORT_DASH) == false)
		return isInvalid;

	if (CheckAdjacentDuplicates(LONG_DASH) == false)
		return isInvalid;


	return !isInvalid;
}
