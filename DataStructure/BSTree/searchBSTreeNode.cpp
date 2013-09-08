#include "arupBSTree.h"

arupBSTreeNode* isRecPresent(arupBSTreeNode* pRoot,int key){
        if(!pRoot || key == pRoot->data)
            return pRoot;
        
        if(key < pRoot->data)
            return isRecPresent(pRoot->left,key);
        else
            return isRecPresent(pRoot->right,key);
}

arupBSTreeNode* isItrPresent(arupBSTreeNode* pRoot,int key){
        if(!pRoot || key == pRoot->data)
            return pRoot;
        
        while(pRoot && pRoot->data != key)
        {
           if(key < pRoot->data)
               pRoot = pRoot->left;
           else
               pRoot = pRoot->right;
        }                
        return pRoot;
}
arupBSTreeNode* searchBSTreeNode(arupBSTreeNode* root,int key,bool recursive){

    if(recursive){
       return isRecPresent(root,key); 
    }
    else{
        return isItrPresent(root,key);
    }
}
