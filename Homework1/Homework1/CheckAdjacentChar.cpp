//CheckAdjacentChar.cpp - checks for .. and -- in local and domain parts
//Written by Berty Ruan

#include "CheckAdjacentChar.h"

bool CheckAdjacentChar(const char character, const string address)
{
    unsigned int startPosition = 0;
	int characterIndex = address.find(character, startPosition);
	while(address.find(character, characterIndex) != (string::npos))
	{			
		if (startPosition >= address.size())
				return true;
		else 
			if(address[characterIndex + 1 ] == address[characterIndex])
		{
			return false;
		}

		startPosition = characterIndex + 1;	
		characterIndex = address.find(character, startPosition);
	}

	return true;
}