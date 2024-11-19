#include "OSAP_002_T6_source.h"


// Calculates sum of node values from current node to root by following parent links
int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
  int key_sum = 0;

  while (node != nullptr) {
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}

// Finds leftmost node in the subtree (smallest value successor) of given node
AvlTree::Node* AvlTreeUtils::FindSuccessor(AvlTree::Node* node) {
  if (node == nullptr) {
    return node;
  }
  AvlTree::Node* temp = node;
  while (temp && temp->left != nullptr) {
    temp = temp->left;
  }
  return temp;
}

// Traverses tree to find node with given value using binary search
AvlTree::Node* AvlTreeUtils::FindNodeByValue(AvlTree::Node* node, int find_data) {
  while (node != nullptr) {
    if (node->data == find_data) {
      return node;
    } else if (node->data > find_data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return node;
}