/*
 
 Name: TileCost.cpp
 
 Creator: Adam Hock
 
 Date started: 11/16/2017
 
 Description: This program accepts a width and length of a floor and the length
 of each square tile. It outputs how many square tiles are needed to fill the
 room and how much spare room is left for the length and width. The user then
 inputs the cost of each tile, and the program outputs how much all the tiles
 will cost.
 
 Comments: This project was inspired by github user "karan" who created a "Mega 
 Project List" that features many projects that coders can work on for practice.
 The list for her projects can be found in the following link. 
 https://github.com/karan/Projects. 
  
 */

#include <cstdlib>
#include <iostream>

using namespace std;

/*
 This program accepts a width and length of a floor and the length of each square tile and outputs how many square
 tiles are needed to fill the room, and also shows how much spare room is left 
 for the length and width.
 * 
 The user then inputs the cost of each tile,
 and the program outputs how much it will cost. 
 */
int main(int argc, char** argv) {
    int length, width, Tlength, tiles; 
    double Ltiles, Wtiles, price, cost, Lspare, Wspare;
    cout << "Length of floor: ";
    cin >> length;
    cout << "Width of floor: ";
    cin >> width;
    cout << "Length of square tile: ";
    cin >> Tlength;
    if (Tlength == 0)
        cout << "Error!!!";
    Ltiles = (length/Tlength);
    Wtiles = (width/Tlength);
    tiles = Ltiles*Wtiles;
    Lspare = length - (Ltiles*Tlength);
    Wspare = width - (Wtiles*Tlength);
    cout << "You need " << tiles << " tiles to complete this project!" << endl;
    cout << "Once the tiles are placed, you will have " << Lspare << " units of";
    cout << " extra length and " << Wspare << " units of extra width" <<endl;
    cout << "/n how much does each tile cost (in dollars)?    $";
    cin >> price;
    cost = price*tiles;
    cout << "This project will cost you $" << cost << endl;
    
    
    return 0;
}

