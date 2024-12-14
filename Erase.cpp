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

// Find target node, delete it and rebalance if needed
AvlTree::Node* AvlTree::EraseNode(Node* node, int erase_data) {
  if (!node) {
    return nullptr;
  }
  if (erase_data < node->data) {
    node->left = EraseNode(node->left, erase_data);
  } else if (erase_data > node->data) {
    node->right = EraseNode(node->right, erase_data);
  } else {
    // Case 1: Node has at most one child
    if (!node->left || !node->right) {
      if (node->left && !(node->right)) {
        node->data = node->left->data;
        delete node->left;
        node->left = nullptr;
      } else if (!(node->left) && node->right) {
        node->data = node->right->data;
        delete node->right;
        node->right = nullptr;
      } else {
       // Leaf node case
        if (node->parent) {
          if (node->parent->left == node) {
            node->parent->left = nullptr;
          } else if (node->parent->right == node) {
            node->parent->right = nullptr;
          }
        }
        delete node;
        node = nullptr;
      }
    } 
    // Case 2: Node has two children
    else {
      Node* temp = AvlTreeUtils::FindSuccessor(node->right);
      node->data = temp->data;
      EraseNode(node->right, temp->data);
    }
  }
   // Update height/size and check balance
   // Avoid null pointer errors by rotating only when node is not nullptr.
  if (node) {
    AvlTreeMetrics::UpdateHeight(node);
    AvlTreeMetrics::UpdateSize(node);
    int balance = AvlTreeRotate::CalculateBalanceFactor(node);
    int left_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->left);
    int right_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->right);

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
  }
  return node;
}

// Erases value and prints sum of target node's height and depth
void AvlTree::Erase(int value_to_erase) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, value_to_erase);
  if (target_node == nullptr) {
    cout << 0 << "\n";
    return;
  }

  int depth_height_sum = target_node->height +
                       AvlTreeMetrics::CalculateDepth(target_node);
  cout << depth_height_sum << "\n";
  root_ = EraseNode(root_, value_to_erase);
}

