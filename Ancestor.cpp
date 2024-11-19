#include "OSAP_002_T6_source.h"

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
    int key_sum = 0;

    while (node != nullptr) {
        key_sum += node->data;
        node = node->parent;
    }

    return key_sum;
}

void AvlTree::Ancestor(int x) {//존재하는 값
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    int depth = AvlTreeMetrics::CalculateDepth(node);
    int height = node->height;
    int parent_path_sum = AvlTreeUtils::GetPathToRootSum(node->parent);
    cout << depth + height << " " << parent_path_sum << "\n";
}

