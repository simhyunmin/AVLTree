#include "OSAP_002_T6_source.h"

// Returns the depth (distance from root) of the given node by counting parent links
int AvlTreeMetrics::CalculateDepth(AvlTree::Node* node) {
  int depth = 0;
  if (node == nullptr) {
    return 0;
  }
  while (node->parent != nullptr) {
    node = node->parent;
    ++depth;
  }

  return depth;
}

// Updates node's height as max height between left and right child plus 1
void AvlTreeMetrics::UpdateHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->height = 1 + std::max(
    node->left ? GetHeight(node->left) : -1,
    node->right ? GetHeight(node->right) : -1
  );
}

// Updates node's size as sum of left and right subtree sizes plus 1
void AvlTreeMetrics::UpdateSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->size = 1 + GetSize(node->left) + GetSize(node->right);
}

// Returns node's height, -1 for null node
int AvlTreeMetrics::GetHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return -1;
  }
  return node->height;
}

// Returns node's size, 0 for null node
int AvlTreeMetrics::GetSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->size;
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