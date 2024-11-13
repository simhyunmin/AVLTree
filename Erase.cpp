#include "OSAP_002_T6_source.h"

void AvlTree::Erase(int x) {
    Node* current = root;
    Node* parent = nullptr;

    // 삭제할 노드를 찾기 위한 while 루프
    while (current && current->data != x) {
        parent = current;
        if (x < current->data)
            current = current->left;
        else
            current = current->right;
    }

    if (!current) { // 노드가 존재하지 않으면 0을 출력하고 종료
        cout << 0 << endl;
        return;
    }

    int depthHeightSum = getHeight(current) + getDepth(root, x); // 깊이와 높이의 합 계산

    Node* alternative;
    if (!current->left || !current->right) { // 자식이 하나 이하인 경우
        alternative = current->left ? current->left : current->right;

        if (!parent)  // 삭제할 노드가 루트일 경우
            root = alternative;
        else if (parent->left == current)
            parent->left = alternative;
        else
            parent->right = alternative;
    } else {  // 자식이 둘인 경우
        Node* temp = current->right;
        Node* tempParent = current;

        while (temp->left) {  // 오른쪽 서브트리의 가장 왼쪽 노드를 찾음
            tempParent = temp;
            temp = temp->left;
        }

        current->data = temp->data; // 삭제할 노드의 키를 대체
        if (tempParent->left == temp)
            tempParent->left = temp->right;
        else
            tempParent->right = temp->right;

        delete temp;
        cout << depthHeightSum << endl; // 깊이와 높이의 합 출력
        return;
    }

    delete current;  // 노드 삭제
    node_count_--;

    cout << depthHeightSum << endl; // 깊이와 높이의 합 출력
}
