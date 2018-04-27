///////////////////////////////////////////////////////////////////////////////////
// ProgramName: Program # 3
// Author: Colton Boyd 
// Description: 
// This program reads in animal names into a doubly-linked
// list, then prompts the user to enter a number that will
// serve as random. It will then prompt the user
// to enter a number that will be as the multiplier. If
// number is even, the pointer moves to the right and vice
// versa. Animals are then removed based on the random number 
// until one animal is left. This animal is then declared the survivor.
// Semester: Spring 2018
// Course: 1063 Data Structures
// Date: 27 04 2018
///////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include <string>

#include "DBList.h"

using namespace std;
/////////////////////////////
//Main function
/////////////////////////////
int main()
{
	//instance for our class 
	DBList List;

	//allow for manipulation
	string first;
	string second;

	int listSize = 0;

	int rand = 0;

	int num = 0;

	int length = 0;




	//prompts user to enter the random number seed
	cout << "Please enter a number that will serve as the random seed:" << endl;

	//type in random num 
	cin >> rand;

	srand(rand);

	//animal file
	ifstream fin("animals.txt");

	//creates the outfile
	ofstream outfile("eliminated.txt");

	//outfile everything to eliminated.txt
	outfile << "//////////////////////////////////////////////////////////////////////////" << endl;
	outfile << "//ProgramName: Program # 3" << endl;
	outfile << "//Author: Colton Boyd " << endl;
	outfile << "//Description: " << endl;
	outfile << "//This program reads in animal names into a doubly-linked" << endl;
	outfile << "//list, then prompts the user to enter a number that will" << endl;
	outfile << "//serve as random. It will then prompt the user" << endl;
	outfile << "//to enter a number that will be as the multiplier. If" << endl;
	outfile << "//number is even, the pointer moves to the right and vice" << endl;
	outfile << "//versa. Animals are then removed based on the random number" << endl;
	outfile << "//until one animal is left. This animal is then declared the survivor." << endl;
	outfile << "//Semester: Spring 2018" << endl;
	outfile << "//Course: 1063 Data Structures" << endl;
	outfile << "//Date: 27 04 2018" << endl;
	outfile << "//////////////////////////////////////////////////////////////////////////////" << endl << endl;

	//insert items
	while (!fin.eof()) {

		fin >> first;

		listSize++;

		List.InsertRear(first);

	}

	//reset list to recalculate 
	fin.clear();
	fin.seekg(0, std::ios::beg); 


								
	cout << "Choose a number: " << endl;

	cin >> num;

	//Prompt telling user to pick another number if not through 1-13. 
	while (num > 13 || num < 1)
	{
		cout << "Pick another number: " << endl;

		cin >> num;
	}
	// outfiles the multiplier 
	outfile << "The chosen multiplier: " << num << endl;

	// loop for checking conditions
	while (!fin.eof())
	{
		//Gives us the first animal in list 
		fin >> first;

		outfile << "First: ";
		//While size of list is greater than 1 
		while (listSize > 1) {

			length = first.length() * num;

			second = List.checkifEvenorOdd(length);

			// prints out every 11 animals removed
			if (listSize % 11 == 0)
			{
				outfile << "- " << second << endl;

				cout << " " << second << endl;
			}
			else
			{
				cout << " " << second << endl;
			}

			fin >> first;

			listSize--;
		}
	}
	//print function to see our results 
	List.Print(outfile);
}
