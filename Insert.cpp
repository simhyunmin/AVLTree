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