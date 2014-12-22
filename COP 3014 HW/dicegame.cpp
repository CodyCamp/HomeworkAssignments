/* Name: Cody Campbell
Date: 10/19/14
Section: 2
Assignment: #4
Due Date: 10/19/14
About this project: This is a dice based betting game where the userstarts out with $500 and can bet to win more or lose money.
Assumptions: Assumes user input is an interger

All work below was performed by Cody Campbell */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>             //libraries included for random int generator

using namespace std;

void welcome();
void rollDice(int&, int&);
bool checkWin(int diceOne, int diceTwo);

int main()
{
	srand(time(0));
	const int startingMoney = 500;
	int playerMoney = startingMoney;
	welcome();

	/*
	rollDice(diceOne, diceTwo);                   Used for debuggging & checking dice numbers
	cout <<diceOne << " " << diceTwo;
	*/

	while (playerMoney > 0)
	{
		int playerBet, diceOne, diceTwo, diceSum;
		diceOne = 0;
		diceTwo = 0;

		cout << "You have $" << playerMoney << " remaining\n";
		cout << "Place your bet: ";
		cin >> playerBet;
		if (playerBet < 0 || playerMoney == 0)
		{
			cout << "\nYou're leaving with $" << playerMoney << endl;
			if (playerMoney - startingMoney > 0)
			{
				cout << "You MADE $" << (playerMoney - startingMoney) << "!!!" << endl;
			}
			else if (playerMoney - startingMoney < 0)
			{
				cout << "You LOST $" << (startingMoney - playerMoney) << "!!!" << endl;
			}
			cout << "Thanks for playing!\n";
			break;
		}
		else if (playerBet == 0)
		{
			cout << "You can't bet 0!";
		}
		else if (playerBet > playerMoney)
		{
			cout << "You can't bet more $ than you have!"; 
		}
		else
		{
			rollDice(diceOne, diceTwo);
			diceSum = diceOne + diceTwo;
			cout << "You rolled " << diceOne << " and " << diceTwo << " = " << diceSum << endl;
			if (diceSum == 7)
			{
				cout << "You Win!!\n\n";
				playerMoney += playerBet;
			}
			else
			{
				cout << "You Lose!!\n\n";
				playerMoney -= playerBet;
			}
			
		}
	}
	return 0;
}

void welcome()                     // function used to start game off with description
{
	cout << "***** Welcome to SEVENS! The betting dice game! *****\n";
	cout << "Wager whatever you'd like. If you roll a 7, you win whatever you bet!\n";
	cout << "But beware, if you don't roll a 7, you lose your wager\n";
	cout << "Enter a negative bet if you'd like to quit the game early\n";
	cout << "LETS BEGIN!!!\n\n";
}

void rollDice(int& diceOne, int& diceTwo)
{
	diceOne = rand() % 6 + 1;     // by using a reference value you change the variable even though it is in a different scope
	diceTwo = rand() % 6 + 1;     // this function generates two random nubers between 1 and 6
}