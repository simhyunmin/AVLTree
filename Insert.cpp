#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::InsertNode(Node* node, int x) {
    int height = node->height;
    int depth = node->depth;
    
    if(!node) {
        node_count_++;
        int depth_height_sum = depth + 1;
        return new Node(x);
    }

    if(x < node->data){
        node->left = InsertNode(node->left, x);
        depth++;
    } else if (x > node->data){
        node->right = InsertNode(node->right, x);
        depth++;
    } else {
        return node;
    }

    node->height = 1 + max(node->left->height, node->right->height);
    AvlSet(node);

    return node;
}

void AvlTree::Insert(int x){
    int depth_height_sum = 0;
    root = InsertNode(root, x);
    cout << depth_height_sum << endl;
}
