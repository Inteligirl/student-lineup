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
	string stars;   //output formating

	
	// Set the star output formatting
	stars.assign(75, '*');

	//Explain fuction of program to user
	cout << endl << stars << endl;
	cout << "\nThis program will input student names from the file lineup.txt." << endl;
	cout << "The student names will be compared alphabeticaly and stored." << endl;
	cout << "The name of the first student and the last student will then be displayed." << endl << endl;
	cout << stars << endl << endl;

	//Open text file
	inputFile.open("lineup.txt");

	//verify file requested did open
	if (!inputFile)			
	{
		cout << "Input file did not open." << endl;
		return 10;
	}

	//Extra comments so I can walk myself through what the lines are doing.
	while (inputFile >> student)  //while the inputFile returns True store read data to variable student
	{
		if (counter == 0) //The counter will never be 0 except it's first time through. This is an initialization
			              //to setup the first and last values to compare the remaining students to.
		{
			firstStudent = student; //it's assigning two at a time. value 1 from file
			lastStudent = student;  //value 2 from file
			counter++;              //add 1 to counter
		}

		else          //since the counter is now 1 this else statement will execute until the End of File
		{
			          //this is where the comparison takes place
			if (student < firstStudent)  //easier to think of data as a number. If number read is less that firstStudent
				firstStudent = student;  //then assign that number as the new firstNumber
			else if (student > lastStudent) //else if larger than the number stored as lastStudent
				lastStudent = student;      //then assign that number as the new lastStudent
		}
	}

	cout << "\nThe name of the first student is " << firstStudent << "." << endl;
	cout << "\nThe name of the last studnet is " << lastStudent << ".\n" << endl;

	inputFile.close();

	return 0;

}