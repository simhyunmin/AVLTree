// #include "OSAP_002_T6_source.h"

// int AvlTree::InorderTraversalByValue(Node* node, int find_value){
//     if (node == nullptr) {
//         return;
//     }

//     InorderTraversalByValue(node -> left, find_value);
//     node_rank_count_++;
//     if (node -> data == find_value) {
//         return node_rank_count_;
//     }
//     InorderTraversalByValue(node -> right, find_value);
// }