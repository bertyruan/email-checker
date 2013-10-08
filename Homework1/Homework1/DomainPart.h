//Domain.h Validates the Domain part in the email address
//Written by Berty Ruan


#pragma once
#include <string>
#include <vector>
#include "SubdomainPart.h"
#include "TldPart.h"

using namespace std;


class DomainPart
{
public:
	// MUST HAVE a defualt constructor (because DomainPart is a member of Email)
	DomainPart() {}

	// Takes the address and stores into the Address data member
	void Set(const string& address);

	// Returns true when the Address is valid or false otherwise
	bool IsValid();

private:
	// Parses the Address into Subdomains and Tld
	bool Parse();

	// Calls IsValid() for each Subdomain
	bool SubdomainsAreValid();

	bool ValidDomain();

	string Address;
	vector<SubdomainPart> Subdomains;
	TldPart Tld;
};