/* Name: Cody Campbell
Date: 10/1/2014
Section: 2
Assignment: 3, exercise 3
Due Date: 10/2/14
About this project: This will take a time input from the user and return the number of seconds since the last time the clock struck 12
Assumptions: correct user input, user will not put minute or second values larger than or equal to 60
All work below was performed by Cody Campbell */

#include <iostream>
#include <iomanip>

using namespace std;

int Seconds(int hours, int minutes, int seconds);

int main()
{
	int clockOneSeconds, clockOneMinutes, clockOneHours;
	cout << "Input first clock time...\nHours: ";
	cin >> clockOneHours;
	cout << "Minutes: ";
	cin >> clockOneMinutes;
	cout << "Seconds: ";
	cin >> clockOneSeconds;

	int clockTwoSeconds, clockTwoMinutes, clockTwoHours;
	cout << "\nInput second clock time...\nHours: ";
	cin >> clockTwoHours;
	cout << "Minutes: ";
	cin >> clockTwoMinutes;
	cout << "Seconds: ";
	cin >> clockTwoSeconds;

	while (clockOneHours >= 12 || clockTwoHours >= 12) {
		if (clockOneHours >= 12)
		{
			clockOneHours -= 12;
		}
		else if (clockTwoHours >= 12)
		{
			clockTwoHours -= 12;
		}
	}

	int clockOneTotalSeconds, clockTwoTotalSeconds;
	clockOneTotalSeconds = Seconds(clockOneHours, clockOneMinutes, clockOneSeconds);
	clockTwoTotalSeconds = Seconds(clockTwoHours, clockTwoMinutes, clockTwoSeconds);

	int secondsApart;

	if (clockOneTotalSeconds > clockTwoTotalSeconds)
		secondsApart = clockOneTotalSeconds - clockTwoTotalSeconds;
	else
		secondsApart = clockTwoTotalSeconds - clockOneTotalSeconds;


	cout << "\nIt's been " << clockOneTotalSeconds << " seconds since the first clock struck 12:00";
	cout << "\nIt's been " << clockTwoTotalSeconds << " seconds since the second clock struck 12:00";
	cout << "\nThe two times are " << secondsApart << " seconds apart.\n";

	return 0;
}

int Seconds(int hours, int minutes, int seconds)
{
	int secondsSinceTwelve;
	secondsSinceTwelve = (hours * 3600) + (minutes * 60) + (seconds);
	return secondsSinceTwelve;
}