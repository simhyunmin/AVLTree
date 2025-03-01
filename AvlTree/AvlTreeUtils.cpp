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
 * @brief Calculate sum of node values from current node to root
 * @param node Starting node for path calculation
 * @return Sum of values in path to root
 */
int AvlTreeUtils::GetPathToRootSum(AvlTree::Node *node) {
  int key_sum = 0;

  while (node != nullptr) {
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}

/**
 * @brief Find successor node (smallest value in right subtree)
 * @param node Starting node to find successor
 * @return Pointer to successor node, nullptr if not found
 */
AvlTree::Node *AvlTreeUtils::FindSuccessor(AvlTree::Node *node) {
  if (node == nullptr) {
    return node;
  }
  AvlTree::Node *temp = node;
  while (temp && temp->left != nullptr) {
    temp = temp->left;
  }
  return temp;
}

/**
 * @brief Find node with specific value using binary search
 * @param node Root node to start search
 * @param find_data Value to find
 * @return Pointer to found node, nullptr if not found
 */
AvlTree::Node *AvlTreeUtils::FindNodeByValue(AvlTree::Node *node,
                                             int find_data) {
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