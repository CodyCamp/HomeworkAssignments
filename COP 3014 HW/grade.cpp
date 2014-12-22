/* Name: Cody Campbell
Date: 9/19/14
Section: 2
Assignment: #2 - Grade Calculator 
Due Date: 9/19/14
About this project: This program will easily allow students to input their grades and have their final grade along with the letter grade calculated and presented for them.
Assumptions: asssumes correct input for grade values


All work below was performed by Cody Campbell*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "**************************\n" << "  Welcome to the COP3014\n" << " Grade Calculation System\n" << "**************************\n\n";

	cout << "Please enter the following data:\n";

	int homeworkOne, homeworkTwo, homeworkThree, homeworkFour, testOne, testTwo, finalExam; //this block asks for users grades and stores data in variables
	cout << "Homework 1 grade --> ";
	cin >> homeworkOne;
	cout << "Homework 2 grade --> ";
	cin >> homeworkTwo;
	cout << "Homework 3 grade --> ";
	cin >> homeworkThree;
	cout << "Homework 4 grade --> ";
	cin >> homeworkFour;
	cout << "\nTest 1 grade --> ";
	cin >> testOne;
	cout << "Test 2 grade --> ";
	cin >> testTwo;
	cout << "Final Exam grade --> ";
	cin >> finalExam;
	cout << endl;

	char extraCreditCheck; //ask and checks if user has extra credit
	cout << "Did you earn any extra credit on homeworks? (y or n) --> ";
	cin >> extraCreditCheck;

	double homeworkAverage, finalAverage;

	if (extraCreditCheck == 'y') //runs if user has extra credit
	{
		int extraCreditPoints;
		cout << "How many points should be added to homework total? --> ";
		cin >> extraCreditPoints;
		homeworkAverage = (( static_cast<double>(homeworkOne) + homeworkTwo + homeworkThree + homeworkFour + extraCreditPoints) / 4);// turned homework one into a double because homeworkAverage is a double and 
																																	 //only using ints to do the calculations here results in an incorrect final average.
		finalAverage = ((homeworkAverage)*0.4) + ((testOne)*0.175) + ((testTwo)*0.175) + ((finalExam)*0.25);

		int finalAverageInt = static_cast<int>(finalAverage); // switch only takes int, this turns final average from double to int
		
			switch (finalAverageInt / 10) 
		{
			case 10:
			case 9:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage; //rounds final average to two decimal places
				cout << "\nYour letter grade is: A! You passed with flying colors!\n";
				break;
			case 8:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: B!\n";
				break;
			case 7:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: C!\n";
				break;
			case 6:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: D..\nTry harder next time!\n";
				break;
			default:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYou earned the unmentionable grade...\nStudy harder next time!\n";
		}
	}

	else if (extraCreditCheck == 'n') // runs if no extra credit
	{
		homeworkAverage = ((static_cast<double>(homeworkOne) +homeworkTwo + homeworkThree + homeworkFour) / 4);
		finalAverage = (homeworkAverage*0.4) + ((testOne)*0.175) + ((testTwo)*0.175) + ((finalExam)*0.25);

		int finalAverageInt = static_cast<int>(finalAverage);

			switch (finalAverageInt / 10)//need to turn finalAverage into an int, switch only takes int
		{
			case 10:
			case 9:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: A! You passed with flying colors!\n";
					break;
			case 8:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: B!\n";
				break;
			case 7:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: C!\n";
				break;
			case 6:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYour letter grade is: D..\nTry harder next time!\n";
				break;
			default:
				cout << "Your final average is: " << fixed << setprecision(2) << finalAverage;
				cout << "\nYou earned the unmentionable grade...\nStudy harder next time!\n";
		}
	}

	else // runs if extra credit value was not a y or n 
	{
		cout << "Invalid entry, aborting program...\n";
	}

	return 0;
}