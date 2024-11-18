#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::InsertNode(AvlTree::Node* node, int insert_data, int& depth_height_sum, int depth) {
    if (!node) {
        depth_height_sum = depth + 1;
        return new Node(insert_data);
    }
    if (insert_data < node->data) {
        node->left = InsertNode(node->left, insert_data, depth_height_sum, depth + 1);
        node->left->parent = node;
    }
    else if (insert_data > node->data) {
        node->right = InsertNode(node->right, insert_data, depth_height_sum, depth + 1);
        node->right->parent = node;
    }

    AvlTreeMetrics::UpdateHeight(node);
    AvlTreeMetrics::UpdateSize(node);

    int balance = AvlTreeRotate::CalculateBalanceFactor(node);
    int left_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->left); // 왼쪽 자식 노드의 균형 인수 계산
    int right_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->right); // 오른쪽 자식 노드의 균형 인수 계산

    if (balance > 1 && left_child_balance >= 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return AvlTreeRotate::RightRotate(node);
    }

    if (balance < -1 && right_child_balance <= 0) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return AvlTreeRotate::LeftRotate(node);
    }

    if (balance > 1 && left_child_balance < 0) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        AvlTreeRotate::LeftRotate(node->left);
        return AvlTreeRotate::RightRotate(node);
    }

    if (balance < -1 && right_child_balance > 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        AvlTreeRotate::RightRotate(node->right);
        return AvlTreeRotate::LeftRotate(node);
    }

    return node;
}

void AvlTree::Insert(int insert_data) {
    int depth_height_sum = 0;
    Node* cNode = AvlTreeUtils::NodeFindByValue(root, insert_data);
    if (cNode != nullptr) {
        return;
    }
    root = InsertNode(root, insert_data, depth_height_sum, -1);
    Node* fNode = AvlTreeUtils::NodeFindByValue(root, insert_data);
    cout << fNode->height + AvlTreeMetrics::CalculateDepth(fNode) << "\n";

}