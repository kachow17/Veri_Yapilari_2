/** 
* @file BST.cpp 
* @description BST sinifi
* @course 1-b
* @assignment 2
* @date 29.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*		  İrfan Eren Çiftçi irfan.ciftci1@ogr.sakarya.edu.tr	
*/
#include "Stack.hpp"

Stack::Stack()
{
    topOfStack = NULL;
}
bool Stack::isEmpty()
{
    return topOfStack == NULL;
}

void Stack::push(const int& item)
{
    topOfStack = new StackNode(item,topOfStack);
}

void Stack::pop(){
    if(isEmpty()) throw "Stack is Empty";
    StackNode *tmp = topOfStack;
    topOfStack = topOfStack->next;
    delete tmp;
}

const int Stack::top() 
{
    if(isEmpty()) throw "Stack is Empty";
    return topOfStack->item;
}

void Stack::makeEmpty()
{
	while(!isEmpty()) pop();
}

Stack::~Stack()
{
    makeEmpty();
}