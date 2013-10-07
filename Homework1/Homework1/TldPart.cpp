// TldPart.cpp - TldPart validation class implementation
// Written by Berty Ruan

#pragma once

#include "TldPart.h"



// Takes the address and stores into the Address data member
void TldPart::Set(const string& address)
{
	Address = address;
	transform(Address.begin(), Address.end(),Address.begin(), ::toupper);
}

// Returns true when the Address is valid or false otherwise
bool TldPart::IsValid()
{
	bool isValid = true;
	ifstream input("ValidTLDs.txt");
	string tld;

	while(!input.eof())
	{
		input >> tld;

		if (tld == Address)
			return isValid;
	}


	// Check against the list of ICAN domains

	return !isValid;
}
