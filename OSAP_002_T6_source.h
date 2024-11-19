#ifndef OSAP_002_T6_SOURCE_H
#define OSAP_002_T6_SOURCE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class AvlTree {
public:
    AvlTree() : root(nullptr) {};
    ~AvlTree() { Clear(root); };

    struct Node {
        int data;
        int height;
        int size;
        Node* left;
        Node* right;
        Node* parent;

        Node(int data_) : data(data_), height(0), size(1), left(nullptr), right(nullptr), parent(nullptr) {}
    };

    void Clear(Node* node); //모든 노드를 삭제해주는 함수 (소멸자 부분에서 호출)


    //features
    void Find(int x);
    void Empty() {cout << ((root == nullptr) ? 1 : 0) << "\n";}
    void Size() const;
    void Height() const;
    void Ancestor(int x);
    void Average(int x);
    Node* InsertNode(Node* node, int x, int& depth_height_sum, int depth);
    void Insert(int x);
    Node* EraseNode(Node* node, int x);
    void Erase(int x);
    void Rank(int x);
    int CalculateRank(Node* node, int x);

    //트리 확인 함수
    void PrintTreeRecursive(Node* node, string prefix, bool isLeft) const;
    void PrintTree() const;
private:
    Node* root;  //루트 노드를 가리키는 포인터
};

class AvlTreeUtils {
public:
    static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value); //특정 노드를 값에 의해 찾고 반환해주는 함수
    static int GetPathToRootSum(AvlTree::Node*); //부모 노드로 거슬러 올라가며 key값 더하는 함수 (Ancestor에서 쓰임)
    static AvlTree::Node* FindSuccessor(AvlTree::Node* node); //후임자 찾는 함수 (Erase에서 쓰임)
};

class AvlTreeMetrics {
public:
    static int CalculateDepth(AvlTree::Node* node); //Depth 계산 함수
    static void UpdateSize(AvlTree::Node* node); //노드의 멤버 변수인 size 업데이트 함수
    static int GetSize(AvlTree::Node* node); //노드의 size 반환
    static void UpdateHeight(AvlTree::Node* node); //노드의 멤버 변수인 height 업데이트
    static int GetHeight(AvlTree::Node* node); //노드의 height 반환
};

class AvlTreeRotate {
public:
    static int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
    static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
    static AvlTree::Node* RightRotate(AvlTree::Node* node); //불균형인 노드를 right rotate 해주는 함수
    static AvlTree::Node* LeftRotate(AvlTree::Node* node); //불균형인 노드를 left rotate 해주는 함수
};

void AvlTree::PrintTree() const{
    cout << "\n=== Tree Visualization ===\n";
    if (root == nullptr) {
        cout << "Empty tree\n";
        return;
    }
    PrintTreeRecursive(root, "", true);
    cout << "=======================\n";
}
void AvlTree::PrintTreeRecursive(Node* node, string prefix, bool isLeft) const{
    if (node == nullptr) return;

    cout << prefix;
    cout << (isLeft ? "--- " : "+-- ");

    // 노드의 값과 높이 출력
    cout << node->data << " (h:" << node -> height << ")" << " (s:" << node->size << ")" << " (d:" << AvlTreeMetrics::CalculateDepth(node) << ")" << "\n";

    // 자식 노드 출력을 위한 새로운 prefix 생성
    string newPrefix = prefix + (isLeft ? "|   " : "    ");

    // 왼쪽 자식을 먼저 출력한 후 오른쪽 자식 출력
    PrintTreeRecursive(node->left, newPrefix, true);
    PrintTreeRecursive(node->right, newPrefix, false);
}

#endif