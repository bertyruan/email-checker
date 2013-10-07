// SubdomainPart.h - SubdomainPart validation class declaration
// Written by Berty Ruan

#pragma once


#include <string>
using namespace std;

class SubdomainPart
{
public:
	// Takes the address and stores into the Address data member
	SubdomainPart(const string& address);

	// Returns true when the Address is valid or false otherwise
	bool IsValid();

private:
	string Address;
};


//check size, must be between 1 and 64
//check the dash rule; make a function, bool CheckRule(const string& text, char symbol)
//check for valid characters