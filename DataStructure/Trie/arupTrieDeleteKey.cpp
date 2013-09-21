/*
 * arupTrieDeleteKey.cpp
 *
 *  Created on: 25-Aug-2013
 *      Author: ArupMadhu
 */

#include "arupTrie.h"

bool Trie::
deleteHelper(TrieNode* pNode,string key,unsigned int index){
    bool bRet = false;
    if(pNode)
    {
        if(index == key.length() - 1)
        {
            if(pNode->isLeaf()){
                pNode->bLeaf = false;
                this->nCount--;
            }
            bool bHasChildren = pNode->hasChildren();
            bRet = !bHasChildren;
        }else
        {
            CHILDREN child_list = pNode->children;
            int i = INDEX(key[index + 1]);
            TrieNode* pCurrNode = (*child_list)[i];
            bRet = deleteHelper(pCurrNode,key,index + 1);

            if(bRet)
            {
                (*child_list)[i] = NULL;
                delete pCurrNode;
                bRet = !pNode->hasChildren();
            }

        }
    }
    return bRet;
}


bool Trie::
deleteKey(string key){
    bool bRet = false;
    if(key.length() == 0)
    {
      bRet = false;
    }else if(pRoot && pRoot->children)
    {
        CHILDREN children = pRoot->children;
        int i = INDEX(key[0]);
        TrieNode* pCurrNode = (*children)[i];
        bRet = deleteHelper(pCurrNode,key,0);
    }
    return bRet;
}

void Trie::
deleteKey(vector<string> stringList){
    for(unsigned int i = 0; i < stringList.size();i++){
            deleteKey(stringList[i]);
        }
}
