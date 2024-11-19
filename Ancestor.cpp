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

// Prints height+depth sum and path sum to root from parent
void AvlTree::Ancestor(int target_value) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int depth = AvlTreeMetrics::CalculateDepth(target_node);
  int height = target_node->height;
  int parent_path_sum = AvlTreeUtils::GetPathToRootSum(target_node->parent);
  
  cout << depth + height << " " << parent_path_sum << "\n";
}

