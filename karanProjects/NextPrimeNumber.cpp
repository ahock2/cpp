/*
 
 Name: NextPrimeNumber.cpp
 
 Creator: Adam Hock
 
 Date started: 11/15/2017
 
 Description: This program accepts a numerical user input and outputs the next 
 prime number after the user's inputted number.
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
  
 This program can be updated to tell the user the next composite number, tell
 the user if their inputted number is prime or composite, and maybe show factors
 of a composite number to prove the number is in fact composite.
 
 */

#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    int input;
    bool NextPrime;
    cout << "Please enter an integer" << endl;
    cin >> input;
    int i = input + 1;
    while(true)
    {
        NextPrime = true;
        for (int j = 2; j < i; j++)
        {
            if (i%j == 0)
                NextPrime = false;
        }
        if (NextPrime == true)
        {
            cout << "The next prime number is " << i << endl;
            break;
        }
        i++;
    }
    
    return 0;
}

