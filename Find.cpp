#include "OSAP_002_T6_source.h"

void AvlTree::Find(int x) {
  Node *node = NodeFindByValue(root, x);
  cout << ((node != nullptr) ? node->depth + node->height : 0) << "\n";
}