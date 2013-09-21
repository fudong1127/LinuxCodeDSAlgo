/*
 * arupTrieIinsertKey.cpp
 *
 *  Created on: 25-Aug-2013
 *      Author: ArupMadhu
 */
#include "arupTrie.h"

void Trie::
insertKey(string key){
    if(key.empty())
        return;
    int level = 0;
    int height = key.length();
    TrieNode* pCurr = this->pRoot;

    for(level = 0; level < height;level++)
    {
        int index = INDEX(key[level]);
        CHILDREN pChildren = pCurr->children;

        if((*pChildren)[index] == NULL){
            (*pChildren)[index] = new TrieNode();
        }
        pCurr = (*pChildren)[index];
    }
    if(!pCurr->bLeaf){
        pCurr->bLeaf = true;
        this->nCount++;
    }
}

void Trie::insertKey(vector<string> stringList){
    for(unsigned int i = 0; i < stringList.size();i++){
        insertKey(stringList[i]);
    }
}



