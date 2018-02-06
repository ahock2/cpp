/*
 
 Name: BinaryVSDecimal.cpp
 
 Creator: Adam Hock
 
 Date started: 11/17/2017
 
 Description: This program converts a binary number inputted by the user (if 
 given the correct number of digits) to decimal. It also converts a decimal 
 number to binary.
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
  
 Potential updates for this project could
 range from not asking for a user input for how many digits the binary number
 will be, converting to hexadecimal and octal.
 
 */


#include <cstdlib>
#include <cmath>
#include <iostream>

using namespace std;


int BinToDec (int digits, int* binary)
/* This function takes in a binary number and outputs its decimal equivalent */
{
    int decimal = 0;
    for (int a = 0; a < digits; a++)
    {
        if (binary[a] == 1)
            decimal += pow(2, a);
    }
    return decimal;
}

int* DecToBin (int decimal, int digits, int* binary) 
/* This function takes in a decimal number and outputs its binary equivalent*/
{
    for (int j = digits-1; j >= 0; j--)
    {
        if (decimal >= pow(2, j))
        {
            binary[j] = 1;
            decimal-=pow(2, j);
        }
        else
            binary[j] = 0;
    }
    return binary; 
}

int main(int argc, char** argv) 
{
    int choice;
    cout << "Which of the following converters would you like to use?" << endl;
    cout << "\n 1.) Binary to Decimal converter" << endl;
    cout << "\n 2.) Decimal to Binary converter" << endl;
    cout << endl;
    cin >> choice;
    cout << endl;
    if (choice == 1)
        /* This part of the code asks for the user to input a binary number
           to eventually convert it into decimal form */
    {
        int digits;
        cout << "How many digits is this binary number going to be?" << endl;
        cin >> digits;
        cout << endl;
        int binary[digits] = {};
        if (digits < 1)
        {
            cout << "error" << endl;
            return 0;
        }
        else
        {
            cout << "Please enter each binary number while pressing the ENTER key in between" << endl;
            for (int a = digits-1; a >= 0; a--)
            {
                cin >> binary[a];
                if (binary[a] != 0 && binary[a] != 1)
                {
                    cout << "error" << endl;
                    return 0;
                }
            }
        }
        cout << endl;
        int decimal = BinToDec(digits, binary);
        cout << decimal;
    }   
    if (choice == 2)
        /* This part of the code asks for the user to input a decimal number
          to eventually convert it into binary form */
    {
        int decimal;
        int digits = 1;
        cout << "Give me a decimal number, and I will convert it to binary" << endl;
        cin >> decimal;
        cout << endl;
        if (decimal < 0)
            cout << "error" << endl;
        else
        {
            for (int i = 1; i > 0; i++)
            {
                if (decimal >= pow (2, i))
                    digits++;
                else
                    i =  -1;
            }
        }
        int binary[digits] = {};
        int* answer = DecToBin(decimal, digits, binary);
        for (int k = digits-1; k >= 0; k--)
            cout << answer[k];
    }
    cout << "\n" << endl;
    return 0;
}

