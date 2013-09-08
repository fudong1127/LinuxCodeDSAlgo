#ifndef _MAIN_H_
#define _MAIN_H_
#include "iostream"
#include "vector"
#include "string"
//#include "list.h"
#include "arupBSTree.h"   
    
using std::cout;
using std::cin;
using std::endl;
using std::vector;
using std::string;


typedef arupBSTreeNode ABSTN;


ABSTN* getMinBSTreeNode(ABSTN* root);

ABSTN* getMaxBSTreeNode(ABSTN* root);

ABSTN* searchBSTreeNode(ABSTN* root,int key,bool recursive = false);

unsigned int getBSTreeSize(ABSTN* root);
#endif
