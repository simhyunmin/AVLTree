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
    void Find(int x);
    Node* InsertNode(Node* node, int x, int& depth_height_sum, int depth);
    void Insert(int x);
    // set이 비어 있다면 1을, 아니면 0을 출력한다.
    void Empty() {
        cout << ((root == nullptr) ? 1 : 0) << "\n";
    }
    //set에 저장된 원소의 수를 출력한다
    void Size() const {
        if (root == nullptr) {
            cout << 0 << "\n";
            return;
        }
        cout << root->size << "\n";
    }
    void Height() const;
    void Ancestor(int x);
    void Average(int x);
    void Rank(int x);
    int CalculateRank(Node* node, int x);
    Node* EraseNode(Node* node, int x);
    void Erase(int x);
    //모든 노드를 삭제해주는 함수 (소멸자 부분에서 호출)
    void Clear(Node* node);

    int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
    Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수

    //불균형인 노드를 rotate 해주는 함수
    Node* RightRotate(AvlTree::Node* node);
    Node* LeftRotate(AvlTree::Node* node);
    void PrintTreeRecursive(Node* node, string prefix, bool isLeft);
    void PrintTree();
private:
    Node* root;  //루트 노드를 가리키는 포인터
};

class AvlTreeUtils {
public:
    //Depth 계산 함수
    static int CalculateDepth(AvlTree::Node* node);
    //특정 노드를 값에 의해 찾고 반환해주는 함수
    static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value);
    //부모 노드로 거슬러 올라가며 key값 더하는 함수
    static int GetPathToRootSum(AvlTree::Node*);
    static AvlTree::Node* MinValueNode(AvlTree::Node* node);
    static void UpdateHeight(AvlTree::Node* node);
    static int SubtreeHeight(AvlTree::Node* node);
    static int GetHeight(AvlTree::Node* node);
    static int GetSize(AvlTree::Node* node);
    static void UpdateSize(AvlTree::Node* node);
    static int CalculateHeight(AvlTree::Node* node);
};


#endif
