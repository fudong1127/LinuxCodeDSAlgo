#include "arupBSTree.h"

arupBSTreeNode* getMinBSTreeNode(arupBSTreeNode* root)
{
    while(root && root->left){
        root = root->left;
    }
    return root;
}
