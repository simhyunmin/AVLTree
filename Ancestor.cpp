#include "OSAP_002_T6_source.h"
void AvlTree::Ancestor(int x) const{  
  Node *node = NodeFindByValue(root, x);
  
  int depth = node->depth;
  int height = node->height;
  int parent_path_sum = GetPathToRootSum(node->parent); 

  cout << depth + height << " " << parent_path_sum << endl;
}
