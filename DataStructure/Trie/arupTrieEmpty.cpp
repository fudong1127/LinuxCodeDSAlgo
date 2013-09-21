/*
 * arupTrieEmpty.cpp
 *
 *  Created on: 25-Aug-2013
 *      Author: ArupMadhu
 */


#include "arupTrie.h"

void Trie::
Empty(TrieNode* pNode){
    if(pNode){
       CHILDREN children = ((pNode->children)?pNode->children:NULL);
        for(unsigned int i = 0; i < NUM_CHILDREN && children ;i++){

            TrieNode* pCurrNode = (*children)[i];
            if(pCurrNode){
                Empty(pCurrNode);
                if(pCurrNode->isLeaf()){
                    pCurrNode->bLeaf = false;
                    this->nCount--;
                }

                delete pCurrNode;
                (*children)[i] = NULL;
            }
        }
    }
}


