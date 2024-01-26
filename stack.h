//
// Created by EXCALIBUR on 24.10.2023.
//
//ismetayvazoglu 29493

#include "cell.h"
using namespace std;

#ifndef CS300_HW1_STACK_H
#define CS300_HW1_STACK_H

template <class Object>
class Stack //mostly taken from course slides
{
private:

   struct node{
       Object obj;
       node *next;
       node(const Object & element, node * n = nullptr)
               : obj(element), next(n) {}
   };
   node* top;

public:

    Stack();
    ~Stack();
    void push(const Object& x);
    void pop();
    bool isEmpty();
    Object at_top();
    void makeEmpty();
};

#include "stack.cpp"
#endif //CS300_HW1_STACK_H
