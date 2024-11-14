#include "OSAP_002_T6_source.h"

// AVL 트리에 새로운 x를 삽입하고 깊이와 높이의 합을 출력
void AvlTree::Insert(int insert_data){
  //빈 트리일 경우 루트 노드에 삽입
  Node* newNode = new Node(insert_data);
  if(root == nullptr) {
    root = newNode;
    cout << 0 << "\n";
    return;
  }

  Node* current_node = root;
  Node* current_parent = nullptr;

  //삽입 위치 찾기
  while (current_node != nullptr) {
    current_parent = current_node;
    if (insert_data < current_node -> data) {
      current_node = current_node -> left;
    } else {
      current_node = current_node -> right;
    }
  }

  //부모 노드 기준으로 왼쪽, 오른쪽 자식 설정
  if (insert_data < current_parent -> data) {
    current_parent -> left = newNode;
  } else {
    current_parent -> right = newNode;
  }

  newNode -> parent = current_parent;

  //삽입된 위치를 기준으로 불균형인 노드를 찾고 rotate 해주기
  AvlRotateUtils::AvlSet(newNode);
  cout << AvlTreeUtils::CalculateHeight(newNode) + AvlTreeUtils::CalculateDepth(newNode) << "\n";
  
}
