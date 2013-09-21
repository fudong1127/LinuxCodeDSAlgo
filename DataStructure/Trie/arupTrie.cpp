/*
 * arupTrie.cpp
 *
 *  Created on: 24-Aug-2013
 *      Author: ArupMadhu
 */

#include "arupTrie.h"

TrieNode::
TrieNode(){
    bLeaf = false;
    children = new vector<TrieNode*>(NUM_CHILDREN);
    for(unsigned int i = 0; i< NUM_CHILDREN;i++){
            (*children)[i] = NULL;
    }
}

TrieNode::
~TrieNode(){
    bLeaf = false;
    for(unsigned int i = 0; i< NUM_CHILDREN;i++){
            delete (*children)[i];
            (*children)[i] = NULL;
    }
}

bool TrieNode::
hasChildren(void){
    for(unsigned int i = 0; i< NUM_CHILDREN;i++){
        if((*children)[i])
                return true;
    }
    return false;
}

void Trie::
Copy(TrieNode* pSrcNode,TrieNode* pDestNode){
    CHILDREN pSrcChildren  = pSrcNode->children;
    CHILDREN pDestChildren = pDestNode->children;
    int size = (*pSrcChildren).size();

    pDestNode->bLeaf = pSrcNode->bLeaf;
    if(pDestNode->bLeaf)
        this->nCount++;

    for (int i = 0; i < size; i++) {
       TrieNode* pSrcCurrNode  =  (*pSrcChildren)[i];
       TrieNode* pDestCurrNode =  (*pDestChildren)[i];

       if(!pSrcCurrNode){
            pDestCurrNode = pSrcCurrNode;
       }
       else{
           (*pDestChildren)[i] = pDestCurrNode = new TrieNode();
           Copy(pSrcCurrNode,pDestCurrNode);
       }
    }
}

Trie::
Trie(Trie* pNewTrie){
    initTrie();
    if(pNewTrie && pNewTrie->pRoot){
       Copy(pNewTrie->pRoot,pRoot);
    }
}


Trie::
~Trie(){
    delete pRoot;
    nCount = 0;
}

void Trie::
clear(void){
    if(isEmpty())
        return;
    return Empty(this->pRoot);
}

