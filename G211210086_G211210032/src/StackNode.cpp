/** 
* @file BST.cpp 
* @description BST sinifi
* @course 1-b
* @assignment 2
* @date 29.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*		  İrfan Eren Çiftçi irfan.ciftci1@ogr.sakarya.edu.tr	
*/
#include "StackNode.hpp"

StackNode::StackNode(const int& item,StackNode* next)
{
    this->item = item;
    this->next = next;
}

// StackNode::~StackNode()
// {
//     //cout<<"yok oldum"<<endl;
// }