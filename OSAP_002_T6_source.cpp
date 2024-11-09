#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

class AvlTree {
public:
  AvlTree() : root(nullptr){};
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
  void Insert(int x);                
  int Empty() ;                 
  void Size() const;                  
  void Height() const;                 
  void Ancestor(int x);                
  double Average(int x);            
  void Rank(int x);                    
  int Erase(int x);
  
  Node* getroot(){return root;}

private:
  Node* root = nullptr;  //루트 노드를 가리키는 포인터
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

  //특정 노드를 값에 의해 찾고 반환해주는 함수
  static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value);


  //부모 노드로 거슬러 올라가며 key값 더하는 함수
  static int GetPathToRootSum(AvlTree::Node *); 

};

class RankUtils{
public:
  //x 값보다 작은 값을 가진 노드 수 + 1 값 반환
  static int RankSearch (AvlTree::Node* root, int x);
  //루트 기준 오른쪽 서브트리 탐색
  static int RankRootRightSearch(AvlTree::Node* node, int find_value);
  //루트 왼쪽 서브트리의 총 노드 개수 출력
  static int RankRootEqualSearch(AvlTree::Node* node);
  //루트 기준 왼쪽 서브트리 탐색
  static int RankRootLeftSearch(AvlTree::Node* node, int find_value);  

};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);


    
    return 0;
}

void AvlTree::Ancestor(int x){  
  Node *node = AvlTreeUtils::NodeFindByValue(root, x);
  
  int depth = node->depth;
  int height = node->height;
  int parent_path_sum = AvlTreeUtils::GetPathToRootSum(node->parent); 

  cout << depth + height << " " << parent_path_sum << "\n";
}

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node *node) {  
  int key_sum = 0;

  while(node != nullptr) {   
    key_sum += node->data;
    node = node->parent;
  }

  return key_sum;
}

AvlTree::Node* AvlTreeUtils::NodeFindByValue(AvlTree::Node* root, int find_data){
    if (root == nullptr || root -> data == find_data){
      return root;
    }

    if (find_data < root -> data){
      NodeFindByValue(root -> left, find_data);
    }
    if (find_data > root -> data){
      NodeFindByValue(root -> right, find_data);
    }
}

//불균형인 노드를 찾고 유형에 맞는 rotate 함수를 호출해주는 함수
AvlTree::Node* AvlRotateUtils::AvlSet(AvlTree::Node* current_node){
  AvlTree::Node* parent = FindUnbalancedNode(current_node);

  //불균형인 노드가 없기에 현재 노드를 반환
  if (parent == nullptr){
    return current_node;
  }

  int parent_balance_factor = CalculateBalanceFactor(parent);
  int left_child_balance_factor = CalculateBalanceFactor(parent -> left);
  int right_child_balance_factor = CalculateBalanceFactor(parent -> right);

  if (parent_balance_factor < -1 && right_child_balance_factor <= 0 ){
    return RR(parent);   //RR
  }

  if (parent_balance_factor > 1 && left_child_balance_factor >= 0){
    return LL(parent);   //LL
  }
    
  if (parent_balance_factor > 1 && left_child_balance_factor < 0){
    return LR(parent);   //LR
  }
  
  if (parent_balance_factor < -1 && right_child_balance_factor > 0) {
    return RL(parent);   //RL
  }
    
}

AvlTree::Node* AvlRotateUtils::FindUnbalancedNode (AvlTree::Node* node){
  if (node == nullptr){  //불균형인 노드가 없는 경우
    return nullptr;
  }
  int balance_factor = CalculateBalanceFactor(node);
  
  if (balance_factor < -1 || balance_factor > 1){
    return node;
  }

  return FindUnbalancedNode(node -> parent);
} 

//불균형인 노드를 rotate 해주는 함수
AvlTree::Node* AvlRotateUtils::RR(AvlTree::Node* parent){
  AvlTree::Node* temp = parent -> right;

  parent -> right = temp -> left;
  temp -> left = parent;
  return temp;
}
AvlTree::Node* AvlRotateUtils::LL(AvlTree::Node* parent){
  AvlTree::Node* temp = parent -> left;

  parent -> left = temp -> right;
  temp -> right = parent;
  return temp;
}
AvlTree::Node* AvlRotateUtils::LR(AvlTree::Node* parent){
  parent -> left = RR(parent -> left);
  return LL(parent);
    
}
AvlTree::Node* AvlRotateUtils::RL(AvlTree::Node* parent){
  parent -> right = LL(parent -> right);
  return RR(parent);
}

void AvlTree::Height() const{
  if (root == nullptr) {
    cout << -1 << "\n";
  } else {
    cout << root -> height << endl;
  }
}    

void AvlTree::Rank(int x){
  Node* root = getroot();
  Node* node = AvlTreeUtils::NodeFindByValue(root, x);
  
  if (node == nullptr) {
    cout << 0 << "\n";
    return;
  }

  int depth_plus_height_sum = node -> depth + node -> height;
  int node_rank = RankUtils::RankSearch(root, x);

  cout << depth_plus_height_sum + " " + node_rank << "\n";
}


int RankUtils::RankSearch(AvlTree::Node* root, int find_value){
    
  //루트 기준 find_value가 root -> data보다 작은 경우 루트의 왼쪽 서브트리 중 find_value보다 작은 노드의 개수 + 1을 반환 
  if (find_value < root -> data) {  
    return RankRootEqualSearch(root -> left) - RankRootLeftSearch(root -> left, find_value) + 1;
  }

  //루트 기준 find_value가 root -> data랑 같은 경우 루트의 왼쪽 서브트리의 총 노드 개수 반환
  if (find_value == root -> data) {
    return RankRootEqualSearch(root -> left) + 1;
  }

  //루트 기준 find_value가 root -> data보다 큰 경우 루트의 오른쪽 서브트리 중 find_value를 찾을 때까지 탐색한 총 노드 수 + 루트 왼쪽 서브트리 총 개수 + 루트 
  if (find_value > root -> data) {
    return 1 + RankRootRightSearch(root -> right, find_value) + RankRootEqualSearch(root -> left);
  } 
}

int RankUtils::RankRootRightSearch(AvlTree::Node* node, int find_value){
  if (node == nullptr) {
    return 0;
  }

  if (node -> data == find_value) {
      return 1;
  }

  return 1 + RankRootRightSearch(node -> left, find_value) + RankRootRightSearch(node -> right, find_value) + 1;
}
//루트 왼쪽 서브트리의 총 노드 개수 출력
int RankUtils::RankRootEqualSearch(AvlTree::Node* node){
  if (node == nullptr) {
    return 0;
  }

  return 1 + RankRootEqualSearch(node -> left) + RankRootEqualSearch(node -> right);
}

//루트 기준 왼쪽 서브트리 탐색
int RankUtils::RankRootLeftSearch(AvlTree::Node* node, int find_value){
  if (node == nullptr) {
    return 0;
  }
  if (node -> data == find_value) {
    return 1;
  }

  return 1 + RankRootLeftSearch(node -> left, find_value) + RankRootLeftSearch(node -> right, find_value);
}

//Height, Rank 함수 및 필요한 외부 함수 main.cpp 추가 완료 


