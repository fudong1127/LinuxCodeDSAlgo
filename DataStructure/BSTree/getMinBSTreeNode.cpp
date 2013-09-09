#include "arupBSTree.h"

arupBSTreeNode* 
getRecMinBSTreeNode(arupBSTreeNode* root){
    arupBSTreeNode* pNode = root;
    if(pNode && pNode->left){
        pNode = getRecMinBSTreeNode(pNode->left);
    }
    return pNode;
}

arupBSTreeNode* 
getItrMinBSTreeNode(arupBSTreeNode* root){
    while(root && root->left){
        root = root->left;
    }
    return root;
}


arupBSTreeNode* 
getMinBSTreeNode(arupBSTreeNode* root,bool isRec)
{
    if(isRec){
        return getRecMinBSTreeNode(root);         
    }else{
        return getItrMinBSTreeNode(root);
    }
}
