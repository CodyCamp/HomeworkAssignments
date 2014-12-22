/* Name: Cody Campbell
 Date: 11/14/14
 Section: 2
 Assignment: 6
 Due Date: 11/14/14
 About this project: This project will be a program that tests to see if a user entered password meets the needed criteria for password strength.
 Assumptions: assumes user will input data, user will keep trying until completed.
 
 All work below was performed by Cody Campbell */

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

bool lengthCheck(string password);              //defining functions for later use
bool digitCheck(string password);
bool uppercaseCheck(string password);
bool lowercaseCheck(string password);
bool spaceCheck(string password);
bool passwordCheck(string password);

int main()
{
    string userPassword, userPasswordTwo;
    do{
        cout << "\nEnter your password: ";
        cin >> userPassword;
        if (not lengthCheck(userPassword))                            //checks to see if length is correct
            cout << "Password needs to have 6 or more characters\n";
        if (not digitCheck(userPassword))               // "not" added so functions work easily with passwordCheck function below
            cout << "Password needs to containt at least one digit\n";
        if (not uppercaseCheck(userPassword))                   //functions do what they say
            cout << "Password needs to contain at least one uppercase letter\n";
        if(not lowercaseCheck(userPassword))
            cout << "Password needs to contain at least one lowercase letter\n";
        if (not spaceCheck(userPassword))
            cout << "Password can not contain a space\n";
    } while(passwordCheck(userPassword));
    
    cout << "Now re-enter your password for verification: ";
    cin >> userPasswordTwo;
    
    if (userPassword == userPasswordTwo)                   //checks users passwords to make sure theyre the same
        cout << "You have now entered a valid password\n";
    else if (userPassword != userPasswordTwo)
    {
        cout << "Password doesn not match. Start over\n";
        return 0;
    }
    return 0;
}

bool lengthCheck(string password){                      //functions used in main program
    if (password.length() < 6){
        return false;
    }
    else
        return true;
}

bool digitCheck(string password){
    for (int i = 0; i < password.length(); i++)
    {
        if (isdigit(password[i]))
            return true;
    }
    return false;
}
            
bool uppercaseCheck(string password){
    for (int i = 0; i < password.length(); i++)
    {
        if (isupper(password[i]))
            return true;
    }
    return false;
}

bool lowercaseCheck(string password){
    for (int i = 0; i < password.length(); i++)
    {
        if (islower(password[i]))
            return true;
    }
    return false;
}
                 
bool spaceCheck(string password){
    for (int i = 0; i < password.length(); i++)
    {
        if (isspace(password[i]))
            return false;
    }
    return true;
}
            
bool passwordCheck(string password){                            //mostly used to condense main program to make it look nicer
    if(lengthCheck(password) && uppercaseCheck(password) && lowercaseCheck(password) &&digitCheck(password))
        return false;
    return true;
}