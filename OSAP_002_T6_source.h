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

#ifndef OSAP_002_T6_SOURCE_H
#define OSAP_002_T6_SOURCE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class AvlTree {
public:
  AvlTree() : root_(nullptr) {};
  ~AvlTree() { Clear(root_); };

  struct Node {
    int data;
    int height;
    int size;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value) : data(value), height(0), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
  };
  // Tree Management
  void Clear(Node* node); 

  // Basic Tree Operations
  void Find(int x)const;
  void Empty() {cout << ((root_ == nullptr) ? 1 : 0) << "\n";}
  void Size() const;
  void Height() const;

  // Traversal and Statistics
  void Ancestor(int x);
  void Average(int x);

  // Insertion Operations
  Node* InsertNode(Node* node, int x, int& depth_height_sum, int depth);
  void Insert(int x);

  // Deletion Operations
  Node* EraseNode(Node* node, int x);
  void Erase(int x);

  // Ranking Operations
  void Rank(int x);
  int CalculateRank(Node* node, int x);

  // Tree Visualization/Debugging
  void PrintTreeRecursive(Node* node, string prefix, bool is_left) const;
  void PrintTree() const;
private:
  Node* root_;
  AvlTree(const AvlTree&) = delete; 
  AvlTree& operator=(const AvlTree&) = delete;
};

class AvlTreeUtils {
public:
  // Search Operations
  static AvlTree::Node* FindNodeByValue(AvlTree::Node* node, int value);
  static AvlTree::Node* FindSuccessor(AvlTree::Node* node);

  // Path Calculations
  static int GetPathToRootSum(AvlTree::Node* node);
};

class AvlTreeMetrics {
public:
   // Tree Size Operations
   static void UpdateSize(AvlTree::Node* node);
   static int GetSize(AvlTree::Node* node);

   // Height and Depth Operations
   static int CalculateDepth(AvlTree::Node* node);
   static void UpdateHeight(AvlTree::Node* node);
   static int GetHeight(AvlTree::Node* node);
};

class AvlTreeRotate {
public:
   // Balance Analysis
   static int CalculateBalanceFactor(AvlTree::Node* node);
   static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node);

   // Rotation Operations
   static AvlTree::Node* RightRotate(AvlTree::Node* node);
   static AvlTree::Node* LeftRotate(AvlTree::Node* node);
};

void AvlTree::PrintTree() const{
    cout << "\n=== Tree Visualization ===\n";
    if (root_ == nullptr) {
        cout << "Empty tree\n";
        return;
    }
    PrintTreeRecursive(root_, "", true);
    cout << "=======================\n";
}
void AvlTree::PrintTreeRecursive(Node* node, string prefix, bool isLeft) const{
    if (node == nullptr) return;

    cout << prefix;
    cout << (isLeft ? "--- " : "+-- ");

    // Print the value and height of the node
    cout << node->data << " (h:" << node -> height << ")" << " (s:" << node->size << ")" << " (d:" << AvlTreeMetrics::CalculateDepth(node) << ")" << "\n";

    // Create a new prefix for printing child nodes
    string newPrefix = prefix + (isLeft ? "|   " : "    ");

    // Print the left child first, then the right child
    PrintTreeRecursive(node->left, newPrefix, true);
    PrintTreeRecursive(node->right, newPrefix, false);
}

#endif

