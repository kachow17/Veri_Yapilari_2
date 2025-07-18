#ifndef BST_HPP
#define BST_HPP

#include"BSTNode.hpp"

class BST{
    public:
        BSTNode* root;
        int toplam;
        
        BST();
        ~BST();
        void searchAndAdd(BSTNode *&subNode,const int& newItem);
        bool searchAndDelete(BSTNode *&subNode,const int& data);
        bool deleteNode(BSTNode *&subNode);
        void postOrder(BSTNode *subNode);
        int height(BSTNode* subNode);
        void clear();
        bool isEmpty() const;
};

#endif
