#include "OSAP_002_T6_source.h"
int AvlTree::UpdateHeight(Node *node) {
  if (node == nullptr) {
    return -1;
  }
  
  int height = max(UpdateHeight(node->left), UpdateHeight(node->right)) + 1;
  node->height = height;
    
  return height;
}