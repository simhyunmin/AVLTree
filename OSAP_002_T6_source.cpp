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

  void Clear(Node* node);

  // features
  void Find(int x)const;
  void Empty() {cout << ((root_ == nullptr) ? 1 : 0) << "\n";}
  void Size() const;
  void Height() const;
  void Ancestor(int x);
  void Average(int x);
  Node* InsertNode(Node* node, int x, int& depth_height_sum, int depth);
  void Insert(int x);
  Node* EraseNode(Node* node, int x);
  void Erase(int x);
  void Rank(int x);
  int CalculateRank(Node* node, int x);

  // 트리 확인 함수
  void PrintTreeRecursive(Node* node, string prefix, bool isLeft) const;
  void PrintTree() const;
private:
  Node* root_;
};

class AvlTreeUtils {
public:
  static AvlTree::Node* FindNodeByValue(AvlTree::Node* node, int value);
  static int GetPathToRootSum(AvlTree::Node*);
  static AvlTree::Node* FindSuccessor(AvlTree::Node* node);
};

class AvlTreeMetrics {
public:
  static int CalculateDepth(AvlTree::Node* node);
  static void UpdateSize(AvlTree::Node* node);
  static int GetSize(AvlTree::Node* node);
  static void UpdateHeight(AvlTree::Node* node);
  static int GetHeight(AvlTree::Node* node);
};

class AvlTreeRotate {
public:
  static int CalculateBalanceFactor(AvlTree::Node* node);
  static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node);
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

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
  int key_sum = 0;

  while (node != nullptr) {
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}

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

void AvlTreeMetrics::UpdateHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->height = 1 + std::max(
    node->left ? GetHeight(node->left) : -1,
    node->right ? GetHeight(node->right) : -1
  );
}

void AvlTreeMetrics::UpdateSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return;
  }
  node->size = 1 + GetSize(node->left) + GetSize(node->right);
}

int AvlTreeMetrics::GetHeight(AvlTree::Node* node) {
  if (node == nullptr) {
    return -1;
  }
  return node->height;
}

int AvlTreeMetrics::GetSize(AvlTree::Node* node) {
  if (node == nullptr) {
    return 0;
  }
  return node->size;
}

void AvlTree::Size() const {
  if (root_ == nullptr) {
    cout << 0 << "\n";
    return;
  }
  cout << root_->size << "\n";
}

void AvlTree::Clear(AvlTree::Node* node) {
  if (node != nullptr) {
    Clear(node->left);
    Clear(node->right);
    delete node;
  }
}

int AvlTreeRotate::CalculateBalanceFactor(AvlTree::Node* node) {
  if (node == nullptr) {
    return 0;
  }
  
  int left_height = (node->left) ? node->left->height : -1;
  int right_height = (node->right) ? node->right->height : -1;
  return left_height - right_height;
}

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

