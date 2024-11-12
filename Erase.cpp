#include "OSAP_002_T6_source.h"

AvlTree::Node* AvlTree::EraseNode(Node* node, int x, bool& found) {

    if (!node) { // 노드가 nullptr일 경우 종료
        return nullptr;
    }

    if (x < node->data){ // 왼쪽 서브트리에 있을 경우
        node->left = EraseNode(node->left, x, found);
    } else if(x > node->data){ // 오른쪽 서브트리에 있을 경우
        node->right = EraseNode(node->right, x, found);
    } else {
        found = true; // 노드 발견
        node_count_--;

        if(!node->left || !node->right){ // 자식이 하나 이하인 경우
            Node* temp = node->left ? node->left: node->right; // 자식 선택
            delete node;
            return temp; 
        } else { // 자식이 둘인 경우
            Node* temp = MinValueNode(node->right); // 오른쪽 서브트리의 최솟값
            node->data = temp->data; // 현재 노드 data를 최솟값으로 교체
            node->right = EraseNode(node->right, temp->data, found); // 오른쪽에서 최솟값을 삭제
        }
    }

    if (!node) { // 노드가 nullptr이면 반환
        return node;
    }

    node->height = 1 + max(node->left->height, node->right->height); // 현재 노드 높이 갱신
    int balance = CalculateBalanceFactor(node); // 현재 노드의 균형 인수 계산
    int left_child_balance = CalculateBalanceFactor(node->left); // 왼쪽 자식 노드의 균형 인수 계산
    int right_child_balance = CalculateBalanceFactor(node->right); // 오른쪽 자식 노드의 균형 인수 계산

    if (balance > 1 && left_child_balance >= 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return RightRotate(node);
    }

    if (balance < -1 && right_child_balance <= 0) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return LeftRotate(node);
    }
    
    if (balance > 1 && left_child_balance < 0) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && right_child_balance > 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    } 

    return node;
}

void AvlTree::Erase(int x){
    bool found = false;
    Node* node = NodeFindByValue(root, x);
    if (node == nullptr) {
        cout << 0 << endl;
        return;
    }
    int depth_height_sum = node -> depth + node -> height;
    cout << depth_height_sum << endl;
    root = EraseNode(node, x, found);
}
