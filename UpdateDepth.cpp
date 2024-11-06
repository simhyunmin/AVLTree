#include "OSAP_002_T6_source.h"
int AvlTree::UpdateDepth(Node *node) {
  if (node == nullptr) { 
    return -1;
  }
  
  int depth = 0;
  Node *parent_node = node;

  while((parent_node = parent_node->parent) != nullptr) // 부모 노드로 거슬러 올라가며 depth 업데이트
    ++depth;
  
  node->depth = depth;

  return depth;
}