#include "OSAP_002_T6_source.h"

void AvlTree::Rank(int x){
  Node* node = NodeFindByValue(root, x);
  if(node == nullptr){
    cout << 0 << endl;
  }
  int depth_plus_height_sum = node -> depth + node -> height;
  int node_rank = InorderTraversalByValue(root, x);

  cout << depth_plus_height_sum + node_rank << endl;
}