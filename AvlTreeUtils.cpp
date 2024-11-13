#include "OSAP_002_T6_source.h"

 AvlTree::~AvlTree() {
  cout << "AvlTree 종료" << endl;
 }

AvlTree::Node* AvlTree::NodeFindByValue(Node* head, int find_data){
    if (head == nullptr || head -> data == find_data){
      return head;
    }

    if (find_data < head -> data){
      NodeFindByValue(head -> left, find_data);
    }
    if (find_data > head -> data){
      NodeFindByValue(head -> right, find_data);
    }
}

// 특정 노드의 높이를 반환하는 함수
int AvlTree::getHeight(Node* node) {
  if (!node) {
    return 0;
  }
  
  return 1 + max(getHeight(node->left), getHeight(node->right));
}

// 특정 노드의 깊이를 반환하는 함수
int AvlTree::getDepth(Node* node, int x) {
  int depth = 0;
  while (node && node->data != x) {
    depth++;
    if (x < node->data) {
      node = node->left;
    } else {
      node = node->right;
    }
  }
  return node ? depth : -1;
}

// 특정 노드의 균형인수 계
int AvlTree::CalculateBalanceFactor(Node* node){
  return (node -> left -> height) - (node -> right -> height);
}

// 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
AvlTree::Node* AvlTree::FindUnbalancedNode (Node* node){
  if (node == nullptr){  //root 노드 도달
    return nullptr;
  }
  int balance_factor = CalculateBalanceFactor(node);
  
  if (balance_factor < -1 || balance_factor > 1){
    return node;
  }

  return FindUnbalancedNode(node -> parent);
}

//불균형인 노드를 rotate 해주는 함수
AvlTree::Node* AvlTree::RightRotate(Node* y){
  Node* x = y->left;
  Node* temp = x->right;

  x->right = y;
  y->left = temp;

  y->height = max(y->left->height, y->right->height) + 1;
  x->height = max(x->left->height, x->right->height) + 1;

  return x;
}

AvlTree::Node* AvlTree::LeftRotate(Node* x){
  Node* y = x->right;
  Node* temp = y->left;

  y->left = x;
  x->right = temp;

  x->height = max(x->left->height, x->right->height) + 1;
  y->height = max(y->left->height, y->right->height) + 1;

  return y;
}

AvlTree::Node* AvlTree::RR(Node* parent){
  Node* temp = parent -> right;

  parent -> right = temp -> left;
  temp -> left = parent;
  return temp;
}
AvlTree::Node* AvlTree::LL(Node* parent){
  Node* temp = parent -> left;

  parent -> left = temp -> right;
  temp -> right = parent;
  return temp;
}
AvlTree::Node* AvlTree::LR(Node* parent){
  parent -> left = RR(parent -> left);
  return LL(parent);
    
}
AvlTree::Node* AvlTree::RL(Node* parent){
  parent -> right = LL(parent -> right);
  return RR(parent);
}

//불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
AvlTree::Node* AvlTree::AvlSet(Node* parent){
  int parent_balance_factor = CalculateBalanceFactor(parent);
  int left_child_balance_factor = CalculateBalanceFactor(parent -> left);
  int right_child_balance_factor = CalculateBalanceFactor(parent -> right);

  if (parent_balance_factor > 1 && left_child_balance_factor >= 0 ){
    return RR(parent);   //RR
  }

  if (parent_balance_factor < -1 && right_child_balance_factor <= 0){
    return LL(parent);   //LL
  }
    
  if (parent_balance_factor < -1 && right_child_balance_factor < 0){
    return LR(parent);   //LR
  }
  
  if (parent_balance_factor > 1 && left_child_balance_factor > 0) {
    return RL(parent);   //RL
  }
    
}

