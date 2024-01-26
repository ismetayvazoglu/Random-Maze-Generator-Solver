//
// Created by EXCALIBUR on 24.10.2023.
//
//ismetayvazoglu 29493

#include "stack.h"

template <class Object>
Stack<Object>::Stack()
{
    top = nullptr;
}

template <class Object>
bool Stack<Object>::isEmpty()
{
    return (top == nullptr);
}

template <class Object>
void Stack<Object>::pop()
{
    if(!(isEmpty())) {
        node *oldTop = top;
        top = top->next;
        delete oldTop;
    }
}

template <class Object>
void Stack<Object>::push(const Object & x)
{
    top = new node(x, top);
}

template <class Object>
Object Stack<Object>::at_top() {
    return this->top->obj;
}

template <class Object>
void Stack<Object>::makeEmpty()
{
    while (!isEmpty()) {
        pop();
    }
}

template <class Object>
Stack<Object>::~Stack()
{
    makeEmpty();
}


