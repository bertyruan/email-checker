// TldPart.cpp - TldPart validation class implementation
// Written by Berty Ruan

#pragma once

#include "TldPart.h"



// Takes the address and stores into the Address data member
void TldPart::Set(const string& address)
{
	Address = address;

	//captializes all the characters in address using the algorithm class
	transform(Address.begin(), Address.end(),Address.begin(), ::toupper);
}

// Returns true when the Address is valid or false otherwise
bool TldPart::IsValid()
{
	bool isValid = true;

	//inputing all the valid Tlds from ValidTLDs.txt
	ifstream input("ValidTLDs.txt");
	string tld;

	while(!input.eof())
	{
		input >> tld;

		//if one of the valid Tlds matches Address, return true
		if (tld == Address)
			return isValid;
	}

	return !isValid;
}
