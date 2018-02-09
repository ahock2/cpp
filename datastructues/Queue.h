/*

Name: Queue.h

Creator: Adam Hock

Date Started: 12/19/2017

Description: This header was created to help me practice the data structures
I learned in my C++ class that I took in the spring of 2017. The headers are
not mine. I used the header files created by my professor, Dennis 
Castleberry, to practice implementing some basic functions with this data 
structure. Methods that I have modified or created from scratch are denoted 
by a comment as the first line of said functions. The link to the original 
header files can be found here.

https://github.com/dcastl2/advanced-cpp/tree/master/notes/data

*/


#ifndef QUEUE_H
#define QUEUE_H

#include <cstdlib>
#include <iostream>


/**
 * A QueueNode contains a key and a pointer to the next node in the queue.
 * The QueueNode constructor loads the key into the node.
 */
class QueueNode {
  public:
    int key;
    QueueNode *next;
    QueueNode(int);
};

QueueNode::QueueNode(int key) {
  this->key  = key;
  this->next = NULL;
}


/**
 * The Queue class has a pointer to the head (front) and tail (back) of the
 * queue.  It supports enqueue (add to back) and dequeue (remove from front)
 * operations.
 */
class Queue {
  private:
    QueueNode *head;
    QueueNode *tail;
    int size;
  public:
    Queue();
    void enqueue(int);
    int  dequeue();
    bool empty();
    int  getSize();
    void print();
    /*The following methods were created by Adam Hock*/
    Queue reverse();
    Queue lRotate(int);
    Queue rRotate(int);
};


/**
 * A new Queue has its head and tail pointers set to NULL.
 */
Queue::Queue() {
  head = tail = NULL;
  size = 0;
}


/**
 * A dequeue operation removes the node at the front of the queue and returns
 * the key that was in it.
 * @return  the key of the head node
 */
int Queue::dequeue() {
  int dekey = -1;
  QueueNode *newhead = head->next;
  if (size) {
    dekey = head->key;
    delete head;
    head  = newhead;
    size--;
  }
  return dekey;
}


/**
 * An enqueue operation adds a new node (with key) to the tail of the queue.
 * @param key  key to place in new node
 */
void Queue::enqueue(int key) {
  QueueNode *newtail = new QueueNode(key); 
  if (size) {
    tail->next = newtail;
    tail       = newtail;
  } else head = tail = newtail;
  size++;
}


/**
 * Tell if queue is empty.
 * @return  true if queue empty
 */
bool Queue::empty() {
  if (size)
    return false;
  return true;
}


/**
 * Return size of queue.
 * @return  size of queue
 */
int Queue::getSize() {
  return size;
}


/**
 * Print the queue, head to tail.
 */
void Queue::print() {
  QueueNode *node = head;
  while (node) {
    std::cout << '\t' << node->key;
    node = node->next;
  }
  std::cout<< "\n" << std::endl;
}

Queue Queue::reverse()
{
    /*This method was created by Adam Hock. It returns the reverse of a queue.*/
    Queue *Adam = this;
    QueueNode *Mid = Adam->head;
    QueueNode *Left = Mid;
    QueueNode *Right = Mid->next;
    Adam->head = Adam->tail;
    Adam->tail = Left;
    Left->next = NULL;
    while (Right)
    {
        Mid = Right;
        Right = Right->next;
        Mid->next = Left;
        Left = Mid;
    }
    return *Adam;
}

Queue Queue::lRotate(int n)
{
    /*This method was created by Adam Hock. It rotates the queue to the
    left by n-number of elements. */
    Queue *Adam = this;
    for (int i=0; i<n; i++)
        Adam->enqueue(Adam->dequeue());
    return *Adam;
}

Queue Queue::rRotate(int n)
{
    /*This method was created by Adam Hock. It rotates the queue to the 
    right by n-number of elements. */
    Queue *Adam = this;
    for (int i=0; i < Adam->size-n; i++)
        Adam->enqueue(Adam->dequeue());
    return *Adam;
}

#endif
