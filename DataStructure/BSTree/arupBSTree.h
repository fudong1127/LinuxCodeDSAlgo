#ifndef __ARUPBTREE_H__
#define __ARUPBTREE_H__
#include "iostream"
#include "../common.h"

class arupBSTreeNode{
        public:
            int data;

            arupBSTreeNode* left;
            
            arupBSTreeNode* right;
            
            arupBSTreeNode* parent;

            arupBSTreeNode(int data,
                           arupBSTreeNode* pLeft,
                           arupBSTreeNode* pRight,
                           arupBSTreeNode* pParent = NULL)
            {
                this->data      = data;
                this->left      = pLeft;
                this->right     = pRight;
                this->parent    = pParent;
            }
            ~arupBSTreeNode()
            {
                if(this->left){
                    DELETE(this->left);
                }
                if(this->right){
                    DELETE(this->right);
                }
                if(this->parent){
                    this->parent = NULL;                   
                }
            }
};
#endif
