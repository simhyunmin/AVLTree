#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTreeUtils::FindSuccessor(AvlTree::Node* node) {
    if (node == nullptr) {
        return node;
    }
    AvlTree::Node* temp = node;
    while (temp && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}

AvlTree::Node* AvlTree::EraseNode(Node* node, int erase_data) {
    if (!node) {
        return nullptr;
    }
    //cout << "moving, current loc: " << node->data << endl;
    if (erase_data < node->data) { // 왼쪽 서브트리에 있을 경우
        //cout << "moving to left" << endl;
        node->left = EraseNode(node->left, erase_data);
    }
    else if (erase_data > node->data) { // 오른쪽 서브트리에 있을 경우
        //cout << "moving to right" << endl;
        node->right = EraseNode(node->right, erase_data);
    }
    else { //삭제할 노드인 경우
        //cout << "find node to erase" << node->data << endl;
        if (!node->left || !node->right) { // 자식이 하나 이하인 경우
            if (node->left && !(node->right)) {
                node->data = node->left->data;
                delete node->left;
                node->left = nullptr;
            }
            else if (!(node->left) && node->right) {
                node->data = node->right->data;
                delete node->right;
                node->right = nullptr;
            }
            else {//무자식
                if (node->parent) {
                    if (node->parent->left == node) {
                        node->parent->left = nullptr;
                    }
                    else if(node->parent->right == node){
                        node->parent->right = nullptr;
                    }
                }
                delete node;
                node = nullptr;
            }     
        }
        else { //자식이 둘인 경우
            //후임자 노드 찾기
            Node* temp = AvlTreeUtils::FindSuccessor(node->right);

            node->data = temp->data;
            EraseNode(node->right, temp->data);
        }
    }

    if (node) {
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
    }
    return node;
}

void AvlTree::Erase(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    if (node == nullptr) {
        cout << 0 << "\n";
        return;
    }
    int depth_height_sum = node->height + AvlTreeMetrics::CalculateDepth(node);
    cout << depth_height_sum << "\n";
    root = EraseNode(root, x);
}