/* Starter file for assignment 5

* Two functions are provided.  You will write the 5 specified functions,

* as well as a menu program to test the functions.

*

* Name: Cody Campbell
Date: 11/6/14
Section: 2
Assignment: 5
Due Date: 11/6/14
About this project: This project will help develop skills with arrays and functions
Assumptions: correct user input, assumes first thing user does is fill the array arraye

All work done below was performed by Cody Campbell*/

#include <iostream>

using namespace std;

/* Given Function prototypes */
void PrintArray(const int arr[], const int size);
void FillArray(int arr[], const int size);

/* My function prototypes */
void printMenu();														//defining functions
void Insert(int arr[], int size, int newValue, int newIndex);
void Reverse(int arr[], int size);
void Delete(int arr[], int size, int indexNum);
int SumEvens(int arr[], int size, int numAdd);
int HowMany(int arr[], int size, int value);

int main()                                                                                  //main starts here
{
	const int SIZE = 15;

	/* Declare your array and write the menu loop */

	int arraye[SIZE] = {};
	
	char userSelection = 'M';
	
	do
	{
		switch (userSelection){
			case 'I':{												// Insert function
						 int insertValue = 0;
						 int insertIndex = 0;

						 cout << "Enter the value to be inserted: ";
						 cin >> insertValue;
						 cout << "Enter the index number: ";
						 cin >> insertIndex;
						 Insert(arraye, SIZE, insertValue, insertIndex);
						 PrintArray(arraye, SIZE);
						 break;
			}
			case 'Q':{												//exits program
						 break;
			}
			case 'P':{											    //prints the array "arraye"
						 PrintArray(arraye, SIZE);
						 break;
			}
			case 'D':{												//deletes number at given index
						 int deleteIndex = 0;
						 cout << "Enter the index to be deleted: ";
						 cin >> deleteIndex;
						 Delete(arraye, SIZE, deleteIndex);
						 PrintArray(arraye, SIZE);
						 break;
			}
			case 'R':{											   //reverses array
						 Reverse(arraye, SIZE);
						 PrintArray(arraye, SIZE);
						 break;
			}
			case 'S':{											//sum of the number of even numbers in the range the user entered
						 int numToAdd = 0;
						 cout << "Enter how many even numbers to add: ";
						 cin >> numToAdd;
						 while (numToAdd > SIZE || numToAdd < 0)
						 {
							 cout << "Make sure your number is less than the array size and greater than zero!";
							 cin >> numToAdd;
						 }
						 cout << "The sum of the first " << numToAdd << " even numbers is: " << SumEvens(arraye, SIZE, numToAdd);
						 break;
			}
			case 'H':{												//tells how many times the value is in the array
						 int searchFor = 0;
						 cout << "Enter a value to search for: ";
						 cin >> searchFor;
						 cout << "The value " << searchFor << " appears in the list " << HowMany(arraye, SIZE, searchFor) << " times";
						 break;
			}
			case 'M':{											   //print menu again
						 printMenu();
						 break;
			}
			case 'F':{                                             //allows user to fill array
						 FillArray(arraye, SIZE);
						 break; 
			}
		}

		cout << "\nEnter your menu selection: ";
		cin >> userSelection;
	 } while (userSelection != 'Q');
	 

	return 0;

}	// end main()



/* My functions */
void printMenu()     //Prints menu

{

	cout << "\t " << "** Given features **" << endl;

	cout << "P\t" << "Print the array contents" << endl;

	cout << "F\t" << "Fill the array (user entry)" << endl << endl;

	cout << "\t " << "** Function Tests **" << endl;

	cout << "I\t" << "Insert" << endl;

	cout << "D\t" << "Delete" << endl;

	cout << "R\t" << "Reverse" << endl;

	cout << "H\t" << "HowMany" << endl;

	cout << "S\t" << "SumEvents" << endl << endl;

	cout << "M\t" << "Print this menu" << endl;

	cout << "Q\t" << "Quit this program" << endl;

}

int SumEvens(int arr[], int size, int numAdd)                       // working

{
	int count = 0;													
	int sum = 0;
	for (int i = 0; i < size; i++){					
		if (count >= numAdd)					//ends program when count hits numAdd
			break;
		else if (arr[i] == 0)					//passes zero w/o changing count
			sum += 0;
		else if (arr[i] % 2 == 0){				//adds if number is even, also adds one to count
			sum += arr[i];
			count++;
		}
	}
	return sum;
}

int HowMany(int arr[], int size, int value)                         // working

{
	int count = 0;
	for (int i = 0; i <= size; i++){						//loops through array and adds to count when value is present at checked index
		if (arr[i] == value)
			count++;
	}
	return count;
}

void Reverse(int arr[], int size)                                   // working
{
	int placeHolder = 0;
	for (int i = 0; i < (size / 2); i++){						//loops through the first half of the array using a temperary variable to store an array index
		placeHolder = arr[i];									// changes two array indexes every loop
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = placeHolder;
	}
}

void Delete(int arr[], int size, int indexNum)                      // working
{
	if (indexNum < size)					// makes sure index is in the range
	{
		for (int i = indexNum; i < size; i++)		// loops through changing each array value to the one after it except the last, which is set to zero
		{
			if (i == size - 1)
				arr[i] = 0;
			else
				arr[i] = arr[i + 1];
		}
	}
}

void Insert(int arr[], int size, int newValue, int newIndex)        // working
{
	if (newIndex <= size)						
	for (int i = size; i >= newIndex; i--)		//loops starting from the end of the array, changing the values to the values at the index before them
		arr[i] = arr[i - 1];					// stops when i hits new index
	arr[newIndex] = newValue;
}



/* DO NOT CHANGE THESE! */

void PrintArray(const int arr[], const int size)

// this function prints the contents of the array

{

	cout << "\nThe array:\n { ";

	for (int i = 0; i < size - 1; i++)	// print all but last item

		cout << arr[i] << ", ";



	cout << arr[size - 1] << " }\n";	// print last item

}

void FillArray(int arr[], const int size)

// this function loads the contents of the array with user-entered values

{

	cout << "Please enter " << size

		<< " integers to load into the array\n> ";



	for (int i = 0; i < size; i++)

		cin >> arr[i];	// enter data into array slot

}