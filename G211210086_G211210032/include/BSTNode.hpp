#ifndef BSTNODE_HPP
#define BSTNODE_HPP

#include<iostream>
using namespace std;

class BSTNode{
    public:
        int data;
        BSTNode* left;
        BSTNode* right;
        
        BSTNode(const int,BSTNode*,BSTNode*);
};

#endif