#include "main.h"
#define   PROPER_TREE       0
#define   PROPER_VECTOR     1
#define   PROPER_LIST       2

ABSTN* getBSTree(int type,void* pContainer = NULL);

ABSTN* 
getBSTree(int type,void* pContainer){
    ABSTN* pTree = NULL;
    switch(type)
    {
        case PROPER_TREE:{
                ABSTN* node1 = new ABSTN(1,NULL,NULL,NULL);        
                ABSTN* node2 = new ABSTN(2,NULL,NULL,NULL);        
                ABSTN* node3 = new ABSTN(3,NULL,NULL,NULL);

                node2->parent = NULL;
                node2->left   = node1;
                node2->right  = node3;
                
                node1->parent = node2;
                node3->parent = node2;

                pTree = node2;
                
                node1 = node2 = node3 = NULL;
            }break;
        case PROPER_VECTOR:{
            //vector<int>* pVector = (vector<int>*)pContainer; 
            //pVector = NULL;
            }break;
        case PROPER_LIST:{
            //list<int>* plist = (list<int>*)pContainer; 
            }break;
        default:
            std::cout<<"Invalid type of tree!!"<<std::endl;
    }
    return pTree;
}
int 
main(int argc,char** argv){
     ABSTN* pRoot = NULL;
     string message = "";

     if((pRoot = getBSTree(PROPER_TREE)))
     {
        //Find the node with the minimum key in the BST
        if(pRoot){
           bool isRec = true;
           message = "minimum data: ";
           cout<<message<<getMinBSTreeNode(pRoot,isRec)->data<<endl;
        }
        
        //Find the node with the maximum key in the BST
        if(pRoot){
           bool isRec = true;
           message = "maximum data: ";
           cout<<message<<getMaxBSTreeNode(pRoot,isRec)->data<<endl; 
        }
        
        //Find the node with the specified key in the BST
        if(pRoot){
            ABSTN* pNode = NULL;
            int key = 1;
            bool isRec = true;

            pNode   = searchBSTreeNode(pRoot,key,isRec); 
            message = (pNode == NULL)?("key not present"):("key is present");
            cout<<message<<endl;
        }
        
        //Find total number of nodes in the BST
        if(pRoot){
            message = "size of the BSTree: ";
            cout<<message<<getBSTreeSize(pRoot)<<endl;
        }
     }
     DELETE(pRoot);
    return 0;
}

