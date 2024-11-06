#include "OSAP_002_T6_source.h"

void AvlTree::Height() const{
  if (root == nullptr) {
    cout << -1 << endl;
  } else {
    cout << root -> height << endl;
  }
}    