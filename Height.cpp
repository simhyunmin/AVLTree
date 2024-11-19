#include "OSAP_002_T6_source.h"

// Prints tree height, -1 if empty
void AvlTree::Height() const {
  if (root_ == nullptr) {
    cout << -1 << "\n";
    return;
  }

  cout << root_->height << "\n";
}

