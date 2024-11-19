#include "OSAP_002_T6_source.h"

void AvlTree::Size() const {
        if (root == nullptr) {
            cout << 0 << "\n";
            return;
        }
        cout << root->size << "\n";
    }