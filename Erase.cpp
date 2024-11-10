#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::EraseNode(Node* node, int x) {

    if(x < node->data){
        node->left = EraseNode(node->left, x);
    } else if(x > node->data){
        node->right = EraseNode(node->right, x);
    } else {
        node_count_--;

        if(!node->left || !node->right){
            Node* temp = node->left ? node->left: node->right;
            delete node;
            return temp;
        } else {
            Node* temp = minValueNode(node->right);
            node->data = temp->data;
            node->right = EraseNode(node->right, temp->data);
        }
    }

    if(!node){
        return node;
    }

    node->height = 1 + max(node->left->height, node->right->height);
    AvlSet(node);

    return node;
}

void AvlTree::Erase(int x){
    Node* node = NodeFindByValue(root, x);
    if (node == nullptr) {
        cout << 0 << endl;
        return;
    }
    int depth_height_sum = node -> depth + node -> height;
    cout << depth_height_sum << endl;
    EraseNode(node, x);
}
