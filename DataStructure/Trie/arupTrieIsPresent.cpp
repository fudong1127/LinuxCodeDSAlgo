/*
 * arupTrieisPresent.cpp
 *
 *  Created on: 25-Aug-2013
 *      Author: ArupMadhu
 */

#include "arupTrie.h"

bool Trie::isKeyPresent(string key){
    if(key.empty() || !pRoot)
            return false;
    int level = 0;
    int height = key.length();
    TrieNode* pCurr = this->pRoot;

    for(level = 0; level < height;level++)
    {
        int index = INDEX(key[level]);
       CHILDREN pChildren = pCurr->children;

        if((*pChildren)[index] == NULL){
            return false;
        }
        pCurr = (*pChildren)[index];
    }
    return true;
}



