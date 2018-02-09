/*
 
 Name: Fact_Calc_source.cpp
 
 Creator: Adam Hock
 
 Date started: 11/23/2017
 
 Description: This source file creates the functions that will multiply two
 binomials together, factor a trinomial using the AC method, and factor a 
 trinomial using the quadratic formula.
 
 */

#include "FactoringCalculator.h"
#include <iostream>
#include <cmath>

using namespace std;

void Foil()
{
    int a, b, c, d;
    cout << "Fill in the following criteria so we can foil the following polynomial" << endl;
    cout << endl;
    cout << "( ax + b ) ( cx + d )" << endl;
    cout << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    cout << "d: ";
    cin >> d;
    cout << endl;
    cout << "This is the following foiled function" << endl;
    cout << endl;
    cout << a*c << "x^2 + " << (b*c)+(a*d) << "x + " << b*d << endl;
};

void Factor()
{
    int a, b, c, product, term1, term2, diviser1, diviser2, choice, zero1, zero2;
    cout << "Fill in the following criteria so we can factor the following polynomial" << endl;
    cout << endl;
    cout << "ax^2 + bx + c" << endl;
    cout << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    product = a*c;
    for (term1 = -abs(product); term1 <= abs(product); term1++)
    {
        if (term1 == 0)
            term1++;
        if (product%term1 == 0)
        {
            term2 = product/term1;
            if (term1+term2 == b)
            {
                cout << "These two terms can factor! This is how!" << endl;
                cout << endl;
                cout << "The two terms that multiply to " << product << " and add to " << b << " are " << term1 << " and " << term2 << endl;
                cout << endl;
                cout << "The equation can be rewritten as..." << endl;
                cout << endl;
                cout << "( " << a << "x^2 + " << term1 << "x ) ( " << term2 << "x + " << c << " )" << endl;
                cout << endl;
                for (int i = 1; i < abs(a) + abs(term1); i++)
                {
                    if (a%i == 0 && term1%i == 0)
                        diviser1 = i;
                }
                for (int j = 1; j < abs(term2) + abs(c); j++)
                {
                    if (term2%j == 0 && c%j == 0)
                        diviser2 = j;
                }
                if (a > 0 && term2 < 0)
                    diviser2 *= -1;
                if (a < 0 && term2 > 0)
                    diviser1 *= -1;
                cout << "You can divide your first two terms by " << diviser1 << "x and you are left with the terms ( " << a/diviser1 << "x + " << term1/diviser1 << " )" << endl;
                cout << endl;
                cout << "You can divide the last two terms by " << diviser2 << " and you are left with the terms ( " << term2/diviser2 << "x + " << c/diviser2 << " )" << endl;
                cout << endl;
                cout << "In the end, your polynomial factors out to be ( " << diviser1 << "x + " << diviser2 << " ) ( " << a/diviser1 << "x + " << term1/diviser1 << " )" << endl;
                cout << endl;
                cout << "Would you like to find the real zeros of this polynomial?" << endl;
                cout << endl;
                cout << "1. Yes" << endl;
                cout << endl;
                cout  << "2. No" << endl;
                cout << endl;
                cin >> choice;
                cout << endl;
                if (choice == 1)
                {
                    zero1 = (-diviser2/diviser1);
                    zero2 = (-(term1/diviser1)/(a/diviser1));
                    if (-diviser2%diviser1 == 0)
                        cout << "The real zero of the first polynomial is " << zero1 << endl;
                    else
                        cout << "The real zero of the first polynomial is " << -diviser2 << "/" << diviser1 << endl;
                    if (-(term1/diviser1)%(a/diviser1) == 0)
                        cout << "The real zero of the second polynomial is " << zero2 << endl;
                    if (floor(zero2) != zero2)
                        cout << "The real zero of the second polynomial is " << -term1/diviser1 << "/" << a/diviser1 << endl;
                    cout << endl;
                    return;
                }
                return;
            }
        }
    }
    cout << "We cannot factor this polynomial via the AC method, so try using the quadratic formula program!" << endl;
    cout << endl;
    return;
};

void QuadFormula ()
{
    int a, b, c, root, denom, denom1, denom2, num1, num2;
    int rootresult = 1;
    cout << "Fill in the following criteria so we can factor the following polynomial" << endl;
    cout << endl;
    cout << "ax^2 + bx + c" << endl;
    cout << endl;
    cout << "a: ";
    cin >> a;
    cout << "b: ";
    cin >> b;
    cout << "c: ";
    cin >> c;
    root = pow(b,2) - (4*a*c);
    denom = 2*a;
    denom2 = denom1 = denom;
    num1 = -b+root;
    num2 = -b-root;
    for (int i = 1; i < root; i++)
    {
        if (root/i == i)
        {
            root /= i;
            num1 = -b+root;
            num2 = -b-root;
            if((num1)%denom == 0)
                cout << "The first real zero of this polynomial is " << (num1)/denom << endl;
            if((num1)%denom != 0)
            {
                for (int j = abs(num1) + abs(denom); j > 0; j--)
                {
                    if (num1%j == 0 && denom%j == 0)
                    {
                        num1 /= j;
                        denom1 /= j;
                    }
                }
                cout << "The first real zero of this polynomial is " << (num1) << "/" << denom1 << endl;
            }
            if((num2)%denom == 0)
                cout << "The second real zero of this polynomial is " << (num2)/denom << endl;
            if((num2)%denom != 0)
            {
                for (int k = abs(num2) + abs(denom); k > 0; k--)
                {
                    if (num2%k == 0 && denom%k == 0)
                    {
                        num2 /= k;
                        denom2 /= k;
                    }
                }
                cout << "The second real zero of this polynomial is " << (num2) << "/" << denom2 << endl;
            }
            return;
        }
    }
    cout << "The real zeros of this polynomial are " << -b << " Plus/Minus sqrt(";
    if (root < 0)
        cout << -root << ")i all over " << denom << endl;
    if (root > 0)
        cout << root << ") all over " << denom << endl;
    return;
};