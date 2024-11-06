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


   
  int Find(int x) ;                    
  int Insert(int x);                
  int Empty() ;                 
  int Size() ;                  
  void Height() const;                 
  void Ancestor(int x) const;                
  double Average(int x);            
  void Rank(int x);                    
  int Erase(int x);   

  //x 값보다 작은 값을 가진 노드 수 + 1 값 반환
  int RankSearch(int x);
    
  //rotate 관련 함수
  int CalculateBalanceFactor(Node* node); //특정 노드의 균형인수 계산
  Node* FindUnbalancedNode (Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수

  //불균형인 노드를 rotate 해주는 함수
  Node* RR(Node* node); 
  Node* LL(Node* node);
  Node* LR(Node* node);
  Node* RL(Node* node);

  //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
  Node* AvlSet(Node* node);

  //특정 노드를 값에 의해 찾고 반환해주는 함수
  Node* NodeFindByValue(Node* head, int value) const;

  //특정 노드 중위 순회하면서 rank 반환해주는 함수
  // int InorderTraversalByValue(Node* node, int x);
  
  int node_count_; 
  // int node_rank_count_;

  int UpdateDepth(Node *node); // 특정 노드에 대해 Depth 업데이트 하는 함수
  int UpdateHeight(Node *node);  // 특정 노드에 대해 Height 업데이트 하는 함수

  int GetPathToRootSum(Node *node) const; // 특정 노드부터 루트까지의 경로의 노드들의 key 값들의 합을 구하는 함수 
private:
  Node* root = nullptr;  //루트 노드를 가리키는 포인터

};

#endif
