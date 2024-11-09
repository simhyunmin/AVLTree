#include "OSAP_002_T6_source.h"

int RankRootRightSearch(AvlTree::Node* node, int find_value);
int RankRootLeftSearch(AvlTree::Node* node, int find_value);
int RankRootEqualSearch(AvlTree::Node* node, int find_value);


int AvlTree::RankSearch(int find_value){
  //사전에 Rank 함수 쪽에서 find_value가 잘못된 값이 들어올 경우 처리해줬음
    
  //루트 기준 find_value가 root -> data보다 작은 경우 루트의 왼쪽 서브트리 중 find_value보다 작은 노드의 개수 + 1을 반환 
  if (find_value < root -> data) {  
    return RankRootEqualSearch(root -> left) - RankRootLeftSearch(root -> left, find_value) + 1;
  }

  //루트 기준 find_value가 root -> data랑 같은 경우 루트의 왼쪽 서브트리의 총 노드 개수 반환
  if (find_value == root -> data) {
    return RankRootEqualSearch(root -> left) + 1;
  }

  //루트 기준 find_value가 root -> data보다 큰 경우 루트의 오른쪽 서브트리 중 find_value를 찾을 때까지 탐색한 총 노드 수 + 루트 왼쪽 서브트리 총 개수 + 루트 
  if (find_value > root -> data) {
    return 1 + RankRootRightSearch(root -> right, find_value) + RankRootEqualSearch(root -> left);
  } 

    
}

//루트 기준 오른쪽 서브트리 탐색
int RankRootRightSearch(AvlTree::Node* node, int find_value){
  if (node == nullptr) {
    return 0;
  }

  if (node -> data == find_value) {
      return 1;
  }

  return 1 + RankRootRightSearch(node -> left, find_value) + RankRootRightSearch(node -> right, find_value) + 1;
}
//루트 왼쪽 서브트리의 총 노드 개수 출력
int RankRootEqualSearch(AvlTree::Node* node){
  if (node == nullptr) {
    return 0;
  }

  return 1 + RankRootEqualSearch(node -> left) + RankRootEqualSearch(node -> right);
}

//루트 기준 왼쪽 서브트리 탐색
int RankRootLeftSearch(AvlTree::Node* node, int find_value){
  if (node == nullptr) {
    return 0;
  }
  if (node -> data == find_value) {
    return 1;
  }

  return 1 + RankRootLeftSearch(node -> left, find_value) + RankRootLeftSearch(node -> right, find_value);
}

