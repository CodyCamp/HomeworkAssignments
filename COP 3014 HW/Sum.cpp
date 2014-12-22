/* Name: Cody Campbell
Date: 10/1/2014
Section: 2
Assignment: 3, exercise 2
Due Date: 10/2/2014
About this project: This will take in two integers from the user and output the sum of all the numbers between them.
Assumptions: Assumes correct input from user

All work below was performed by Cody Campbell*/


#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int inputOne, inputTwo, bigInput, smallInput, finalSum;

	cout << "Input two intergers: ";
	cin >> inputOne;
	cin >> inputTwo;
	cout << endl;

	if (inputOne > inputTwo)
	{
		bigInput = inputOne;
		smallInput = inputTwo;
	}

	else if (inputOne < inputTwo)
	{
		bigInput = inputTwo;
		smallInput = inputOne;
	}

	else
	{
		smallInput = inputOne;
		bigInput = inputOne;
	}

	finalSum = 0;

	cout << "Sum of values from " << smallInput << " through " << bigInput << " is:\n";

	while (smallInput <= bigInput)
	{
		cout << smallInput;
		if (smallInput < bigInput)
		{
			cout << " + ";
		}
		finalSum += smallInput;
		smallInput++;

	}

	cout << "\n= " << finalSum << "\n";

	return 0;

}