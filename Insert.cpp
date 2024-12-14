/*
MIT License

Copyright (c) 2024 INHA_OSAP_002_T6

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

Author: INHA_OSAP_002_T6
Date: 2024-11-20
*/

#include "OSAP_002_T6_source.h"

// Binary search to insertion point and rebalance if needed
AvlTree::Node* AvlTree::InsertNode(AvlTree::Node* node, int insert_data,
                                int& depth_height_sum, int depth) {
  if (!node) {
    depth_height_sum = depth + 1;
    return new Node(insert_data);
  }

  // Find insertion position using binary search
  if (insert_data < node->data) {
    node->left = InsertNode(node->left, insert_data,
                         depth_height_sum, depth + 1);
    node->left->parent = node;
  } else if (insert_data > node->data) {
    node->right = InsertNode(node->right, insert_data,
                          depth_height_sum, depth + 1);
    node->right->parent = node;
  }

  // Update node properties
  AvlTreeMetrics::UpdateHeight(node);
  AvlTreeMetrics::UpdateSize(node);

  // Check balance factors
  int balance = AvlTreeRotate::CalculateBalanceFactor(node);
  int left_child_balance =
    AvlTreeRotate::CalculateBalanceFactor(node->left);
  int right_child_balance =
    AvlTreeRotate::CalculateBalanceFactor(node->right);

  // Single right rotation
  if (balance > 1 && left_child_balance >= 0) {
    return AvlTreeRotate::RightRotate(node);
  }

  // Single left rotation
  if (balance < -1 && right_child_balance <= 0) {
    return AvlTreeRotate::LeftRotate(node);
  }
  // Left-Right rotation
  if (balance > 1 && left_child_balance < 0) {
    AvlTreeRotate::LeftRotate(node->left);
    return AvlTreeRotate::RightRotate(node);
  }
  // Right-Left rotation
  if (balance < -1 && right_child_balance > 0) {
    AvlTreeRotate::RightRotate(node->right);
    return AvlTreeRotate::LeftRotate(node);
  }

  return node;
}

// Inserts value and prints sum of inserted node's height and depth
void AvlTree::Insert(int insert_data) {
  int depth_height_sum = 0;
  
  Node* current_node = AvlTreeUtils::FindNodeByValue(root_, insert_data);
  if (current_node != nullptr) {
    return;
  }
  root_ = InsertNode(root_, insert_data, depth_height_sum, -1);
  Node* found_node = AvlTreeUtils::FindNodeByValue(root_, insert_data);
  cout << found_node->height + AvlTreeMetrics::CalculateDepth(found_node) 
    << "\n";
}

