//CheckAdjacentChar.cpp - checks for .. and -- in local and domain parts. Also checks for . and - that are at the
	//beginning or end of a part
//Written by Berty Ruan

#include "CheckChar.h"

bool CheckAdjacentChar(const char character, const string address)
{
    unsigned int startPosition = 0;

	//find the first occurence of character
	int characterIndex = address.find(character, startPosition);

	//while there is a character that was not searched through
	while(address.find(character, characterIndex) != (string::npos))
	{	
		//makes sure the index doesn't exceed the size of the address string
		if (startPosition >= address.size())
				return true;
		else
			//checks to see if there is a character next to the current character
			if(address[characterIndex + 1 ] == address[characterIndex])
				return false;
		
		//increment
		startPosition = characterIndex + 1;	
		characterIndex = address.find(character, startPosition);
	}


	return true;
}

bool CheckDashAndDots(const char character, const string address)
{
	//if there is a dot at the beginning or end of the domain 
	if (address.find(character) == 0 || address.find(character, address.size() - 1 ) != string::npos) 
		return false;

}