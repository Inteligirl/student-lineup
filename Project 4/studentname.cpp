//Tammy Gibson
//COP2000.0M1
//Program will test a list of student names. Sort alphabetically and display the first and last studnet's name.

#include <iostream>
#include <fstream>  //to read in files
#include <string>  //to read in strings
#include <iomanip> //in out manipulation

using namespace std;

int main()
{
	//variables
	string student;
	string firstStudent;
	string lastStudent;
	int counter = 0;
	ifstream inputFile;

	string stars; //output formating

	// Set the star output formatting
		stars.assign(75, '*');

	//Explain fuction of program to user
	cout << endl << stars << endl;
	cout << "\nThis program will input student names from the file lineup.txt." << endl;
	cout << "The student names will be sorted alphabeticaly." << endl;
	cout << "The name of the first student and the last student will then be displayed." << endl << endl;
	cout << stars << endl << endl;

	inputFile.open("lineup.txt");

	if (!inputFile)			//verify file requested did open
	{
		cout << "Input file did not open." << endl;
		return 10;
	}

	while (inputFile >> student)
	{
		if (counter == 0)
		{
			firstStudent = student;
			lastStudent = student;
			counter++;
		}

		else
		{

			if (student < firstStudent)
				firstStudent = student;
			else if (student > lastStudent)
				lastStudent = student;
		}
	}

	cout << "\nThe name of the first student is " << firstStudent << "." << endl;
	cout << "\nThe name of the last studnet is " << lastStudent << ".\n" << endl;

	inputFile.close();

	return 0;

}