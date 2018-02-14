/*
 
 Name: Fizz_Buzz.cpp
 
 Creator: Adam Hock
 
 Date started: 2/14/2018
 
 Description: This program prints the numbers from 1 to 100, but for multiples
 * of three print "Fizz" and for multiples of five print "Buzz". For numbers 
 * which are multiples of both three and five, print "FizzBuzz".
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects.
 
 */
#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char** argv) {
    
    for (int i = 1; i < 101; i++)
    {
        if (i%3 == 0)
            cout << "Fizz";
        if (i%5 == 0)
            cout << "Buzz";
        if (i%3 != 0 && i%5 != 0)
            cout << i;
        cout << endl;
    }
    return 0;
}

