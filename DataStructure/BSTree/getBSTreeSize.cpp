#include "arupBSTree.h"

unsigned int 
getBSTreeSize(arupBSTreeNode* root)
{
  if(root)
  {
      return (1 + getBSTreeSize(root->left) + getBSTreeSize(root->right));
  }
  return 0;
}
