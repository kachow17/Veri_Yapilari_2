#ifndef STACK_HPP
#define STACK_HPP
#include "StackNode.hpp"


class Stack
{
    public:
        StackNode* topOfStack;
        Stack();
        bool isEmpty();
        void push(const int&);
        void pop();
        const int top();
        void makeEmpty();
        ~Stack();
};

#endif