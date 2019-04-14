


#include "pch.h"
#include<iostream>
#include "String.h"

using namespace std;

//constructors
String::String() {
	anyString = nullptr;
	//stringLength = 0;
}
String::String(const char* aS) {

	setAnyString(aS);

}
String::String(const String& obj) {
	
	if (this->anyString != nullptr)
		delete[] this->anyString;

	this->anyString = new char[obj.stringLength + 1];

	this->stringLength = obj.stringLength;
	for (int i = 0; i <= obj.stringLength; i++) {
		this->anyString[i] = obj.anyString[i];
	}

	this->anyString[obj.stringLength] = '\0';
}

//string setter
void String::setAnyString(const char aS[]) {

	if (anyString != nullptr)
		delete[] anyString;

	anyString = new char[lengthOfString(aS) + 1];

	stringLength = lengthOfString(aS);
	for (int i = 0; i <= lengthOfString(aS); i++) {
		anyString[i] = aS[i];
	}

	anyString[lengthOfString(aS)] = '\0';
}

//copy string
void String::copyString(const String& src) {
	if (this->stringLength != src.stringLength) {

		this->anyString = new char[src.stringLength + 1];
		
		for (int i = 0; i <= src.stringLength; i++) {
			this->anyString[i] = src.anyString[i];
		}
	}
	else {
		for (int i = 0; i <= src.stringLength; i++) {
			this->anyString[i] = src.anyString[i]; 
		}
	}
	
}

//string getter
char* String::getAnyString() {
	return anyString;
}

int String::getLengthOfString()const {
	return stringLength;
}

//to get countForTokenPtr
int String::getCountForTokenPtr() {
	return countForTokenPtr;
}

//length calculator of desired string
int String::lengthOfString(const char aS[]) {
	int  i = 0;
	while (aS[i] != '\0')
		i++;
	
	return i;
}

//upper case
char* String::stringUpperCase() {

	if (upperCased != nullptr)
		delete[] upperCased;
	
	upperCased = new char[lengthOfString(anyString)+1];

	for (int i = 0; i <= lengthOfString(anyString); i++) {
		
		for (int j = 0; j < 26; j++) {

			if (anyString[i] == j + 97) {
				upperCased[i] = j + 65;
				break;
			}
			else 
				upperCased[i] = anyString[i];
		}
	}
	
	return upperCased;
}

//lower case
char* String::stringLowerCase() {

	if (lowerCased != nullptr)
		delete[] lowerCased;

	lowerCased = new char[lengthOfString(anyString) + 1];

	for (int i = 0; i <= lengthOfString(anyString); i++) {
		
		for (int j = 0; j < 26; j++) {

			if (anyString[i] == j + 65) {
				lowerCased[i] = j + 97;
				break;
			}
			else
				lowerCased[i] = anyString[i];
		}
	}
	
	return lowerCased;
}

//compare
int String::stringComparing(char* sS) {

	int lengthOfFirstString = lengthOfString(anyString);
	int lengthOfSecondString = lengthOfString(sS);
	
	if (lengthOfFirstString < lengthOfSecondString)
		return 1;

	else if (lengthOfFirstString > lengthOfSecondString)
		return -1;
		
	else if (lengthOfFirstString == lengthOfSecondString) {
		
		for (int i = 0; i < lengthOfFirstString; i++) {
			
			if (anyString[i] > sS[i]) {
				return -1;
			}

			else if (sS[i] > anyString[i]) {
				return 1;
			}

			else
				return 0;
		}
	}
}

//tokenization
char** String::stringTokenization() {
	
	if (tokenization != nullptr)
		delete tokenization;

	countForTokenPtr = 1;
	for (int i = 0; i <= lengthOfString(anyString); i++) {
		
		if (anyString[i] == 32 && anyString[i + 1] != 32)
			countForTokenPtr++;

	}
		
	tokenization = new char*[countForTokenPtr];
	
	for (int i = 0; i < countForTokenPtr; i++) {
		tokenization[i] = new char[28];
	}

	int o = 0,s=0;
	for (int i = 0; i < countForTokenPtr; i++) {

		for (int j = 0; ;) {
			if (anyString[o] == 32) {
				while(anyString[o+1] == 32)
					o++;
				j++;
				break; 
			}
			else {
				if (o > lengthOfString(anyString)) break;
				tokenization[i][j] = anyString[o];
				o++;
				s = j;
				j++;
			}
		}

		tokenization[i][s+1] = '\0';
		if (o > lengthOfString(anyString))
			break;
		o++;
	}
	
	return tokenization;
}

