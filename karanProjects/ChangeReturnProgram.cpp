/*
 
 Name: ChangeReturnProgram.cpp
 
 Creator: Adam Hock
 
 Date started: 11/20/2017
 
 Description: This program asks the user to input an amount of money (ex. 35.76)
 and the program outputs how many and what type of change should be dispensed
 (ex. 1 $20, 1 $10, 1 $5, 3 quarters, and 1 penny)
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
  
 This project can be improved simply by adding more features that a cash
 register already has such as calculating the correct change and assigning
 different numbers to meals (like at McDonald's).
 
 */
#include <cstdlib>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {
    double input;
    int hundreds=0;
    int fifties=0;
    int twenties=0;
    int tens=0;
    int fives=0;
    int ones=0; 
    int quarters=0;
    int dimes=0; 
    int nickels=0;
    cout << "Please enter a dollar amount: $";
    cin >> input;
    double pennies = input*100;
    int Dpennies;
    while (true)
    {
        if (pennies / 10000 >= 1)
        {
            hundreds++;
            pennies-=10000;
        }
        else if (pennies / 5000 >= 1)
        {
            fifties++;
            pennies-=5000;
        }
        else if (pennies / 2000 >= 1)
        {
            twenties++;
            pennies-=2000;
        }
        else if (pennies / 1000 >= 1)
        {
            tens++;
            pennies-=1000;
        }
        else if (pennies / 500 >= 1)
        {
            fives++;
            pennies-=500;
        }
        else if (pennies / 100 >= 1)
        {
            ones++;
            pennies-=100;
        }
        else if (pennies / 25 >= 1)
        {
            quarters++;
            pennies-=25;
        }
        else if (pennies / 10 >= 1)
        {
            dimes++;
            pennies-=10;
        }
        else if (pennies / 5 >= 1)
        {
            nickels++;
            pennies-=5;
        }
        else
            break;
    }
    Dpennies=pennies;
    cout << "Number of $100 bills: " << hundreds << endl;
    cout << "Number of $50 bills: " << fifties << endl;
    cout << "Number of $20 bills: " << twenties << endl;
    cout << "Number of $10 bills: " << tens << endl;
    cout << "Number of $5 bills: " << fives << endl;
    cout << "Number of $1 bills: " << ones << endl;
    cout << "Number of quarters: " << quarters << endl;
    cout << "Number of dimes: " << dimes << endl;
    cout << "Number of nickels: " << nickels << endl;
    cout << "Number of pennies: " << Dpennies << endl;
    return 0;
}