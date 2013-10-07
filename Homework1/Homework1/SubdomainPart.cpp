// SubdomainPart.cpp - Subdomain validation class implementation
// Written by Berty Ruan

#pragma once

#include "SubdomainPart.h"
#define VALID_DOMAIN_CHARS "abcefghijklmnopqrstuvwxyzADBCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_"
#define LENGTH_OF_VALID_CHARS 64
#define DASH '-'

// Takes the address and stores into the Address data member
SubdomainPart::SubdomainPart(const string& address)
{
	Address = address;
}

// Returns true when the Address is valid or false otherwise
bool SubdomainPart::IsValid()
{
	// 1. Check the size
	if (Address.size() > 265)
		return false;

	// 2. Check for valid characters
	for (int i = 0; i < Address.size(); i++)
	{
		int counter = 0;
		for (int j = 0; j < LENGTH_OF_VALID_CHARS; j++)
		{
			if (Address[i] == VALID_DOMAIN_CHARS[j])
				counter++;
		}
		if (counter != 1)
			return false;
	}


	// 3. Check for dash rule
	if(Address[0] == DASH || Address[Address.size() -1] == DASH)
		return false;

	return true;
}
