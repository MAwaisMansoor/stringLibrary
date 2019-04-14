#include "pch.h"
#include <iostream>
#include "String.h"
#include <windows.h>

using namespace std;

//String class
void stringClass() {
	String S1("This IS A TesT StrINg");
	String S2(S1), S3("This is the copied string");
	String S4, S5("Insertion operator overloaded");
		S4 = S1 + S3;
	
	char secondString[100] = "This IS the SeConD StrING";
	cout << "Enter a string: ";
	cin >> S5;
	cout << S5 << endl;

	cout<<S1.getAnyString()<<endl
		<<S3.getAnyString()<<endl
		<< S4.getAnyString()<<endl
		<< S4.getLengthOfString();
	int menu;

	
	
label:	cout << "\nEnter\n\
	1 for test string\n\
	2 for tokenization\n\
	3 for concatenation\n\
	4 for upper case string\n\
	5 for lower case string\n\
	6 for comparison of strings\n\
	7 for length of test string\n\
	8 to print every thing\n\
	9 to exit: ";
	
	cin >> menu;
	
	//validating user input
	while (menu < 1 || menu > 9) {
		
		cout << "Please! enter valid input: ";
		cin >> menu;
	}
	
	switch (menu) {

	case 1:
		cout << endl << S1.getAnyString() << endl;
		break;
	
	case 2:
		S1.stringTokenization();
		cout << endl;
		for (int i = 0; i < S1.getCountForTokenPtr(); i++) {

			for (int k = 0; S1.stringTokenization()[i][k] != '\0'; k++) {

				cout << S1.stringTokenization()[i][k];
			}

			cout << endl;
		}

		break;
	
	case 3:
		cout << "\nThe concate/combined string is: \n"
		<< S1.stringConcatenation(S4) 
		<< "\nThe complete length of concate/combined string is "
		<< S1.lengthOfString(S1.stringConcatenation(S4));
		break;
	
	case 4:
		cout << endl;
		cout << "\nUpper Cased string: \n" 
			 << S1.stringUpperCase() << endl;
		break;
	
	case 5:
		cout << endl;
		cout << "\nLower Cased string: \n"
			 <<S1.stringLowerCase() << endl;
		break;
	
	case 6:
		if (S1.stringComparing(secondString) == 0)
			cout << "\nBoth strings are equal.\n";
		
		else if (S1.stringComparing(secondString) == 1)
			cout << "\nSecond string is greater than first string.\n";
		
		else if (S1.stringComparing(secondString) == -1)
			cout << "\nFirst string is greater than second string.\n";

		break;
	
	case 7:
		cout << "\nThe length of test string is "
			<< S1.getLengthOfString() << " characters.\n";
		break;
	
	case 8:
		S1.printEveryThing(secondString);
		break;
	
	case 9:
		exit(0);
	}
	
	goto label;
}

int main() {
	stringClass();
}