/*
 
 Name: FactoringCalculator.cpp
 
 Creator: Adam Hock
 
 Date started: 11/23/2017
 
 Description: This header file implements the functions that will multiply two
 binomials together, factor a trinomial using the AC method, and factor a 
 trinomial using the quadratic formula.
 
 */

#include <cstdlib>
#include "FactoringCalculator.h"

#include <iostream>

using namespace std;

/*
 This program will do basic foiling and factoring of two binomials, and can use the quadratic formula
 */
int main(int argc, char** argv) {
    int choice;
    while(1){
        cout << "Which of the following programs would you like to run?" << endl;
        cout << endl;
        cout << "1. Foiling Calculator" << endl;
        cout << endl;
        cout << "2. Factoring Calculator" << endl;
        cout << endl;
        cout << "3. Quadratic Formula Calculator" << endl;
        cout << endl;
        cout << "Your choice: ";
        cin >> choice;
        if (choice == 1)
            Foil();
        else if (choice == 2)
            Factor();
        else if (choice == 3)
            QuadFormula();
        else
            cout << "error!" << endl;
        cout << endl;
        cout << "Would you like to continue using this program?" << endl;
        cout << endl;
        cout << "1. Yes" << endl;
        cout << endl;
        cout << "2. No" << endl;
        cout << endl;
        cin >> choice;
        if (choice == 2)
            break;
        if (choice != 1 && choice != 2)
        {
            cout << "error!" << endl;
        }
    }
    return 0;
}

