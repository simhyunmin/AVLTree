#include "OSAP_002_T6_source.h"

// AVL 트리에 새로운 x를 삽입하고 깊이와 높이의 합을 출력
void AvlTree::Insert(int x) {

    if (!root) { // 트리가 비어있는 경우
        root = new Node(x);
        ++node_count_;
        cout << CalculateHeight(root) + CalculateDepth(x) << endl; // 루트 노드의 깊이+높이 합 출력
        return;
    }

    Node* current = root;
    Node* parent = nullptr;

    // 삽입할 위치를 찾기 위한 while 루프
    while (current != nullptr) {
        parent = current;
        if (x < current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    // 새로운 노드를 parent의 자식으로 연결
    current = new Node(x);
    if (x < parent->data) {
        parent->left = current;
    }
    else {
        parent->right = current;
    }
        
    node_count_++; // 노드 개수 증가

    AvlSet(parent);
    
    cout << CalculateHeight(current) + CalculateDepth(x) << endl; // 삽입된 노드의 깊이+높이 합 출력
}
