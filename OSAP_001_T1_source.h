#ifndef OSAP_001_T1_SOURCE_H
#define OSAP_001_T1_SOURCE_H

#include <iostream>
#include <algorithm>

class AvlTree {
public:
    AvlTree();
    ~AvlTree();
     
    struct Node {
        int height;
        int depth; 
        int data;
        Node* left;
        Node* right;
        Node* parent;

        Node(int data_, int depth_ = 0) : data(data_), height(0), depth(depth_), left(nullptr), right(nullptr), parent(nullptr) {}
    };


   
    int Find(int x);                    
    int Insert(int x);                
    int Empty() const;                 
    int Size() const;                  
    int Height() const;                 
    int Ancestor(int x);                
    double Average(int x);            
    int Rank(int x);                    
    int Erase(int x);   

    int CalculateBalanceFactor(Node* node); //특정 노드의 균형인수 계산
    int GetSubTreeHeight(Node* node); //특정 노드를 기준으로 서브 트리의 높이를 구하는 함수
    Node* FindUnbalancedNode (Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수

    //불균형인 노드를 rotate 해주는 함수
    Node* RR(Node* node); 
    Node* LL(Node* node);
    Node* LR(Node* node);
    Node* RL(Node* node);

    //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
    Node* AvlSet(Node* node);
private:
    Node* head;
    int node_count_; 

};

#endif