//concatenation
char* String::stringConcatenation(const String& obj) {
	
	int completeLength = this->stringLength + obj.stringLength;

	if (concateString != nullptr)
		delete[] concateString;

	concateString = new char[completeLength + 1];

	//concating both strings
	int j = 0;
	for (int i = 0; i <= completeLength; i++) {

		if (i <= this->stringLength)
			concateString[i] = anyString[i];

		else if (i > this->stringLength) {
			concateString[this->stringLength + j] = obj.anyString[j];
			j++;
		}
	}

	concateString[completeLength] = '\0';

	return concateString;

}


char* String::stringConcatenation(char* sS) {

	int lengthOfFirstString = lengthOfString(anyString);
	int lengthOfSecondString = lengthOfString(sS);

	int completeLength = lengthOfFirstString + lengthOfSecondString;

	if (concateString != nullptr)
		delete[] concateString;

	concateString = new char[completeLength + 1];

	//concating both strings
	int j = 0;
	for (int i = 0; i <= completeLength; i++) {

		if (i <= lengthOfFirstString)
			concateString[i] = anyString[i];

		else if (i > lengthOfFirstString) {
			concateString[lengthOfFirstString + j] = sS[j];
			j++;
		}
	}

	concateString[completeLength] = '\0';

	return concateString;

}


//add operator overloading
String String::operator+(const String& obj) {
	
	String temp;
	
	temp.stringLength = this->stringLength + obj.stringLength;
	
	if (temp.anyString != nullptr)
		delete[] temp.anyString;

	temp.anyString = new char[temp.stringLength + 1];


	int j = 0;
	for (int i = 0; i <= temp.stringLength; i++) {
		
		if (i <= this->stringLength)
			temp.anyString[i] = this->anyString[i];

		else if (i > this->stringLength) {
			temp.anyString[this->stringLength + j] = obj.anyString[j];
			j++;
		}
	}

	temp.anyString[temp.stringLength] = '\0';
	
	return temp;

}

//= operator overloading
void String::operator=(const String& obj) {

	if (this->anyString != nullptr)
		delete[] this->anyString;

	this->anyString = new char[obj.stringLength + 1];
	this->stringLength = obj.stringLength;

	for (int i = 0; i <= obj.stringLength; i++) {

		this->anyString[i] = obj.anyString[i];

	}

	this->anyString[obj.stringLength] = '\0';
	   	 
}

//insertion operator overloading
ostream& operator<<(ostream& output, String& obj) {
	output << obj.getAnyString();
	return output;
}

//insertion operator overloading
istream& operator>>(istream& input, String& obj) {
	input >> obj.anyString;
	obj.anyString[obj.stringLength] = '\0';
	return input;
}


//to print every thing
void String::printEveryThing(char sS[]) {

		cout << endl << getAnyString() << endl;
		
		stringTokenization();
		cout << endl;
		for (int i = 0; i < getCountForTokenPtr(); i++) {

			for (int k = 0; stringTokenization()[i][k] != '\0'; k++) {

				cout << stringTokenization()[i][k];
			}

			cout << endl;
		}
		
		stringConcatenation(sS);
		
		cout << endl;
		cout << "\nUpper Cased string: \n"
			<< stringUpperCase() << endl;
		
		cout << endl;
		cout << "\nLower Cased string: \n"
			<< stringLowerCase() << endl;
		
		cout << "\nThe concate/combined string is: \n"
			<< stringConcatenation(sS)
			<< "\n\nThe complete length of concate/combined string is "
			<< lengthOfString(stringConcatenation(sS)) << endl;
		
		if (stringComparing(sS) == 0)
			cout << "\nBoth strings are equal.\n";
		
		else if (stringComparing(sS) == 1)
			cout << "\nSecond string is greater than first string.\n";
		
		else if (stringComparing(sS) == -1)
			cout << "\nFirst string is greater than second string.\n";
		
		cout << "\nThe length of test string is "
			<< stringLength << " characters.\n";
}

//deleting dynamic allocation
String :: ~String() {
	delete[] anyString;
	for (int i = 0; i < countForTokenPtr; i++)
		delete[] tokenization[i];
	delete[] tokenization;
	delete[] upperCased;
	delete[] lowerCased;
	delete[] concateString;
}