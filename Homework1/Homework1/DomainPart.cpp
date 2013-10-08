
// DomainPart.cpp - Domain validation class implementation
// Written by Berty Ruan

#pragma once

#include "DomainPart.h"
#define DOT '.'
#define TWO_DOTS '..'
#define FIRST_INDEX 0

// Takes the address and stores into the Address data member
void DomainPart::Set(const string& address)
{
	Address = address;
}

//Checks if the domain is valid
bool DomainPart::ValidDomain()
{
	if(Address.find_first_of("..") == string::npos) //if there are dots next to each other
		return false;

	if (Address.find(".") == string::npos)  //if there is no first dot, then return false
		return false;

	if (Address.find(DOT) == 0 || Address.find(DOT, Address.size() - 1 ) != string::npos) //if there is a dot at the beginning or end of the domain 
		return false;

	return true;
}


// Parses the Address into Subdomains and Tld
bool DomainPart::Parse()
{
	// Check for valid domain
	if (ValidDomain() == false)
		return false;


	// Looking for dots

	int firstDot = Address.find(DOT); //gets the index for the first dot
	int nextDot = Address.find(DOT, firstDot + 1); //gets the index for the second dot


	Subdomains.push_back(SubdomainPart(Address.substr(FIRST_INDEX, firstDot - 1)));
	// put the domain part into the vector, but do not include the dot


	while(nextDot != string::npos)  //while there is another dot
		{

			//example:   
			//abc.def.net
			//we found abc
			//since there is another dot, we look at def
			//next dot finds the index of the second dot
			//firstDot + 1  ==> starting from d
			// nextDot - firstDot - 1 ==> 7 - 3 - 1 = 3
				//the subdomain length will be three


			string substring = Address.substr(firstDot + 1, nextDot - firstDot - 1);

			Subdomains.push_back(SubdomainPart(substring)); 
			firstDot = nextDot;
			nextDot = Address.find(DOT,firstDot + 1);


		}
	

	// Use the Set() function to populate TldPart

	Tld.Set(Address.substr(Address.find_last_of(DOT) + 1));

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