#include "OSAP_002_T6_source.h"

void AvlTree::Find(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    cout << ((node != nullptr) ? AvlTreeMetrics::CalculateDepth(node) + node->height : 0) << "\n";
}