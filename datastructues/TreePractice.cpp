/*

Name: TreePractice.cpp

Creator: Adam Hock

Date Started: 12/19/2017

Description: This program was used to practice the methods I created in
my Tree.h header file. 
 
 */

#include <cstdlib>
#include <iostream>
#include "Tree.h"

using namespace std;

int main(int argc, char** argv) {
  
  int x[6] = {7, 3, 11, 2, 5, 13};
  Tree *t = new Tree(x, 6);
  t->preOrder();
  t->postOrder();
  t->inOrder();
  t->reverse();
  cout << t->height() << endl;
  cout << t->size() << endl;
  t->preOrder();
    return 0;
}

