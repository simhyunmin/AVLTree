#ifndef OSAP_002_T6_SOURCE_H
#define OSAP_002_T6_SOURCE_H

#include <iostream>
#include <algorithm>
#include <String>
#include <vector>
using namespace std;

class AvlTree {
public:
  AvlTree() : root(nullptr), node_count_(0){};
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

  void Find(int x);                
  int Empty() ;                 
  void Size() const;                  
  void Height() const;                 
  void Ancestor(int x);                
  double Average(int x);            
  void Rank(int x);
  void Insert(int x);                    
  int Erase(int x);

  //x를 삽입하는 함수
  Node* InsertNode(Node* node, int x);   

  //x 값보다 작은 값을 가진 노드 수 + 1 값 반환
  int RankSearch(int x);

  //특정 노드를 값에 의해 찾고 반환해주는 함수
  Node* NodeFindByValue(Node* node, int value);

  //rotate 관련 함수
  int CalculateBalanceFactor(Node* node); //특정 노드의 균형인수 계산
  Node* FindUnbalancedNode (Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
  // int GetSubTreeHeight(Node* node); //특정 노드를 기준으로 서브 트리의 높이를 구하는 함수

  //불균형인 노드를 rotate 해주는 함수
  Node* RR(Node* node); 
  Node* LL(Node* node);
  Node* LR(Node* node);
  Node* RL(Node* node);

  //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
  Node* AvlSet(Node* node);

  int node_count_; 
  
private:
  Node* root = nullptr;  //루트 노드를 가리키는 포인터

};

#endif
