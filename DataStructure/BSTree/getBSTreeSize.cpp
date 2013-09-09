#include "arupBSTree.h"

unsigned int 
getBSTreeSize(arupBSTreeNode* root){
   if(!root)
       return 0;
   else{
        int ht_left_sub_tree  = getBSTreeSize(root->left);
        int ht_right_sub_tree = getBSTreeSize(root->right);

        return (1 + ht_left_sub_tree + ht_right_sub_tree);
   }
}
