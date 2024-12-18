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

/**
 * @brief Calculate balance factor of node
 * @param node Target node
 * @return Balance factor (left height - right height)
 */
int AvlTreeRotate::CalculateBalanceFactor(AvlTree::Node *node) {
  if (node == nullptr) {
    return 0;
  }
  // make base to 0
  int left_height = (node->left) ? node->left->height : 0;
  int right_height = (node->right) ? node->right->height : 0;
  return left_height - right_height;
}

/**
 * @brief Find ancestor node that violates AVL balance property
 * @param node Starting node
 * @return Pointer to unbalanced node, nullptr if not found
 */
AvlTree::Node *AvlTreeRotate::FindUnbalancedNode(AvlTree::Node *node) {
  if (node == nullptr) {
    return nullptr;
  }
  int balance_factor = CalculateBalanceFactor(node);

  if (balance_factor < -1 || balance_factor > 1) {
    return node;
  }

  return FindUnbalancedNode(node->parent);
}

/**
 * @brief Perform right rotation around parent_node
 * @param parent_node Rotation pivot node
 * @return New root after rotation
 */
AvlTree::Node *AvlTreeRotate::RightRotate(AvlTree::Node *parent_node) {
  AvlTree::Node *child = parent_node->left;
  AvlTree::Node *child_right = child->right;

  // Perform rotation
  child->right = parent_node;
  parent_node->left = child_right;

  // Update parent pointers
  if (child_right) {
    child_right->parent = parent_node;
  }

  child->parent = parent_node->parent;
  parent_node->parent = child;

  // Fix parent's child pointer
  if (child->parent) {
    if (child->parent->left == parent_node) {
      child->parent->left = child;
    } else {
      child->parent->right = child;
    }
  }

  // Update height and size of affected nodes
  parent_node->height = max(AvlTreeMetrics::GetHeight(parent_node->left),
                            AvlTreeMetrics::GetHeight(parent_node->right)) +
                        1;

  child->height = max(AvlTreeMetrics::GetHeight(child->left),
                      AvlTreeMetrics::GetHeight(child->right)) +
                  1;

  AvlTreeMetrics::UpdateSize(parent_node);
  AvlTreeMetrics::UpdateSize(child);

  return child;
}

/**
 * @brief Perform left rotation around parent_node
 * @param parent_node Rotation pivot node
 * @return New root after rotation
 */
AvlTree::Node *AvlTreeRotate::LeftRotate(AvlTree::Node *parent_node) {
  AvlTree::Node *child = parent_node->right;
  AvlTree::Node *child_left = child->left;

  // Perform rotation
  child->left = parent_node;
  parent_node->right = child_left;

  // Update parent pointers
  if (child_left) {
    child_left->parent = parent_node;
  }

  child->parent = parent_node->parent;
  parent_node->parent = child;

  // Fix parent's child pointer
  if (child->parent) {
    if (child->parent->left == parent_node) {
      child->parent->left = child;
    } else {
      child->parent->right = child;
    }
  }

  // Update height and size of affected nodes
  parent_node->height = max(AvlTreeMetrics::GetHeight(parent_node->left),
                            AvlTreeMetrics::GetHeight(parent_node->right)) +
                        1;

  child->height = max(AvlTreeMetrics::GetHeight(child->left),
                      AvlTreeMetrics::GetHeight(child->right)) +
                  1;

  AvlTreeMetrics::UpdateSize(parent_node);
  AvlTreeMetrics::UpdateSize(child);

  return child;
}
