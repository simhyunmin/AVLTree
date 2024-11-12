#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::InsertNode(Node* node, int x, int& depth_height_sum, int depth) {

    if (!node) { // 노드가 nullptr일 경우
        node_count_++;
        int depth_height_sum = depth + 1;
        return new Node(x);
    }

    if (x < node->data){ // 삽입할 x가 현재 노드 data보다 작으면 왼쪽 서브트리에 삽입
        node->left = InsertNode(node->left, x, depth_height_sum, depth + 1);
    } else if (x > node->data){ // 삽입할 x가 현재 노드 data보다 크면 오른쪽 서브트리에 삽입
        node->right = InsertNode(node->right, x, depth_height_sum, depth + 1);
    } else { // 이미 존재하는 data면 삽입하지 않음
        return node;
    }

    node->height = 1 + max(node->left->height, node->right->height); // 현재 노드 높이 갱신
    int balance = CalculateBalanceFactor(node); // 현재 노드의 균형 인수 계산

    if (balance > 1 && x < node->left->data) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return RightRotate(node);
    }

    if (balance < -1 && x > node->right->data) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return LeftRotate(node);
    }
    
    if (balance > 1 && x > node->left->data) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance <-1 && x < node->right->data) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

void AvlTree::Insert(int x){ // 노드 x를 삽입하고 나서 깊이와 높이의 합을 출력
    int depth_height_sum = 0;
    root = InsertNode(root, x, depth_height_sum);
    cout << depth_height_sum << endl;
}
