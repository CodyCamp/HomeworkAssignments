/* Name: Cody Campbell
Date: 12/7/14 (oops..)
Section: 2 
Assignment: 7 
Due Date: 12/6/14 
About this project: this project will analyze five different aspects of a file and put them into a different file
Assumptions: assumes output file is calles output.txt, also assumes there will be 100 or less values in the input file being analyzed

All work below was performed by Cody Campbell */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

/*DECLARE THREE REQUIRED FUNCTIONS HERE*/
void inputFileValCounter(ifstream& in, int numVal[]);
void fillArrayNumVal(ifstream& in, int val[]);
void printToOutputFile(ofstream& out, int val[], int numVal[]);

int main()
{
	ifstream in;
	ofstream out;
	
	/*DECLARE REQUIRED VARIABLES HERE*/
	char userInputFile[25];
	int * valueStorageSpace;
	int numVal[1] = {0};					//used to store count of numbers in input file, more efficient to use a pointer here because arrays are basically pointers I just forgot how
											//to push pointers through functions and this was fater.

	/*WELCOME AND ASK USER FOR INPUT FILE.*/
	cout << "Welcome! Please enter the name of the input file here: ";
	cin >> userInputFile;
	in.open(userInputFile);

	/*CHECK TO SEE THAT IT PROPERLY OPENED, FORCE THEM TO ENTER CORRECT FILENAME*/
	while (!in)				//doesnt let user in until file opens
	{
		in.clear();			//makes sure that !in will evaluate correctly each time by clearing in
		cout << "That file name didnt work, please try again: ";
		cin >> userInputFile;
		in.open(userInputFile);
	}

	//BELOW EACH OF THE FOLLOWING COUT STATEMENTS, YOU SHOULD NEED *ONE* LINE OF CODE. (AKA use a function if itll take more than one line)
	//WRITE AN APPROPRIATE LINE OF CODE OR FUNCTION CALL TO ACHEIVE THE BELOW TASKS.
	cout << "Thank you! Counting values now..." <<endl;	
	inputFileValCounter(in, numVal);					//counts values

	cout << "Closing input file! ... " << endl;			//closes input file
	in.close();

	cout << "Creating dynamic array to store values..." << endl;	//creates large array for storing values
	valueStorageSpace = new int[100];

	cout << "Reopening input file... " << endl;		//opens input file again using correct user input
	in.open(userInputFile);

	cout << "Filling array with numeric values..." << endl;	// fills created array
	fillArrayNumVal(in, valueStorageSpace);

	cout << "Closing input file... " << endl;	//closes input file
	in.close();

	cout << "Opening output file for information processing... " << endl;	//opens output file
	out.open("output.txt");

	cout << "Printing information to output file... " << endl;	// prints analyzed input data to output file
	printToOutputFile(out, valueStorageSpace, numVal);

	cout << "Closing output file... " << endl;	//closes output files
	out.close();

	cout << "Freeing up dynamic memory..." << endl; // deletes the dynamically allocated space
	delete[] valueStorageSpace;

	//Nothing else needed in main() after this.
	cout << endl << "All done!" << endl;
	return 0;
}

/*WRITE YOUR FUNCTION DEFINITIONS HERE*/

void inputFileValCounter(ifstream& in, int numVal[])
{
	int valueCount = 0;
	int value;

	while (!in.eof())
	{
		in >> value;
		if (!in.fail())
			valueCount++;
	}

	numVal[0] = valueCount;											//stores count for later use

	cout << "I counted " << valueCount << " values.\n" << endl;
	
}

void fillArrayNumVal(ifstream& in, int val[])
{
	int value;
	int count = 0;

	while(!in.eof())	//inputs value to array, incrementing array by one
	{
		in >> value;
		val[count] = value;
		count++;
	}
}

void printToOutputFile(ofstream& out, int val[], int numVal[]) 
{
	int cntVal = numVal[0];
	int sumVal = 0;
	int avgVal = 0;
	int maxVal = val[0];					//val[0] used for referance for max/ min
	int minVal = val[0];

	for (int i = 0; i < cntVal; i++)		//finds sum
		sumVal += val[i];

	avgVal = sumVal / cntVal;				//finds avg

	for (int i = 0; i < cntVal; i++)		//finds max
	{
		if (val[i] > maxVal)
			maxVal = val[i];
	}

	for (int i = 0; i < cntVal; i++)		//finds min
	{
		if (val[i] < minVal)
			minVal = val[i];
	}

	out << "Count of values: " << cntVal;
	out << "\nSum of values: " << sumVal;
	out << "\nAverage of values: " << avgVal;
	out << "\nMaximum: " << maxVal;
	out << "\nMinimum: " << minVal;
}

