/*
 * main.cpp
 *
 *  Created on: 24-Aug-2013
 *      Author: ArupMadhu
 */

#include "iostream"
#include "arupTrie.h"
#include "common.h"

using    std::cout;
using    std::endl;

int 
main(int argc,char** argv){
    Trie* pTrie = new Trie();
    string strList[] = {"hi", "there","arup","madhu","good","arghyo","better","best","betterthanbest","awsome","getalife"};
    vector<string> stringList;

    for(unsigned int i = 0; i< SIZE(strList);i++){
        stringList.push_back(strList[i]);
    }
    pTrie->insertKey(stringList);

    for(unsigned int i = 0; i< stringList.size();i++){
        cout<<"check if "<<stringList[i]<<" is present:"<<pTrie->isKeyPresent(stringList[i])<<endl;
    }
    cout<<"Total number of entries in the trie: "<<pTrie->getKeyCount()<<endl;

    cout<<"Deleting all entries in the trie: "<<endl;
    //pTrie->deleteKey(stringList);

    //pTrie->clear();

    cout<<"Total number of entries in the trie: "<<pTrie->getKeyCount()<<endl;
    cout<<endl<<pTrie->getKeyCount()<<endl;

    Trie* pNewTrie = new Trie(pTrie);

    cout<<"Total number of entries in the trie: "<<pNewTrie->getKeyCount()<<endl;

    delete pTrie;
    delete pNewTrie;

    pTrie    = NULL;
    pNewTrie = NULL;
    
    return 0;
}



