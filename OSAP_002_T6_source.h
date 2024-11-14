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
    int data;
    Node* left;
    Node* right;
    Node* parent;

    Node(int data_, int depth_ = 0) : data(data_), height(0), depth(depth_), left(nullptr), right(nullptr), parent(nullptr) {}
  };

  void Find(int x);                    
  int Insert(int x);                
  // set이 비어 있다면 1을, 아니면 0을 출력한다.
  void Empty() {
    cout <<  ( ( root == nullptr ) ? 1 : 0 ) << "\n";
  }
  //set에 저장된 원소의 수를 출력한다
  void Size() const{
    cout << node_count_ << endl;
  }                 
  void Height() const;                 
  void Ancestor(int x);                
  double Average(int x);            
  void Rank(int x);                    
  int Erase(int x);   

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

  
private:
  Node* root = nullptr;  //루트 노드를 가리키는 포인터
  int node_count_; //트리의 노드수
};

class AvlRotateUtils {
public:
    static int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
    static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
    //불균형인 노드를 rotate 해주는 함수
    static AvlTree::Node* RR(AvlTree::Node* node);
    static AvlTree::Node* LL(AvlTree::Node* node);
    static AvlTree::Node* LR(AvlTree::Node* node);
    static AvlTree::Node* RL(AvlTree::Node* node);

    //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
    static AvlTree::Node* AvlSet(AvlTree::Node* node);
};


class AvlTreeUtils {
public:
    //Height계산 함수
    static int CalculateHeight(AvlTree::Node* node);
    //Depth 계산 함수
    static int CalculateDepth(AvlTree::Node* node);
    //특정 노드를 값에 의해 찾고 반환해주는 함수
    static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value);


    //부모 노드로 거슬러 올라가며 key값 더하는 함수
    static int GetPathToRootSum(AvlTree::Node*);

};

class RankUtils {
public:
    //x 값보다 작은 값을 가진 노드 수 + 1 값 반환
    static int RankSearch(AvlTree::Node* root, int x);
    //루트 기준 오른쪽 서브트리 탐색
    static int RankRootRightSearch(AvlTree::Node* node, int find_value);
    //루트 왼쪽 서브트리의 총 노드 개수 출력
    static int RankRootEqualSearch(AvlTree::Node* node);
    //루트 기준 왼쪽 서브트리 탐색
    static int RankRootLeftSearch(AvlTree::Node* node, int find_value);

};

#endif
