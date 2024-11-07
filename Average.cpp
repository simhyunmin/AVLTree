#include "OSAP_002_T6_source.h"
//노드 𝑥가 루트인 부분트리에서 노드들의 key 값의 최솟값(𝑎)와 최댓값(𝑏)의 산술평균((𝑎 + 𝑏)/2)을 출력한다.
double AvlTree::Average(int x) { 
  Node* sub_tree_root = NodeFindByValue(root, x);

  Node* min_node = sub_tree_root;
  while (min_node -> left != NULL) {
    min_node = min_node -> left;
  }
  
  Node* max_node = sub_tree_root;
  while (max_node -> right != NULL) {
    max_node = max_node -> right;
  }
  
  return (min_node->data + max_node->data) / 2;
}
