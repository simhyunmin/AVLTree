#include "OSAP_002_T6_source.h"

int AvlTreeMetrics::CalculateDepth(AvlTree::Node* node) {
    int depth = 0;
    if (node == nullptr) {
        return 0;
    }
    while (node->parent != nullptr) {
        node = node->parent;
        ++depth;
    }

    return depth;
}

void AvlTreeMetrics::UpdateHeight(AvlTree::Node* node) {
    if (node) {
        node->height = 1 + std::max(node->left ? GetHeight(node->left) : -1, node->right ? GetHeight(node->right) : -1);
    }
    return;
}

void AvlTreeMetrics::UpdateSize(AvlTree::Node* node) {
    if (node) {
        node->size = 1 + AvlTreeMetrics::GetSize(node->left) + AvlTreeMetrics::GetSize(node->right);
    }
}

int AvlTreeMetrics::GetHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int AvlTreeMetrics::GetSize(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}