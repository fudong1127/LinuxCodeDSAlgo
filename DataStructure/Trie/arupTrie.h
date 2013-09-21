/*
 * arupTrie.h
 *
 *  Created on: 24-Aug-2013
 *      Author: ArupMadhu
 */

#ifndef ARUPTRIE_H_
#define ARUPTRIE_H_

#include "vector"
#include "string"
#include "../common.h"

using    std::vector;
using    std::string;

#define NUM_CHILDREN        26
#define INDEX(c)            ((int)c - (int)'a')


class TrieNode;
typedef  vector<TrieNode*>* CHILDREN;

class TrieNode{
    private:
        bool bLeaf;

        CHILDREN children;

        TrieNode();

        bool isLeaf(void){
            return bLeaf;
        }

        bool hasChildren(void);

        friend class Trie;
    public:
        ~TrieNode();
};

class Trie{
    private:
        TrieNode* pRoot;

        unsigned int nCount;

        void initTrie(void){
            pRoot = new TrieNode();
            nCount = 0;
        }

        void Copy(TrieNode* pSrcNode,TrieNode* pDestNode);

        void insertKey(string key);

        bool searchKey(string key);

        bool deleteKey(string key);

        bool deleteHelper(TrieNode* pNode,string key,unsigned int index);

        void Empty(TrieNode* pNode);
    public:
        Trie(Trie* pNewTrie = NULL);

        ~Trie();

        int getKeyCount(void){
            return nCount;
        }

        bool isKeyPresent(string key);

        void insertKey(vector<string> stringList);

        void deleteKey(vector<string> stringList);

        bool isEmpty(void){
            return (getKeyCount() == 0);
        }
        void clear(void);
};

#endif /* ARUPTRIE_H_ */
