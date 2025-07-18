/** 
* @file BST.cpp 
* @description BST sinifi
* @course 1-b
* @assignment 2
* @date 29.07.2023
* @author Mert Çalışkan mert.caliskan3@ogr.sakarya.edu.tr
*		  İrfan Eren Çiftçi irfan.ciftci1@ogr.sakarya.edu.tr	
*/
#include "BST.hpp" 

BST::BST(){
    root=NULL;
	toplam = 0;
}
void BST::searchAndAdd(BSTNode *&subNode,const int& newItem){
    if(subNode == NULL)
	{
		subNode = new BSTNode(newItem,0,0);
		toplam+=newItem;
	} 
	else if(newItem < subNode->data)
	{
		searchAndAdd(subNode->left,newItem);
	}
	else if(newItem > subNode->data)
	{
		searchAndAdd(subNode->right,newItem);
	}
	else return;
}

bool BST::searchAndDelete(BSTNode *&subNode,const int& data){
    if(subNode == NULL) return false;
	if(subNode->data == data) return deleteNode(subNode);
	else if(data < subNode->data) return searchAndDelete(subNode->left,data);
	else return searchAndDelete(subNode->right,data);
}

bool BST::deleteNode(BSTNode *&subNode){
    BSTNode *DelNode = subNode;
			
	if(subNode->right == NULL) subNode = subNode->left;
	else if(subNode->left == NULL) subNode = subNode->right;
	else{
		DelNode = subNode->left;
		BSTNode *parent = subNode;
		while(DelNode->right != NULL){
			parent = DelNode;
			DelNode = DelNode->right;
		}
		subNode->data = DelNode->data;
		if(parent == subNode) subNode->left = DelNode->left;
		else parent->right = DelNode->left;
	}
	delete DelNode;
	return true;
}

void BST::postOrder(BSTNode *subNode){
	if(subNode != NULL){
				postOrder(subNode->left);
				postOrder(subNode->right);
				cout<<char(subNode->data)<<" ";
			}
}
 int BST::height(BSTNode* subNode){
	if(subNode == NULL) return -1;
		return 1+max(height(subNode->left),height(subNode->right));
}

bool BST::isEmpty() const{
	return root == NULL;
}

void BST::clear(){
	while(!isEmpty()) 
	{
		deleteNode(root);
		//cout<<"gidiom"<<endl;
	}
}

BST::~BST(){
	clear();
}