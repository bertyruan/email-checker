// LocalPart.cpp - LocalPart validation class implementation
// Written by Berty Ruan
#pragma once

#include "LocalPart.h"
#define VALID_CHARACTERS "-_$.'+0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define DOT '.'
#define DASH '-'
#define SMALLEST_LOCAL_LENGTH_SIZE 1
#define LARGEST_LOCAL_LENGTH_SIZE 64


// Takes the address and stores into the Address data member
void LocalPart::Set(const string& address)
{
	Address = address;
}


// Returns true when the Address is valid or false otherwise
bool LocalPart::IsValid()
{

	// 1. Check the length: must be 1..64
	if (Address.size() < SMALLEST_LOCAL_LENGTH_SIZE || Address.size() > LARGEST_LOCAL_LENGTH_SIZE)
		return false;


	// 2. Check for valid characters
	//Address.find_first_not_of()
	if(Address.find_first_not_of(VALID_CHARACTERS) != string::npos)
		return false;


	// 3. Check the dot and dash rule
	if( CheckAdjacentChar(DOT, Address) == false || CheckAdjacentChar(DASH, Address) == false)
		return false;

	if (CheckDashAndDots(DOT, Address) == false || CheckDashAndDots(DASH, Address) == false)
		return false;


	return true;
}
