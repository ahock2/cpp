/*

Name: Node.h

Creator: Adam Hock

Date Started: 12/18/2017

Description: This header was created to help me practice the data structures
I learned in my C++ class that I took in the spring of 2017. The headers are
not mine. I used the header files created by my professor, Dennis 
Castleberry, to practice implementing some basic functions with this data 
structure. Methods that I have modified or created from scratch are denoted 
by a comment as the first line of said functions. The link to the original 
header files can be found here.

https://github.com/dcastl2/advanced-cpp/tree/master/notes/data

*/

#ifndef NODE_H
#define NODE_H

#include <cstdlib>
#include <iostream>

/**
 * The linked list is defined by a class Node, which contains a key and a 
 * pointer to the next node.  In this particular implementation, there is
 * no wrapper class (e.g. a class called List containing a head). The list
 * supports the adding of nodes to the back.
 */
class Node {

  private:
    int    key;
    Node *next;

  public:
    Node();
    Node(int key);
    void add(int key);
    void insert(int key);
    void print();
    /*These are the methods I created below*/
    bool hasCycle();
    void rRotate();
    void lRotate();
    void reverse();
    void mirrorImage();
};


/**
 * By default, a new Node has its next pointer pointing to NULL.
 */
Node::Node() {
  key  = 0;
  next = NULL;
}


/**
 * The constructor for a new node loads the key into the node and sets its
 * next pointer to NULL.
 * @param key  key to load
 */
Node::Node(int key) {
  this->key = key;
  next = NULL;
}


/**
 * The add method for a new node loads the key into a node and inserts it
 * at the back of the list.
 * @param key  key to load
 */
void Node::add(int key) {
  Node *pos = this;
  while (pos->next)
    pos = pos->next;
  Node *newtail = new Node(key);
  pos->next = newtail;
}


/**
 * Print the list, starting from the head until NULL is encountered.
 */
void Node::print() {
  Node *pos = this;
  while (pos) {
    std::cout << '\t' << pos->key;
    pos = pos->next;
  }
  std::cout << std::endl;
}


bool Node::hasCycle()
{
    /*This method was created by Adam Hock*/
    Node *A = this;
    Node *B = this;
    while (B->next && B->next->next)
    {
        B = B->next->next;
        A = A->next;
        if (A == B)
            return true;
    }
    return false;
}

void Node::rRotate()
{
    /*This method was created by Adam Hock*/
    Node *pos = this;
    Node *Adam = pos;
    while (Adam->next->next)
        Adam = Adam->next;
    Adam->next->next = pos;
    pos = Adam->next;
    Adam->next = NULL;
    pos->print();
}



void Node::lRotate()
{
    /*This method was created by Adam Hock*/
    Node *pos = this;
    Node *Adam = pos;
    while (Adam->next)
        Adam=Adam->next;
    Adam->next = pos;
    pos = pos->next;
    Adam->next->next = NULL;
    pos->print();
}

void Node::reverse()
{
    /*This method was created by Adam Hock*/
    Node *pos = this;
    Node *mid = pos;
    Node *right = pos->next;
    pos->next = NULL;
    while (right)
    {
        mid = right;
        right = right->next;
        mid->next = pos;
        pos = mid;
    }
    pos->print();
}

void Node::mirrorImage()
{
    /*This method was created by Adam Hock*/
    if(this->next)
        this->next->mirrorImage();
    int x = this->key;
    this->add(x);
}
#endif


/* NODE_H */

