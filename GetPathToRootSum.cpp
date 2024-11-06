#include "OSAP_002_T6_source.h"
int AvlTree::GetPathToRootSum(Node *node) const{  
  int key_sum = 0;

  while(node != nullptr) {   // 부모 노드로 거슬러 올라가며 key값 더함
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}