AvlTree::Node* AvlTreeRotate::RightRotate(AvlTree::Node* parent_node) {
  AvlTree::Node* child = parent_node->left;
  AvlTree::Node* child_right = child->right;

  child->right = parent_node;
  parent_node->left = child_right;

  if (child_right) {
    child_right->parent = parent_node;
  }

  child->parent = parent_node->parent;
  parent_node->parent = child;

  if (child->parent) {
    if (child->parent->left == parent_node) {
      child->parent->left = child;
    } else {
      child->parent->right = child;
    }
  }
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

AvlTree::Node* AvlTreeRotate::LeftRotate(AvlTree::Node* parent_node) {
  AvlTree::Node* child = parent_node->right;
  AvlTree::Node* child_left = child->left;

  child->left = parent_node;
  parent_node->right = child_left;

  if (child_left) {
    child_left->parent = parent_node;
  }

  child->parent = parent_node->parent;
  parent_node->parent = child;

  if (child->parent) {
    if (child->parent->left == parent_node) {
      child->parent->left = child;
    } else {
      child->parent->right = child;
    }
  }
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

AvlTree::Node* AvlTree::InsertNode(AvlTree::Node* node, int insert_data,
                                int& depth_height_sum, int depth) {
  if (!node) {
    depth_height_sum = depth + 1;
    return new Node(insert_data);
  }
  if (insert_data < node->data) {
    node->left = InsertNode(node->left, insert_data,
                         depth_height_sum, depth + 1);
    node->left->parent = node;
  } else if (insert_data > node->data) {
    node->right = InsertNode(node->right, insert_data,
                          depth_height_sum, depth + 1);
    node->right->parent = node;
  }

  AvlTreeMetrics::UpdateHeight(node);
  AvlTreeMetrics::UpdateSize(node);

  int balance = AvlTreeRotate::CalculateBalanceFactor(node);

  int left_child_balance =
    AvlTreeRotate::CalculateBalanceFactor(node->left);
  int right_child_balance =
    AvlTreeRotate::CalculateBalanceFactor(node->right);

  if (balance > 1 && left_child_balance >= 0) {
    return AvlTreeRotate::RightRotate(node);
  }

  if (balance < -1 && right_child_balance <= 0) {
    return AvlTreeRotate::LeftRotate(node);
  }

  if (balance > 1 && left_child_balance < 0) {
    AvlTreeRotate::LeftRotate(node->left);
    return AvlTreeRotate::RightRotate(node);
  }

  if (balance < -1 && right_child_balance > 0) {
    AvlTreeRotate::RightRotate(node->right);
    return AvlTreeRotate::LeftRotate(node);
  }

  return node;
}

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

AvlTree::Node* AvlTree::EraseNode(Node* node, int erase_data) {
  if (!node) {
    return nullptr;
  }
  if (erase_data < node->data) {
    node->left = EraseNode(node->left, erase_data);
  }
  else if (erase_data > node->data) {
    node->right = EraseNode(node->right, erase_data);
  }
  else {
    if (!node->left || !node->right) {
      if (node->left && !(node->right)) {
        node->data = node->left->data;
        delete node->left;
        node->left = nullptr;
      }
      else if (!(node->left) && node->right) {
        node->data = node->right->data;
        delete node->right;
        node->right = nullptr;
      }
      else {
        if (node->parent) {
          if (node->parent->left == node) {
            node->parent->left = nullptr;
          }
          else if (node->parent->right == node) {
            node->parent->right = nullptr;
          }
        }
        delete node;
        node = nullptr;
      }
    }
    else {
      Node* temp = AvlTreeUtils::FindSuccessor(node->right);
      node->data = temp->data;
      EraseNode(node->right, temp->data);
    }
  }

  if (node) {
    AvlTreeMetrics::UpdateHeight(node);
    AvlTreeMetrics::UpdateSize(node);
    int balance = AvlTreeRotate::CalculateBalanceFactor(node);
    int left_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->left);
    int right_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->right);

    if (balance > 1 && left_child_balance >= 0) {
      return AvlTreeRotate::RightRotate(node);
    }
    if (balance < -1 && right_child_balance <= 0) {
      return AvlTreeRotate::LeftRotate(node);
    }
if (balance > 1 && left_child_balance < 0) {
  AvlTreeRotate::LeftRotate(node->left);
  return AvlTreeRotate::RightRotate(node);
}
if (balance < -1 && right_child_balance > 0) {
  AvlTreeRotate::RightRotate(node->right);
  return AvlTreeRotate::LeftRotate(node);
}
}
return node;
}

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

void AvlTree::Find(int target_value) const {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int result = 0;
  
  if (target_node != nullptr) {
    result = AvlTreeMetrics::CalculateDepth(target_node) + 
             target_node->height;
  }
  
  cout << result << "\n";
}

void AvlTree::Ancestor(int target_value) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  int depth = AvlTreeMetrics::CalculateDepth(target_node);
  int height = target_node->height;
  int parent_path_sum = AvlTreeUtils::GetPathToRootSum(target_node->parent);
  
  cout << depth + height << " " << parent_path_sum << "\n";
}

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

void AvlTree::Height() const {
  if (root_ == nullptr) {
    cout << -1 << "\n";
    return;
  }

  cout << root_->height << "\n";
}

void AvlTree::Rank(int target_value) {
  Node* target_node = AvlTreeUtils::FindNodeByValue(root_, target_value);
  if (target_node == nullptr) {
    cout << 0 << "\n";
    return;
  }

  int depth_plus_height = AvlTreeMetrics::CalculateDepth(target_node) + 
                         target_node->height;
  int rank_value = CalculateRank(root_, target_value);
  
  std::cout << depth_plus_height << " " << rank_value << "\n";
}

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

void AvlTree::PrintTreeRecursive(Node* node, string prefix, bool isLeft) const {
  if (node == nullptr) return;

  cout << prefix;
  cout << (isLeft ? "--- " : "+-- ");

  cout << node->data << " (h:" << node->height << ")" << " (s:" << node->size << ")" << " (d:" << AvlTreeMetrics::CalculateDepth(node) << ")" << "\n";

  string newPrefix = prefix + (isLeft ? "|   " : "    ");

  PrintTreeRecursive(node->left, newPrefix, true);
  PrintTreeRecursive(node->right, newPrefix, false);
}