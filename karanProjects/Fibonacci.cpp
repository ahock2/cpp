
/*
 
 Name: Fibonacci.cpp
 
 Creator: Adam Hock
 
 Date started: 11/09/2017
 
 Description: This program accepts a number from the user and outputs the 
 Fibonacci sequence up to that number.
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
  
 This project could be updated to offer features such as the sum of the numbers
 up to that Fibonacci number chosen by the user, a bool statement that is true
 if the user inputted number is in the Fibonacci sequence and false if it is
 not, and a program that will calculate the sum of numbers between 2 Fibonacci
 indexes inputted by the user.
 
 */

#include <cstdlib>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int left, mid, right, end, input;
    left = 1;
    mid = 1;
    
    /*
     This part of the program ensures that a positive number has been typed in
     */
    while(true)
    {
        cout << "Please enter how many numbers you want this Fibonacci sequence to be" << endl;
        cin >> input;
        if (input < 0)
            cout << "\nThat number is invalid. Please enter in a positive number\n" << endl;
        else
            break;
    }
    /* If the user inputs a 0 */
    if (input == 0)
        cout << "0" << endl;
    
    for (int i = 1; i < input+1; i++)
    {
        if (i == 1)
            cout << "1";
        if (i == 2)
            cout << "1";
        if (i > 2)
        {
            right = left + mid;
            cout << right;
            left = mid;
            mid = right;
            right = right + left;
        }
        cout << ", ";
    }
    cout << endl;
    return 0;
}

