#ifndef STACKNODE_HPP
#define STACKNODE_HPP

#include <iostream>

using namespace std;

class StackNode
{
    public:
        StackNode* next;
        int item;
        StackNode(const int&,StackNode*);
       // ~StackNode();
};

#endif