#include "OSAP_002_T6_source.h"

void AvlTree::Find(int x) {
  Node *node = NodeFindByValue(root, x);

  if (node != nullptr) {
    cout << node->depth + node->height << "\n";
    return;
  }
  cout << "0" << "\n";
}