
// DomainPart.cpp - Domain validation class implementation
// Written by Berty Ruan

#pragma once

#include "DomainPart.h"
#define DOT '.'
#define FIRST_INDEX 0

// Takes the address and stores into the Address data member
void DomainPart::Set(const string& address)
{
	Address = address;
}

// Parses the Address into Subdomains and Tld
bool DomainPart::Parse()
{
	// Looking for dots

	int firstDot = Address.find(DOT);
	int secondDot = Address.find(DOT, firstDot + 1);

	if (firstDot == string::npos)
		return false;
	else
	{Subdomains.push_back(SubdomainPart(Address.substr(FIRST_INDEX, firstDot)));}


	while(secondDot != string::npos)
		{
			if(Address[secondDot + 1] != '\0')   //dot is the last character in the domain -> invalid domain part
				return false;

			int nextDot = Address.find(DOT, secondDot + 1);

			if (nextDot != string::npos)
			{
			Subdomains.push_back(SubdomainPart(Address.substr(firstDot + 1, secondDot - firstDot - 1))); 
			firstDot = secondDot;
			secondDot = Address.find(DOT,firstDot + 1);
			}
			else
			{
			Subdomains.push_back(SubdomainPart(Address.substr(firstDot + 1))); 
			firstDot = secondDot;
			secondDot = Address.find(DOT,firstDot + 1);
			break;
			}

		}
	

	// Use the Set() function to populate TldPart

	int lastDot = Address.find_last_of(DOT) + 1;

	Tld.Set(Address.substr(lastDot));

	return true;
}

// Calls IsValid() for each Subdomain
bool DomainPart::SubdomainsAreValid()
{
	for ( unsigned int i = 0; i < Subdomains.size(); i++ )
		if ( !Subdomains[i].IsValid() )
			return false;

	return true;
}

// Returns true when the Address is valid or false otherwise
bool DomainPart::IsValid()
{
	return
		// Parse Address into Subdomains and Tld
		Parse() &&
		SubdomainsAreValid() &&
		Tld.IsValid();
}
//Populate TLD from the last dot until the end of the Address goes into Tld