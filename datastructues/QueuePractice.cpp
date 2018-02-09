/*

Name: QueuePractice.cpp

Creator: Adam Hock

Date Started: 12/19/2017

Description: This program was made to test the methods and functions of the
queue data structure. 
 
 */

#include <cstdlib>
#include <iostream>
#include "Queue.h"

bool isRotation(Queue *p, Queue *q)
{
    /*This function was created by Adam Hock. It returns true if queue p is 
      a rotation of queue q. */
    bool rotate = false;
    int x = p->getSize();
    int y = q->getSize();
    int a, b;
    int count;
    if (x != y)
        return false;
    for (int i = 0; i < x-1; i++)
    {
        count = 0;
        p->enqueue(p->dequeue());
        for (int j = 0; j < x; j++)
        {
            a = p->dequeue();
            b = q->dequeue();
            if (a == b)
                count++;
            p->enqueue(a);
            q->enqueue(b);
        }
        if (count == x)
            rotate = true;
    }
    p->enqueue(p->dequeue());
    return rotate;
}

int main(int argc, char** argv) 
{
    Queue *test = new Queue;
    test->enqueue(2);
    test->enqueue(3);
    test->enqueue(5);
    test->enqueue(7);
    std::cout << "Original" << std::endl;
    test->print();
    test->reverse();
    std::cout << "Reversed" << std::endl;
    test->print();
    test->lRotate(1);
    std::cout << "Rotated to the left once" << std::endl;
    test->print();
    test->rRotate(2);
    std::cout << "Rotated to the right twice" << std::endl;
    test->print();
    test->lRotate(2);
    std::cout << "Rotated to the left twice" << std::endl;
    test->print();
    test->rRotate(1);
    std::cout << "Rotated to the right once" << std::endl;
    test->print();
    
    Queue *test2 = new Queue;
    test2->enqueue(2);
    test2->enqueue(5);
    test2->enqueue(3);
    test2->enqueue(7);
    std::cout << "This is another queue that IS NOT a rotation of queue 1" << std::endl;
    test2->print();
    std::cout << isRotation(test, test2) << std::endl;
    std::cout << "These are the two queues after the test is complete" << std::endl;
    test->print();
    test2->print();
    
    Queue *test3 = new Queue;
    test3->enqueue(2);
    test3->enqueue(7);
    test3->enqueue(5);
    test3->enqueue(3);
    std::cout << "This is another queue that IS a rotation of queue 1" << std::endl;
    test3->print();
    std::cout << isRotation(test, test3) << std::endl;
    std::cout << "These are the two queues after the test is complete" << std::endl;
    test->print();
    test3->print();
    
    return 0;
}

