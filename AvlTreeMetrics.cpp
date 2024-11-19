#include "OSAP_002_T6_source.h"

// Returns the depth (distance from root) of the given node by counting parent links
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

// Updates node's height as max height between left and right child plus 1
void AvlTreeMetrics::UpdateHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->height = 1 + std::max(
    node->left ? GetHeight(node->left) : -1,
    node->right ? GetHeight(node->right) : -1
  );
}

// Updates node's size as sum of left and right subtree sizes plus 1
void AvlTreeMetrics::UpdateSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->size = 1 + GetSize(node->left) + GetSize(node->right);
}

// Returns node's height, -1 for null node
int AvlTreeMetrics::GetHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return -1;
  }
  return node->height;
}

// Returns node's size, 0 for null node
int AvlTreeMetrics::GetSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->size;
}