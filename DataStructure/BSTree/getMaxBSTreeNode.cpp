
#include "arupBSTree.h"

arupBSTreeNode* 
getRecMaxBSTreeNode(arupBSTreeNode* root){
    arupBSTreeNode* pNode = root;
    if(pNode && pNode->right){
        pNode = getRecMaxBSTreeNode(pNode->right);
    }
    return pNode;
}

arupBSTreeNode* 
getItrMaxBSTreeNode(arupBSTreeNode* root){
    while(root && root->right){
        root = root->right;
    }
    return root;
}

arupBSTreeNode* 
getMaxBSTreeNode(arupBSTreeNode* root,bool isRec)
{
    if(isRec)
        return getRecMaxBSTreeNode(root);         
    return getItrMaxBSTreeNode(root);
}
