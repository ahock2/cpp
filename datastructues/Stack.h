/*

Name: Stack.h

Creator: Adam Hock

Date Started: 12/18/2017

Description: This header was created to help me practice the data structures
I learned in my C++ class that I took in the spring of 2017. The headers are
not mine. I used the header files created by my professor, Dennis 
Castleberry, to practice implementing some basic functions with this data 
structure. The link to the original header files can be found here.

https://github.com/dcastl2/advanced-cpp/tree/master/notes/data

*/

#ifndef STACK_H
#define STACK_H

#include <cstdlib>
#include <iostream>


/**
 * StackNode class: contains key and pointer to next node. Constructor creates
 * new node and loads key into it.
 */
class StackNode {
  public:
    int key;
    StackNode *next;
    StackNode(int);
};

StackNode::StackNode(int key) {
  this->key  = key;
  this->next = NULL;
}


/**
 * Stack class: contains pointer to top node. Constructor sets top node to NULL.
 * Supports push, pop, peek operations.  Pop adds a node to the top of the stack;
 * push removes node from the top of the stack and returns its key.  Peek views
 * the key of the node on the top of the stack.
 */
class Stack {
  private:
    StackNode *top;
  public:
    Stack();
    void push(int);
    int  peek();
    int  pop();
    bool empty();
    void print();
};


Stack::Stack() {
  top = NULL;
}


/**
 * Delete top node and return key.
 * @return  the key of the top node
 */
int Stack::pop() {
  int popkey = -1;
  StackNode *popme = top;
  if (top)
    popkey = top->key;
  top = popme->next;
  delete popme; 
  return popkey;
}


/**
 * Add node to top of the stack.
 * @param key  key to insert into new top node
 */
void Stack::push(int key) {
  StackNode *newtop = new StackNode(key); 
  newtop->next = top;
  top = newtop;
}


/**
 * Delete top node and return key.
 * @return  the key of the top node
 */
int Stack::peek() {
  int key = -1;
  if (top)
    key = top->key;
  return key;
}


/**
 * Tell if stack is empty.
 * @return  true if stack is empty
 */
bool Stack::empty() {
  if (top)
    return false;
  return true;
}


/**
 * Print the stack from top to bottom.
 */
void Stack::print() {
  StackNode *node = top;
  while (node) {
    std::cout << '\t' << node->key;
    node = node->next;
  }
  std::cout << "\n" << std::endl;
}

#endif /* STACK_H */

