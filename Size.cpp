#include "OSAP_002_T6_source.h"

// Print total number of nodes in tree
void AvlTree::Size() const {
  if (root_ == nullptr) {
    cout << 0 << "\n";
    return;
  }
  cout << root_->size << "\n";
}