#include "OSAP_002_T6_source.h"

int AvlTreeUtils::CalculateDepth(AvlTree::Node* node) {
    int depth = 0;
    if (node == nullptr) {/////혹시 몰라서 추가
        return 0;
    }
    while (node->parent != nullptr) {
        node = node->parent;
        ++depth;
    }

    return depth;
}

AvlTree::Node* AvlTreeUtils::MinValueNode(AvlTree::Node* node) {
    //cout << "오른쪽 subtree중 가장 작은 값을 찾습니다" << endl; ////////////
    if (node == nullptr) {
        return node;
    }
    AvlTree::Node* temp = node;
    while (temp && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

AvlTree::Node* AvlTreeUtils::NodeFindByValue(AvlTree::Node* node, int find_data) {////////////while 버전
    while (node != nullptr) {
        //cout << node->data << endl;
        if (node->data == find_data) {
            return node;
        }
        else if (node->data > find_data) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return node;
}

void AvlTreeUtils::UpdateHeight(AvlTree::Node* node) {
    if (node) {
        node->height = 1 + std::max(node->left ? GetHeight(node->left) : -1, node->right ? GetHeight(node->right) : -1);
    }
    return;
}

void AvlTreeUtils::UpdateSize(AvlTree::Node* node) {
    if (node) {
        node->size = 1 + AvlTreeUtils::GetSize(node->left) + AvlTreeUtils::GetSize(node->right);
    }
}

int AvlTreeUtils::SubtreeHeight(AvlTree::Node* node) {//////////발표전에 밑이랑 합치기
    if (node == nullptr) {
        return 0;
    }
    return node->height + 1;
}

int AvlTreeUtils::GetHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int AvlTreeUtils::CalculateHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return -1;
    }

    return max(CalculateHeight(node->left) , CalculateHeight(node->right))+1;
}

int AvlTreeUtils::GetSize(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
    int key_sum = 0;

    while (node != nullptr) {
        key_sum += node->data;
        node = node->parent;
    }

    return key_sum;
}

