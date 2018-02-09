/*

Name: NodePractice.cpp

Creator: Adam Hock

Date Started: 12/18/2017

Description: This program was used to test out my methods defined in the
Node.h header file.
 
 */

#include <cstdlib>
#include <iostream>
#include "Node.h"

int main(int argc, char** argv) {

    Node *head = new Node(2);
    head->add(3);
    head->add(5);
    head->add(7);
    head->print();
    head->rRotate();
    
    Node *head2 = new Node(2);
    head2->add(3);
    head2->add(5);
    head2->add(7);
    head2->lRotate();
    
    Node *head3 = new Node(2);
    head3->add(3);
    head3->add(5);
    head3->add(7);
    head3->reverse();
    
    Node *head4 = new Node(2);
    head4->add(3);
    head4->add(5);
    head4->add(7);
    head4->print();
    head4->mirrorImage();
    head4->print();
    return 0;
}

