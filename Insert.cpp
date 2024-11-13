#include "OSAP_002_T6_source.h"

// AVL 트리에 새로운 x를 삽입하고 깊이와 높이의 합을 출력
void AvlTree::Insert(int x) {

    if (!root) { // 트리가 비어있는 경우
        root = new Node(x);
        node_count_++;
        cout << getHeight(root) + getDepth(root, x) << endl; // 루트 노드의 깊이+높이 합 출력
    }

    Node* current = root;
    Node* parent = nullptr;

    // 삽입할 위치를 찾기 위한 while 루프
    while (current) {
        parent = current;
        if (x < current->data)
            current = current->left;
        else if (x > current->data)
            current = current->right;
        else
            cout << getHeight(current) + getDepth(root, x) << endl; // 이미 존재하는 경우 깊이+높이 출력
            return;
    }

    // 새로운 노드를 parent의 자식으로 연결
    current = new Node(x);
    if (x < parent->data)
        parent->left = current;
    else
        parent->right = current;

    node_count_++; // 노드 개수 증가

    // 균형을 맞추기 위한 while 루프
    while (parent) {
        int balance = CalculateBalanceFactor(parent);

        if (balance > 1 && x < parent->left->data)
            parent = RightRotate(parent);

        else if (balance < -1 && x > parent->right->data)
            parent = LeftRotate(parent);

        else if (balance > 1 && x > parent->left->data) {
            parent->left = LeftRotate(parent->left);
            parent = RightRotate(parent);
        }

        else if (balance < -1 && x < parent->right->data) {
            parent->right = RightRotate(parent->right);
            parent = LeftRotate(parent);
        }

        if (parent == root) // 루트노드까지 균형 조정이 완료되면 종료
            break;
    }

    cout << getHeight(current) + getDepth(root, x) << endl; // 삽입된 노드의 깊이+높이 합 출력
}
