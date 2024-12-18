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
 * @brief Print total number of nodes in tree
 */
void AvlTree::Size() const {
  if (root_ == nullptr) {
    cout << 0 << "\n";
    return;
  }
  cout << root_->size << "\n";
}

/**
 * @brief Delete all nodes in tree using post-order traversal
 * @param node Starting node for deletion
 */
void AvlTree::Clear(AvlTree::Node *node) {
  if (node != nullptr) {
    Clear(node->left);
    Clear(node->right);
    delete node;
  }
}

/**
 * @brief Insert new node while maintaining AVL balance
 * @param node Current node in recursion
 * @param insert_data Value to insert
 * @param depth_height_sum Running sum of depth and height
 * @param depth Current depth in tree
 * @return New root after insertion
 */
AvlTree::Node *AvlTree::InsertNode(AvlTree::Node *node, int insert_data,
                                   int &depth_height_sum, int depth) {
  if (!node) {
    depth_height_sum = depth + 1;
    Node *newNode = new Node(insert_data);
    AvlTreeMetrics::UpdateHeight(newNode);
    AvlTreeMetrics::UpdateSize(newNode);
    return newNode;
  }

  // Find insertion position using binary search
  if (insert_data < node->data) {
    node->left =
        InsertNode(node->left, insert_data, depth_height_sum, depth + 1);
    node->left->parent = node;
  } else if (insert_data > node->data) {
    node->right =
        InsertNode(node->right, insert_data, depth_height_sum, depth + 1);
    node->right->parent = node;
  }

  // Update node properties
  AvlTreeMetrics::UpdateHeight(node);
  AvlTreeMetrics::UpdateSize(node);

  // Check balance factors
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

  return node;
}

/**
 * @brief interface for inserting value into tree
 * @param insert_data Value to insert
 */
void AvlTree::Insert(int insert_data) {
  int depth_height_sum = 0;

  Node *current_node = AvlTreeUtils::FindNodeByValue(root_, insert_data);
  if (current_node != nullptr) {
    return;
  }
  root_ = InsertNode(root_, insert_data, depth_height_sum, -1);
  Node *found_node = AvlTreeUtils::FindNodeByValue(root_, insert_data);
  cout << found_node->height + AvlTreeMetrics::CalculateDepth(found_node)
       << "\n";
}

/**
 * @brief Delete node while maintaining AVL balance
 * @param node Current node in recursion
 * @param erase_data Value to delete
 * @return New root after deletion and rebalancing
 */
AvlTree::Node *AvlTree::EraseNode(Node *node, int erase_data) {
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
      Node *temp = AvlTreeUtils::FindSuccessor(node->right);
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
  }
  return node;
}

/**
 * @brief interface for deleting value from tree
 * @param value_to_erase Value to delete
 */
void AvlTree::Erase(int value_to_erase) {
  Node *target_node = AvlTreeUtils::FindNodeByValue(root_, value_to_erase);
  if (target_node == nullptr) {
    cout << 0 << "\n";
    return;
  }

  int depth_height_sum =
      target_node->height + AvlTreeMetrics::CalculateDepth(target_node);
  cout << depth_height_sum << "\n";
  root_ = EraseNode(root_, value_to_erase);
}

/**
 * @brief Search for value and print height + depth sum
 * @param target_value Value to find
 */
void AvlTree::Find(int target_value) const {
  Node *target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int result = 0;

  if (target_node != nullptr) {
    result = AvlTreeMetrics::CalculateDepth(target_node) + target_node->height;
  }

  cout << result << "\n";
}

/**
 * @brief Calculate and print parent path statistics
 * @param target_value Value of target node
 */
void AvlTree::Ancestor(int target_value) {
  Node *target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int depth = AvlTreeMetrics::CalculateDepth(target_node);
  int height = target_node->height;
  int parent_path_sum = AvlTreeUtils::GetPathToRootSum(target_node->parent);

  cout << depth + height << " " << parent_path_sum << "\n";
}

/**
 * @brief Print average of min and max values in subtree
 * @param target_value Root value of target subtree
 */
void AvlTree::Average(
    int target_value) {  // Get average of mininum and maximum of the tree
  Node *sub_tree_root =
      AvlTreeUtils::FindNodeByValue(root_, target_value);  // find targe

  Node *min_node = sub_tree_root;
  while (min_node->left != nullptr) {  // find minimun
    min_node = min_node->left;
  }

  Node *max_node = sub_tree_root;
  while (max_node->right != nullptr) {  // find maximum
    max_node = max_node->right;
  }

  int average = (min_node->data + max_node->data) / 2;  // Calculate average
  cout << average << "\n";
}

/**
 * @brief Print tree height
 */
void AvlTree::Height() const {
  if (root_ == nullptr) {
    cout << -1 << "\n";
    return;
  }

  cout << root_->height << "\n";
}

/**
 * @brief Print node statistics and rank
 * @param target_value Value to find rank for
 */
void AvlTree::Rank(int target_value) {
  Node *target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  if (target_node == nullptr) {  // When target_value not exist
    cout << 0 << "\n";
    return;
  }

  int depth_plus_height =
      AvlTreeMetrics::CalculateDepth(target_node) +  // Calculate depth + height
      target_node->height;
  int rank_value = CalculateRank(root_, target_value);  // Calculate Rank

  cout << depth_plus_height << " " << rank_value << "\n";
}

/**
 * @brief Calculate rank of value in tree
 * @param current_node Current node in recursion
 * @param target_value Value to find rank for
 * @return Calculated rank value
 */
int AvlTree::CalculateRank(Node *current_node, int target_value) {
  if (current_node == nullptr) {  // base case: assume size of nullptr for make
                                  // rank of minimum value of 1
    return 0;
  }

  if (target_value <
      current_node->data) {  // move till find the smaller one than target value
    return CalculateRank(current_node->left, target_value);
  } else if (target_value >
             current_node->data) {  // add the size of subtree that data is low
                                    // for target value
    return AvlTreeMetrics::GetSize(current_node->left) + 1 +
           CalculateRank(current_node->right, target_value);
  } else {
    return AvlTreeMetrics::GetSize(current_node->left) +
           1;  // add the size of subtree of left
  }
}

/**
 * @brief Print tree visualization
 */
void AvlTree::PrintTree() const {
  cout << "\n=== Tree Visualization ===\n";
  if (root_ == nullptr) {
    cout << "Empty tree\n";
    return;
  }
  PrintTreeRecursive(root_, "", true);
  cout << "=======================\n";
}

/**
 * @brief Print tree structure recursively with formatting
 * @param node Current node to print
 * @param prefix String prefix for visual indentation
 * @param is_left Whether current node is a left child
 */
void AvlTree::PrintTreeRecursive(Node *node, string prefix,
                                 bool is_left) const {
  if (node == nullptr) return;

  cout << prefix;
  cout << (is_left ? "--- " : "+-- ");

  cout << node->data << " (h:" << node->height << ")"
       << " (s:" << node->size << ")"
       << " (d:" << AvlTreeMetrics::CalculateDepth(node) << ")"
       << "\n";

  string new_prefix = prefix + (is_left ? "|   " : "    ");

  PrintTreeRecursive(node->left, new_prefix, true);
  PrintTreeRecursive(node->right, new_prefix, false);
}