
// DomainPart.cpp - Domain validation class implementation
// Written by Berty Ruan

#pragma once

#include "DomainPart.h"
#include "LocalPart.h"
#define DOT '.'
#define FIRST_INDEX 0

// Takes the address and stores into the Address data member
void DomainPart::Set(const string& address)
{
	Address = address;
}

//Checks if the domain is valid
bool DomainPart::ValidDomain()
{
	//if there is no first dot in the domain, then return false
	if (Address.find(DOT) == string::npos)  
		return false;

	//checks to see if there is two or more adjacent periods
	if (CheckAdjacentChar(DOT, Address) == false)
		return false;

	//checks to see if the string begins or ends with a period
	if (CheckDashAndDots(DOT, Address) == false)
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

	//gets the index for the first dot
	int firstDot = Address.find(DOT); 

	//gets the index for the second dot
	int nextDot = Address.find(DOT, firstDot + 1); 

	// pushes the domain part without the period into the vector 
	Subdomains.push_back(SubdomainPart(Address.substr(FIRST_INDEX, firstDot)));
	
	//while another dot exists
	while(nextDot != string::npos)  
		{

			//example:   
			//abc.def.net
			//we found abc
			//since there is another dot, we look at def
			//next dot finds the index of the second dot
			//firstDot + 1  ==> starting from d
			// nextDot - firstDot - 1 ==> 7 - 3 - 1 = 3
				//the subdomain length will be three

			//finds the next substring after the first period
			string substring = Address.substr(firstDot + 1, nextDot - firstDot - 1);

			//adds substring to vector subdomains
			Subdomains.push_back(SubdomainPart(substring)); 

			//increments to next dot. If none, nextDot equals npos
			firstDot = nextDot;
			nextDot = Address.find(DOT,firstDot + 1);
		}
	

	// take the substring after the last dot and set Tld to it. 
	// Notice that this substring was not pushed into Subdomains
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
