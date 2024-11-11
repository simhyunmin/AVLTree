// #include "OSAP_002_T6_source.h"

// int GetPathToRootSum(AvlTree::Node *); // 부모 노드로 거슬러 올라가며 key값 더하는 함수


// void AvlTree::Ancestor(int x){  
//   Node *node = NodeFindByValue(root, x);
  
//   int depth = node->depth;
//   int height = node->height;
//   int parent_path_sum = GetPathToRootSum(node->parent); 

//   cout << depth + height << " " << parent_path_sum << endl;
// }

// int GetPathToRootSum(AvlTree::Node *node) {  
//   int key_sum = 0;

//   while(node != nullptr) {   
//     key_sum += node->data;
//     node = node->parent;
//   }

//   return key_sum;
// }
