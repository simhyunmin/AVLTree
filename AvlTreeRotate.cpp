#include "OSAP_002_T6_source.h"

//특정 노드의 균형인수 계산
int AvlTreeRotate::CalculateBalanceFactor(AvlTree::Node* node) {
    if (node == nullptr) { return 0; }
    int left_size = (node -> left) ? node -> left -> height : -1;
    int right_size = (node -> right) ? node -> right -> height : -1;
    return left_size - right_size;
}

AvlTree::Node* AvlTreeRotate::FindUnbalancedNode(AvlTree::Node* node) {
    if (node == nullptr) {  //불균형인 노드가 없는 경우
        return nullptr;
    }
    int balance_factor = CalculateBalanceFactor(node);

    if (balance_factor < -1 || balance_factor > 1) {
        return node;
    }

    return FindUnbalancedNode(node->parent);
}

//불균형인 노드를 rotate 해주는 함수
AvlTree::Node* AvlTreeRotate::RightRotate(AvlTree::Node* parent_node) {
    AvlTree::Node* ch = parent_node->left;
    AvlTree::Node* ch_right = ch->right;

    ch->right = parent_node;
    parent_node->left = ch_right;

    if (ch_right) { ch_right->parent = parent_node; }
    ch->parent = parent_node->parent;
    parent_node->parent = ch;

    if (ch->parent) {
        if (ch->parent->left == parent_node) {
            ch->parent->left = ch;
        }
        else {
            ch->parent->right = ch;
        }
    }
    parent_node->height = max(AvlTreeMetrics::GetHeight(parent_node->left), AvlTreeMetrics::GetHeight(parent_node->right)) + 1;
    ch->height = max(AvlTreeMetrics::GetHeight(ch->left), AvlTreeMetrics::GetHeight(ch->right)) + 1;

    AvlTreeMetrics::UpdateSize(parent_node);
    AvlTreeMetrics::UpdateSize(ch);
    return ch;
}
AvlTree::Node* AvlTreeRotate::LeftRotate(AvlTree::Node* parent_node) {
    AvlTree::Node* ch = parent_node->right;
    AvlTree::Node* ch_left = ch->left;
    //부모 노드의 오른쪽 자식의 왼쪽 자식을 부모 노드로 설정
    //원래 부모 노드의 오른쪽 자식의 왼쪽 자식을 원래 부모 노드의 오른쪽 자식으로 설정
    ch->left = parent_node;
    parent_node->right = ch_left;

    if (ch_left) { ch_left->parent = parent_node; }
    //각 위치가 바뀐 노드에 대해서 부모 노드 업데이트
    ch->parent = parent_node->parent;
    parent_node->parent = ch;


    if (ch->parent) {
        if (ch->parent->left == parent_node) {
            ch->parent->left = ch;
        }
        else {
            ch->parent->right = ch;
        }
    }
    parent_node->height = max(AvlTreeMetrics::GetHeight(parent_node->left), AvlTreeMetrics::GetHeight(parent_node->right)) + 1;
    ch->height = max(AvlTreeMetrics::GetHeight(ch->left), AvlTreeMetrics::GetHeight(ch->right)) + 1;

    AvlTreeMetrics::UpdateSize(parent_node);
    AvlTreeMetrics::UpdateSize(ch);
    return ch;
}

/*
MIT License

Copyright (c) 2024 Your Name

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/