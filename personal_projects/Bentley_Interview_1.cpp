/*

Name: Bentley_Interview_1

Creator: Adam Hock

Date Started: 2/13/2018

Description: This program is supposed to take the name William Henry Douglas
and take out the spaces in the name, make all the letters lowercase, take out
duplicate letters, and print a new string which puts the remaining letters in
alphabetical order.
 
Comments: This program was given to me in as an online interview question for
Bentley Systems.
 
*/

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

int main(int argc, char** argv) {

    std::string a = ("William Henry Douglas");
    std::string lowercase = "abcdefghijklmnopqrstuvwxyz";
    std::string lowercase2 = lowercase;
    std::string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    std::string out_of_order;
    std::string in_order;
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < lowercase.size(); j++)
        {
            if (a[i] == lowercase[j])
            {
                out_of_order += a[i];
                lowercase.erase(lowercase.begin()+j);
                uppercase.erase(uppercase.begin()+j);
            }
            else if (a[i] == uppercase[j])
            {
                out_of_order += lowercase[j];
                lowercase.erase(lowercase.begin()+j);
                uppercase.erase(uppercase.begin()+j);
            }
            else
            {
                continue;
            }
        }
    }
    for (int l = 0; l < lowercase2.size(); l++)
    {
        for (int k = 0; k < out_of_order.size(); k++)
        {
            if (lowercase2[l] == out_of_order[k])
            {
                in_order += out_of_order[k];
                continue;
            }
        }
    }
    for (int m = 0; m < in_order.size(); m++)
    {
        cout << in_order[m] << ", ";
    }
    
    return 0;
}

