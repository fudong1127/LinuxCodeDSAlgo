
#include "arupBSTree.h"

arupBSTreeNode* getMaxBSTreeNode(arupBSTreeNode* root)
{
    while(root && root->right){
        root = root->right;
    }
    return root;
}
