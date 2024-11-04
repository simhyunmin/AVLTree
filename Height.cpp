#include "OSAP_002_T6_source.h"

int AvlTree::Height() {
  if (head == nullptr) {
    cout << -1 << endl;
    return -1;
  } else {
    cout << head -> height << endl;
    return head -> height;
  }
}    