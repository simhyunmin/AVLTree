#include "OSAP_002_T6_source.h"

// Prints sum of target node's height and depth if found, 0 otherwise
void AvlTree::Find(int target_value) const {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int result = 0;
  
  if (target_node != nullptr) {
    result = AvlTreeMetrics::CalculateDepth(target_node) + 
             target_node->height;
  }
  
  cout << result << "\n";
}

