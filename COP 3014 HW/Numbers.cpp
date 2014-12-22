/* Name: Cody Campbell
Date: 10/1/2014
Section: 2
Assignment: 3, exercise 1
Due Date: 10/2/2014
About this project: This project will take in intergers given by the user and compute the sum and average while also displaying the total positive and negative numbers given by the user
Assumptions: Assumes correct user input

All work below was performed by Cody Campbell */

#include <iostream>
#include <iomanip>
using namespace std;


int main()
{
	int userInput, posNumCount, negNumCount, sum;
	double average;

	posNumCount = 0;
	negNumCount = 0;
	sum = 0;

	do
	{
		cout << "Input integer (0 to stop): ";
		cin >> userInput;
		sum += userInput;
		if (userInput > 0)
			posNumCount++;
		else if (userInput < 0)
			negNumCount++;

	} 
	while (userInput != 0);

	average = static_cast<double>(sum) / (posNumCount + negNumCount);

	cout << "\n" << "# of positives = " << posNumCount << "\n";
	cout << "# of negatives = " << negNumCount << "\n";
	cout << "Sum = " << sum << "\n";
	cout << "Average = " << setprecision(2) << fixed << average << "\n";

	return 0;
}

