/*
 
 Name: Reverse_String.cpp
 
 Creator: Adam Hock
 
 Date started: 2/14/2018
 
 Description: This program will take a user inputted word and reverse it. It
 * will return the reverse word and also tell you if the word you entered was a
 * palindrome.
 
 Comments: This project was inspired by Github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects.
 
 */
#include <iostream>
#include <string>

using namespace std;

int main() {
    string input, output;
    bool palindrome = false;
    cout << "Please enter your input" << endl;
    cin >> input;
    for (int i = input.size()-1; i >= 0; i--)
    {
        output += input[i];
    }
    if (output == input)
        palindrome = true;
    cout << output << endl;
    if (palindrome == false)
        cout << "Your input is not a palindrome" << endl;
    else
        cout << "Your input is a palindrome" << endl;
    return 0;
}

