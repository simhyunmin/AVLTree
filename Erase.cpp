#include "OSAP_002_T6_source.h"

void AvlTree::Erase(int x){
  Node* del_node = AvlTreeUtils::NodeFindByValue(root, x);
  Node* del_parent_node = del_node -> parent;

  if (del_node == nullptr) {
    cout << 0 << "\n";
    return;
  }
  node_count_--;
  cout << AvlTreeUtils::CalculateHeight(del_node) + AvlTreeUtils::CalculateDepth(del_node) << "\n";
  
  //자식이 존재하지 않는 경우
  if (!(del_node -> left && del_node -> right)) {
    delete del_node;
    del_node = nullptr;
  }
  
  //오른쪽 자식만 존재하는 경우
  else if (del_node -> left == nullptr && del_node -> right != nullptr) {
    Node* temp = del_node -> right;
    temp -> parent = del_node -> parent;
    delete del_node;
    del_node = temp;
  }
  
  //왼쪽 자식만 존재하는 경우
  else if (del_node -> right == nullptr && del_node -> left != nullptr) {
    Node* temp = del_node -> left;
    temp -> parent = del_node -> parent;
    delete del_node;
    del_node = temp;
  }
  
  //둘 다 존재하는 경우
  else {
    Node* temp = del_node -> right;
    
    //후임자 찾기
    while(temp -> left != nullptr) {
      temp = temp -> left;
    }
    
    //찾은 후임자 저장
    Node* successor_node = temp;
    
    //원래 후임자 위치는 삭제
    delete temp;
    temp = nullptr;
  
    successor_node -> parent = del_node -> parent;
    delete del_node;
    
    //후임자를 del_node 위치로 대체한다.
    del_node = successor_node;
  }
  
  //자식이 모두 존재하지 않는 경우 del_node는 대체되지 않고 삭제되기에
  if(del_node == nullptr) {
    AvlRotateUtils::AvlSet(del_parent_node);
  } 
  //그 외에 경우 del_node부터 부모 노드를 거슬러 올라가면서 불균형인 노드 찾고 rotate
  else {
    AvlRotateUtils::AvlSet(del_node);
  }
}
