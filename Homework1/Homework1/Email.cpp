//Email.cpp - Email Validation class function declarations
//Written by Berty Ruan

#include "Email.h"

// Takes the emailAddress and stores into the Address data member
Email::Email(const string& emailAddress)
{
	Address = emailAddress;
}

// Parses the Address into Local and Domain by searching for the '@' sign
bool Email::Parse()
{
	// 1. Find the index of '@'
	int atIndex = Address.find('@');

	// 2. Was '@' found?
	//npos means the largest value. at unsigned int, npos will be the largest signed int if atIndex is -1
	if ( atIndex == string::npos )
		return false;

	// 3. Set the Local with the substring corresponding to the local part
	Local.Set(Address.substr(0, atIndex));

	// 4. Set the Domain
	Domain.Set(Address.substr(atIndex + 1));

	return true;
}

// Returns true when the Address is valid or false otherwise
bool Email::IsValid()
{
	return
		// Parse email into Local and Domain
		Parse() &&
		Local.IsValid() &&
		Domain.IsValid();
}



//1.Parses email Address into LocalPart and Domain
//2.LocalPart must be valid
//3.Domain must be valid

