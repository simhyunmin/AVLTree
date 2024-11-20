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

/*
MIT License

Copyright (c) 2024 Your Name

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/