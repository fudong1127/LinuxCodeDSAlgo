#include "arupBSTree.h"

unsigned int getBSTreeSize(arupBSTreeNode* root){
   if(!root)
       return 0;
   else{
        return (1 + 
               getBSTreeSize(root->left) + 
               getBSTreeSize(root->right));
   }
}
