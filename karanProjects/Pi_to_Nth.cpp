/*
 
 Name: Pi_to_Nth.cpp
 
 Creator: Adam Hock
 
 Date started: 11/09/2017
 
 Description: This program asks the user for an input, and outputs that many
 digits of pi (with a max of 14 digits)
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
 
 */

#include <cstdlib>
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main(int argc, char** argv) {

    int input;
    double pi = atan(1)*4;
    while (true)
    {
        cout << "How many digits of pi would you like to see? (The max is 15)" << endl;
        cin >> input;
        if (input < 1 || input > 15)
            cout << "\nSorry. That number is invalid. Please try again\n" << endl;
        else
            break;
    }
    cout << setprecision(input) << pi;
    cout << endl;
    return 0;
}

