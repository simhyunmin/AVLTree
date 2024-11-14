#include "OSAP_002_T6_source.h"

void AvlTree::Erase(int x) {
    Node *del_node = NodeFindByValue(root, x);
    if (del_node == NULL) { // 노드가 존재하지 않으면 0을 출력하고 종료
        cout << 0 << endl;
        return;
    }
    Node *par_node = del_node->parent; // 삭제할 노드의 부모 노드
    Node *child_node = nullptr;  // 후계자 노드
    int depthHeightSum = getHeight(del_node) + getDepth(root, x); // 깊이와 높이의 합 계산



    if (del_node->left == NULL && del_node->right == NULL) {  // 삭제할 노드의 자식이 하나 인 경우
        child_node = NULL;
    }
    else if (del_node->left == NULL && del_node->right != NULL) {
        child_node = del_node->right;
    }
    else if (del_node->left != NULL && del_node->right == NULL) {
        child_node = del_node->left;
    }
    else { // 삭제할 노드의 자식이 두 개 있을 경우
        child_node = del_node->right;
        while (child_node->left != NULL) { 
            child_node = child_node->left;
        }
        del_node->data = child_node->data;
        del_node = child_node;
        par_node = del_node->parent;
        child_node = del_node->right;
    }
    

    if (par_node == NULL) { // 삭제 할 노드가 루트인 경우
        root = child_node;
        if (child_node != NULL) {
            root->parent = NULL;
        }
    }
    else if (del_node == par_node->left) {
        par_node->left = child_node;
        if (child_node != NULL) {
            child_node->parent = par_node;
        }
    }
    else {
        par_node->right = child_node;
        if (child_node != NULL) {
            child_node->parent = par_node;
        }
    }
    delete del_node;
    node_count_--;

    cout << depthHeightSum << endl; // 깊이와 높이의 합 출력

    // 삭제 후 균형 복구를 위해 루트까지 거슬러 올라가며 rebalancing 수행
    while (par_node != NULL) {
        par_node = AvlSet(par_node);

        if (par_node->parent == NULL) {
            root = par_node;
            break;
        }

        par_node = par_node->parent;
    }
}
