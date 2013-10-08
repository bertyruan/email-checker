//LocalPart.h Local part email validation 
//Written by Berty Ruan

#pragma once

#include <string>
#include "CheckAdjacentChar.h"
using namespace std;

class LocalPart
{
public:
	// MUST HAVE a defualt constructor (because LocalPart is a member of Email)
	LocalPart() {}

	// Takes the address and stores into the Address data member
	void Set(const string& address);

	// Returns true when the Address is valid or false otherwise
	bool IsValid();

	// Made public because DomainPart needs the code
	

private:
	string Address;

};


//Has to have a defalut constructor becasuse LocalPart  object is a data member of an Email class. 
//but the constructor dosen't do anything