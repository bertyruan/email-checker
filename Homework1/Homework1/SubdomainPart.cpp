// SubdomainPart.cpp - Subdomain validation class implementation
// Written by Berty Ruan

#pragma once

#include "SubdomainPart.h"
#define VALID_DOMAIN_CHARS "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789-_"
#define DASH '-'
#define LARGEST_SUBDOMAIN_LENGTH_SIZE 255

// Takes the address and stores into the Address data member
SubdomainPart::SubdomainPart(const string& address)
{
	Address = address;
}

// Returns true when the Address is valid or false otherwise
bool SubdomainPart::IsValid()
{
	// 1. Check the size which can't be greater than 255
	if (Address.size() > LARGEST_SUBDOMAIN_LENGTH_SIZE)
		return false;

	// 2. Check for valid characters
	if (Address.find_first_not_of(VALID_DOMAIN_CHARS) != string::npos)
		return false;


	// 3. Check for dash rule
	if(Address[0] == DASH || Address[Address.size() -1] == DASH)
		return false;

	return true;
}
