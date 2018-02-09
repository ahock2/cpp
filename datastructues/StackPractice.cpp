/*

Name: StackPractice.cpp

Creator: Adam Hock

Date Started: 12/18/2017

Description: This program contains functions that I created to practice using
the stack data structure. All of these functions that are written are mine, but
the header file was written by Dennis Castleberry. The link to his data
structure headers can be found in the link below. 

https://github.com/dcastl2/advanced-cpp/tree/master/notes/data

*/

#include <cstdlib>
#include <iostream>
#include "Stack.h"

Stack upRotate(Stack *s)
{
    int x = s->pop();
    Stack *Adam = new Stack;
    while (!s->empty())
        Adam->push(s->pop());
    Adam->push(x);
    while (!Adam->empty())
        s->push(Adam->pop());
    return *s;
}

Stack downRotate(Stack *s)
{
    int x;
    Stack *Adam = new Stack;
    while (!s->empty())
        Adam->push(s->pop());
    x = Adam->pop();
    while (!Adam->empty())
        s->push(Adam->pop());
    s->push(x);
    return *s;
}

bool isPalindrome(Stack *s)
{
    Stack *Adam = new Stack;
    int x, y;
    while (!s->empty())
    {
        x = s->pop();
        if (s->empty())
            return true;
        while (!s->empty())
            Adam->push(s->pop());
        y= Adam->pop();
        if (x != y)
            return false;
        while (!Adam->empty())
            s->push(Adam->pop());
    }
    return true;
}

void drop(Stack *s)
{
    if(!s->empty())
    {
        Stack *Adam = new Stack;
        while (!s->empty())
            Adam->push(s->pop());
        int x = Adam->pop();
        while (!Adam->empty())
            s->push(Adam->pop());
        drop(s);
        std::cout << x << " blah blah recursion " << std::endl;
    }
}
/*
 This program is to help me practice working with stacks 
 */
int main(int argc, char** argv) {

    Stack *test = new Stack;
    test->push(7);
    test->push(5);
    test->push(3);
    test->push(2);
    test->print();
    upRotate(test);
    test->print();
    downRotate(test);
    test->print();
    downRotate(test);
    test->print();
    std::cout << isPalindrome(test) << std::endl;
    
    Stack *test2 = new Stack;
    test2->push(7);
    test2->push(5);
    test2->push(5);
    test2->push(7);
    test2->print();
    std::cout << isPalindrome(test2) << std::endl;
    
    Stack *test3 = new Stack;
    test3->push(7);
    test3->push(5);
    test3->push(3);
    test3->push(2);
    test3->push(7);
    test3->print();
    std::cout << isPalindrome(test3) << std::endl;
    
    Stack *test4 = new Stack;
    test4->push(7);
    test4->push(5);
    test4->push(3);
    test4->push(5);
    test4->push(7);
    test4->print();
    std::cout << isPalindrome(test4) << std::endl;
    
    Stack *test5 = new Stack;
    test5->push(7);
    test5->push(5);
    test5->push(3);
    test5->push(2);
    drop(test5);
    return 0;
}

