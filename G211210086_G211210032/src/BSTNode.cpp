/** 
* @file BST.cpp 
* @description BST sinifi
* @course 1-b
* @assignment 2
* @date 29.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*		  İrfan Eren Çiftçi irfan.ciftci1@ogr.sakarya.edu.tr	
*/
#include "BSTNode.hpp"

BSTNode::BSTNode(const int data, BSTNode* left = 0,BSTNode* right = 0){
    this->data = data;
    this->left = left;
    this->right = right;
}
