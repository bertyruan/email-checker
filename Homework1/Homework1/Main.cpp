//main.cpp - Email address validation program main entry point
//Written by Berrty Ruan

#include <iostream>
#include <fstream>
#include <string>
#include "Email.h"


using namespace std;

// HOMEWORK
//research email validation rules
//1.1 1.2
//think of a project to make for final project

///make stuff case insensitive 
//size is less than 254
//InValid local address
//x.
//.x
//-x
//x..x
//x--x
//space, []
//>63
//Valid domain
//A-Z,0-9,-,_
//toplevel domain ICANN
//data is coming from email.txt
	//structure of the file

//no user interaction
//research what is a valid email address
//no min. string length size

//result.txt has whether email.txt's emails are valid or invalid by indicating with 0, 1

//use file stream to read .txt documents


void main()
{
	ifstream input("Email.txt");
	ofstream output("Result.txt");

	//1. While not at the end of email.txt file

	while(!input.eof())
	{
		bool isValid = false;

		//2. Read an email address from email.txt
		string emailAddress;
		input >> emailAddress;

		Email theAddress(emailAddress);


		//3. Validate the email
		if (theAddress.IsValid() == true)
			isValid = true;


		//4. Write 0 or 1 to the Result.txt file
		output << isValid << "	"  << emailAddress << endl;

	}


	system("pause");
}


