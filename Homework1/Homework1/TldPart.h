// TldPart.h - TldPart validation class declaration
// Written by Berty Ruan

#pragma once

#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class TldPart
{
public:
	// MUST HAVE a defualt constructor (because TldPart is a member of Domain)
	TldPart() {}

	// Takes the address and stores into the Address data member
	void Set(const string& address);

	// Returns true when the Address is valid or false otherwise
	bool IsValid();

private:
	string Address;
};