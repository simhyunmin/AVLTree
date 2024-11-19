#include "OSAP_002_T6_source.h"

// Prints average of min and max values in subtree rooted at target value
void AvlTree::Average(int target_value) {
  Node* sub_tree_root = AvlTreeUtils::FindNodeByValue(root_, target_value);
  
  Node* min_node = sub_tree_root;
  while (min_node->left != nullptr) {
    min_node = min_node->left;
  }

  Node* max_node = sub_tree_root;
  while (max_node->right != nullptr) {
    max_node = max_node->right;
  }
  
  int average = (min_node->data + max_node->data) / 2;
  cout << average << "\n";
}