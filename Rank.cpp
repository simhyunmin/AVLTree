#include "OSAP_002_T6_source.h"

void AvlTree::Rank(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    if (node == nullptr) {//비어있을 경우 , 루트인 경우, 일반 경우
        cout << 0 << "\n";
        return;
    }

    int depth_plus_height_sum = AvlTreeMetrics::CalculateDepth(node) + node->height;
    cout << depth_plus_height_sum << " " << CalculateRank(root, x) << "\n";
}

int AvlTree::CalculateRank(Node* node, int x) {
    if (node == nullptr) {
        return 0;
    }

    if (x < node->data) {
        return CalculateRank(node->left, x);
    }
    else if (x > node->data) {
        return AvlTreeMetrics::GetSize(node->left) + 1 + CalculateRank(node->right, x);
    }
    else {
        return AvlTreeMetrics::GetSize(node->left) + 1;
    }
}