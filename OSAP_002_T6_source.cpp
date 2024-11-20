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

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int num_test_cases;
  cin >> num_test_cases;
  while (num_test_cases--) {
    int num_queries;
    cin >> num_queries;
    AvlTree avl_tree;
    for (int i = 0; i < num_queries; ++i) {
      string command;
      cin >> command;

      if (command == "Empty") {
        avl_tree.Empty();
      }
      else if (command == "Size") {
        avl_tree.Size();
      }
      else if (command == "Height") {
        avl_tree.Height();
      }
      else if (command == "Insert") {
        int x;
        cin >> x;
        avl_tree.Insert(x);
      }
      else if (command == "Find") {
        int x;
        cin >> x;
        avl_tree.Find(x);
      }
      else if (command == "Ancestor") {
        int x;
        cin >> x;
        avl_tree.Ancestor(x);
      }
      else if (command == "Average") {
        int x;
        cin >> x;
        avl_tree.Average(x);
      }
      else if (command == "Rank") {
        int x;
        cin >> x;
        avl_tree.Rank(x);
      }
      else if (command == "Erase") {
        int x;
        cin >> x;
        avl_tree.Erase(x);
      }
      else if (command == "PrintTree") {
        avl_tree.PrintTree();
      }
      cin.clear();
    }
  }

  return 0;
}

// Calculates sum of node values from current node to root by following parent links
int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
  int key_sum = 0;

  while (node != nullptr) {
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}

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

// Traverses tree to find node with given value using binary search
AvlTree::Node* AvlTreeUtils::FindNodeByValue(AvlTree::Node* node, int find_data) {
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

// Print total number of nodes in tree
void AvlTree::Size() const {
  if (root_ == nullptr) {
    cout << 0 << "\n";
    return;
  }
  cout << root_->size << "\n";
}

// Post-order traversal to delete all nodes in the tree
void AvlTree::Clear(AvlTree::Node* node) {
  if (node != nullptr) {
    Clear(node->left);
    Clear(node->right);
    delete node;
  }
}

// Returns balance factor (left height - right height) of node
int AvlTreeRotate::CalculateBalanceFactor(AvlTree::Node* node) {
  if (node == nullptr) {
    return 0;
  }
  
  int left_height = (node->left) ? node->left->height : -1;
  int right_height = (node->right) ? node->right->height : -1;
  return left_height - right_height;
}

// Finds ancestor node that violates AVL balance property
AvlTree::Node* AvlTreeRotate::FindUnbalancedNode(AvlTree::Node* node) {
  if (node == nullptr) {
    return nullptr;
  }
  int balance_factor = CalculateBalanceFactor(node);

  if (balance_factor < -1 || balance_factor > 1) {
    return node;
  }

  return FindUnbalancedNode(node->parent);
}

// Performs right rotation around parent_node and updates height/size of affected nodes
AvlTree::Node* AvlTreeRotate::RightRotate(AvlTree::Node* parent_node) {
  AvlTree::Node* child = parent_node->left;
  AvlTree::Node* child_right = child->right;

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
  parent_node->height = max(
    AvlTreeMetrics::GetHeight(parent_node->left),
    AvlTreeMetrics::GetHeight(parent_node->right)
  ) + 1;

  child->height = max(
    AvlTreeMetrics::GetHeight(child->left),
    AvlTreeMetrics::GetHeight(child->right)
  ) + 1;

  AvlTreeMetrics::UpdateSize(parent_node);
  AvlTreeMetrics::UpdateSize(child);

  return child;
}

// Performs left rotation around parent_node and updates height/size of affected nodes
AvlTree::Node* AvlTreeRotate::LeftRotate(AvlTree::Node* parent_node) {
  AvlTree::Node* child = parent_node->right;
  AvlTree::Node* child_left = child->left;

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
  parent_node->height = max(
    AvlTreeMetrics::GetHeight(parent_node->left),
    AvlTreeMetrics::GetHeight(parent_node->right)
  ) + 1;

  child->height = max(
    AvlTreeMetrics::GetHeight(child->left),
    AvlTreeMetrics::GetHeight(child->right)
  ) + 1;

  AvlTreeMetrics::UpdateSize(parent_node);
  AvlTreeMetrics::UpdateSize(child);

  return child;
}

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

// Prints height+depth sum and path sum to root from parent
void AvlTree::Ancestor(int target_value) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int depth = AvlTreeMetrics::CalculateDepth(target_node);
  int height = target_node->height;
  int parent_path_sum = AvlTreeUtils::GetPathToRootSum(target_node->parent);
  
  cout << depth + height << " " << parent_path_sum << "\n";
}

// Prints average of min and max values in subtree rooted at target value
void AvlTree::Average(int target_value) {
  Node* sub_tree_root = AvlTreeUtils::FindNodeByValue(root_, target_value);
  
  Node* min_node = sub_tree_root;
  while (min_node->left != nullptr) {
    min_node = min_node->left;
  }

  Node* max_node = sub_tree_root;
  while (max_node->right != nullptr) {
    max_node = max_node->right;
  }
  
  int average = (min_node->data + max_node->data) / 2;
  cout << average << "\n";
}

// Prints tree height, -1 if empty
void AvlTree::Height() const {
  if (root_ == nullptr) {
    cout << -1 << "\n";
    return;
  }

  cout << root_->height << "\n";
}

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

void AvlTree::PrintTree() const {
  cout << "\n=== Tree Visualization ===\n";
  if (root_ == nullptr) {
    cout << "Empty tree\n";
    return;
  }
  PrintTreeRecursive(root_, "", true);
  cout << "=======================\n";
}

void AvlTree::PrintTreeRecursive(Node* node, string prefix, bool is_left) const {
  if (node == nullptr) return;

  cout << prefix;
  cout << (is_left ? "--- " : "+-- ");

  cout << node->data << " (h:" << node->height << ")" << " (s:" << node->size << ")" << " (d:" << AvlTreeMetrics::CalculateDepth(node) << ")" << "\n";

  string new_prefix = prefix + (is_left ? "|   " : "    ");

  PrintTreeRecursive(node->left, new_prefix, true);
  PrintTreeRecursive(node->right, new_prefix, false);
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