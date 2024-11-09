#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::InsertNode(Node* node, int x, int& depth_height_sum, int depth) {
    
    if(!node) {
        node_count_++;
        int depth_height_sum = depth + 1;
        return new Node(x);
    }

    if(x < node->data){
        node->left = InsertNode(node->left, x, depth_height_sum, depth + 1);
    } else if (x > node->data){
        node->right = InsertNode(node->right, x, depth_height_sum, depth + 1);
    } else {
        return node;
    }

    node->height = 1 + max(node->left->height, node->right->height);
    AvlSet(node);

    return node;
}

void AvlTree::Insert(int x){
    int depth_height_sum = 0;
    root = InsertNode(root, x, depth_height_sum);
    cout << depth_height_sum << endl;
}
