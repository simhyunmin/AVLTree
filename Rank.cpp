#include "OSAP_002_T6_source.h"

// Prints sum of node's depth and height, and its rank (or 0 if node not found)
void AvlTree::Rank(int target_value) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  if (target_node == nullptr) {
    cout << 0 << "\n";
    return;
  }

  int depth_plus_height = AvlTreeMetrics::CalculateDepth(target_node) + 
                         target_node->height;
  int rank_value = CalculateRank(root_, target_value);
  
  cout << depth_plus_height << " " << rank_value << "\n";
}

// Calculate rank using binary search traversal
int AvlTree::CalculateRank(Node* current_node, int target_value) {
  if (current_node == nullptr) {
    return 0;
  }

  if (target_value < current_node->data) {
    return CalculateRank(current_node->left, target_value);
  }
  else if (target_value > current_node->data) {
    return AvlTreeMetrics::GetSize(current_node->left) + 1 + 
            CalculateRank(current_node->right, target_value);
  }
  else {
    return AvlTreeMetrics::GetSize(current_node->left) + 1;
  }
}