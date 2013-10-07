//Email.h - function prototypes and such
//Written by Berty Ruan


#pragma once
#include <string>
#include "LocalPart.h"
#include "DomainPart.h"
using namespace std;


class Email
{
public:
	// Takes the emailAddress and stores into the Address data member
	Email(const string& emailAddress);

	// Returns true when the Address is valid or false otherwise
	bool IsValid();

private:
	// Parses the Address into Local and Domain by searching for the '@' sign
	bool Parse();

	string Address;
	LocalPart Local;
	DomainPart Domain;
};