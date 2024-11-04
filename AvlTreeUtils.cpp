#include "OSAP_002_T6_source.h"

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

//특정 노드의 균형인수 계산
int AvlTree::CalculateBalanceFactor(Node* node){
  return GetSubTreeHeight(node -> left) - GetSubTreeHeight(node -> right);
}

//특정 노드의 높이를 구하는 함수
int AvlTree::GetSubTreeHeight(Node* node){
  if (node == nullptr){
    return -1;
  }

  return std::max(GetSubTreeHeight(node -> left), GetSubTreeHeight(node -> right)) + 1;
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
