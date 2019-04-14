#pragma once
#include<iostream>
using namespace std;
class String {

private:
	//variable to store length of string
	
	int stringLength;
	int countForTokenPtr;

	//pointer for string characters 
	char* anyString = nullptr;
	char** tokenization = nullptr;
	char* upperCased = nullptr;
	char* lowerCased = nullptr;
	char* concateString = nullptr;

public:
	//constructors
	String();
	String(const char*);
	String(const String&);
	
	//setter 
	void setAnyString(const char[]);

	//copyier
	void copyString(const String&);

	//getter 
	char* getAnyString();
	int getLengthOfString()const;
	int getCountForTokenPtr();

	//calculate the length
	int lengthOfString(const char*);


	//concatenation
	char* stringConcatenation(char*);
	char* stringConcatenation(const String&);

	//upper case
	char* stringUpperCase();
	
	//lower case
	char* stringLowerCase();

	//compare
	int stringComparing(char*);

	//tokenization
	char** stringTokenization();

	//insertion operator overloading
	friend ostream& operator<<(ostream&, String&);

	//exsertion operator overloading
	friend istream& operator>>(istream&, String&);

	//add operator overloading
	String operator+(const String&);
	
	//equal operator overloading
	void operator=(const String&);
   
	//print
	void printEveryThing(char[]);

	//deletion of dynamic allocation
	~String();
};
