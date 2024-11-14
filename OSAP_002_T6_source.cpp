#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class AvlTree {
public:
    AvlTree() : root(nullptr), node_count_(0) {};
    ~AvlTree() { Clear(root); };

    struct Node {
        int data;
        Node* left;
        Node* right;
        Node* parent;

        Node(int data_, int depth_ = 0) : data(data_), left(nullptr), right(nullptr), parent(nullptr) {}
    };

<<<<<<< HEAD
  Node* getroot(){return root;}
  //모든 노드를 삭제해주는 함수 (소멸자 부분에서 호출)
  void Clear(Node* node);
  Node* InsertNode(Node* node, int x, int& depth_height_sum, int depth);
  Node* EraseNode(Node* node, int x, bool& found);
=======
    void Find(int x);
    void Insert(int x);
    // set이 비어 있다면 1을, 아니면 0을 출력한다.
    void Empty() {
        cout << ((root == nullptr) ? 1 : 0) << "\n";
    }
    //set에 저장된 원소의 수를 출력한다
    void Size() const {
        cout << node_count_ << endl;
    }
    void Height() const;
    void Ancestor(int x);
    void Average(int x);
    void Rank(int x);
    void Erase(int x);

    Node* getroot() { return root; }
    //모든 노드를 삭제해주는 함수 (소멸자 부분에서 호출)
    void Clear(Node* node);

>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8
private:
    Node* root;  //루트 노드를 가리키는 포인터
    int node_count_; //트리의 노드수
};


class AvlRotateUtils {
public:
<<<<<<< HEAD
  static int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
  static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
  
  //불균형인 노드를 rotate 해주는 함수
  static void RR(AvlTree::Node* node);
  static void LL(AvlTree::Node* node);
  static void LR(AvlTree::Node* node);
  static void RL(AvlTree::Node* node);
  
  //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
  static void AvlSet(AvlTree::Node* node);
=======
    static int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
    static AvlTree::Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수
    //불균형인 노드를 rotate 해주는 함수
    static AvlTree::Node* RR(AvlTree::Node* node);
    static AvlTree::Node* LL(AvlTree::Node* node);
    static AvlTree::Node* LR(AvlTree::Node* node);
    static AvlTree::Node* RL(AvlTree::Node* node);

    //불균형인 노드를 기준으로 유형에 맞는 rotate 함수를 호출해주는 함수
    static AvlTree::Node* AvlSet(AvlTree::Node* node);
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8
};


class AvlTreeUtils {
public:
<<<<<<< HEAD
  static int CalculateHeight(AvlTree::Node* node);
  static int CalculateDepth(AvlTree::Node* node);
  //특정 노드를 값에 의해 찾고 반환해주는 함수
  static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value);
=======
    //Height계산 함수
    static int CalculateHeight(AvlTree::Node* node);
    //Depth 계산 함수
    static int CalculateDepth(AvlTree::Node* node);
    //특정 노드를 값에 의해 찾고 반환해주는 함수
    static AvlTree::Node* NodeFindByValue(AvlTree::Node* node, int value);
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8


    //부모 노드로 거슬러 올라가며 key값 더하는 함수
    static int GetPathToRootSum(AvlTree::Node*);

  static AvlTree::Node* minValueNode(AvlTree::Node* node);

  static void UpdateParentHeight(AvlTree::Node* node);

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


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
<<<<<<< HEAD
    
    while(T--){
      int Q;
      cin >> Q;
      cin.clear();
=======
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8

    while (T--) {
        int Q;
        cin >> Q;

<<<<<<< HEAD
        if (command == "Empty") {
          avl_tree.Empty();
        } else if (command == "Size") {
          avl_tree.Size();
        } else if (command == "Height") {
          avl_tree.Height();
        } else if (command == "Insert") {
          int x;
          cin >> x;
          avl_tree.Insert(x);
        } else if (command == "Find") {
          int x;
          cin >> x;
          avl_tree.Find(x); // 노드의 깊이와 높이의 합 출력
        } else if (command == "Ancestor") {
          int x;
          cin >> x;
          avl_tree.Ancestor(x); // 조상 출력
        } else if (command == "Average") {
          int x;
          cin >> x;
          avl_tree.Average(x); // 평균 출력
        } else if (command == "Rank") {
          int x;
          cin >> x;
          avl_tree.Rank(x);
        } else if (command == "Erase") {
          int x;
          cin >> x;
          avl_tree.Erase(x);
=======
        AvlTree avl_tree;
        for (int i = 0; i < Q; ++i) {
            string command;
            cin >> command;

            if (command == "Empty") {
                avl_tree.Empty();
            }
            else if (command == "Size") {
                avl_tree.Size();
            }
            else if (command == "Height") {
                avl_tree.Height();
            }
            else if (command == "Insert") {
                int x;
                cin >> x;
                cout << command + to_string(x) << "\n";
                avl_tree.Insert(x);
            }
            else if (command == "Find") {
                int x;
                cin >> x;
                avl_tree.Find(x); // 노드의 깊이와 높이의 합 출력
            }
            else if (command == "Ancestor") {
                int x;
                cin >> x;
                avl_tree.Ancestor(x); // 조상 출력
            }
            else if (command == "Average") {
                int x;
                cin >> x;
                avl_tree.Average(x); // 평균 출력
            }
            else if (command == "Rank") {
                int x;
                cin >> x;
                avl_tree.Rank(x);
            }
            else if (command == "Erase") {
                int x;
                cin >> x;
                avl_tree.Erase(x);
            }
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8
        }
    }



    return 0;
}

int AvlTreeUtils::CalculateHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(CalculateHeight(node->left), CalculateHeight(node->right)) + 1;
}

int AvlTreeUtils::CalculateDepth(AvlTree::Node* node) {
    if (node->parent == nullptr) {
        return 0;
    }
    return CalculateDepth(node->parent) + 1;
}


AvlTree::Node* AvlTreeUtils::minValueNode(AvlTree::Node* node){
  AvlTree::Node* temp = node;
  while (temp && temp->left != nullptr){
    temp = temp->left;
  }
  return temp;
}

void AvlTree::Clear(AvlTree::Node* node) {
    if (node != nullptr) {
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
}

AvlTree::Node* AvlTreeUtils::NodeFindByValue(AvlTree::Node* root, int find_data) {
    if (root == nullptr || root->data == find_data) {
        return root;
    }

    if (find_data < root->data) {
        return NodeFindByValue(root->left, find_data);
    }
    else if (find_data > root->data) {
        return NodeFindByValue(root->right, find_data);
    }
    else {
        return root;
    }
}

//특정 노드의 균형인수 계산
int AvlRotateUtils::CalculateBalanceFactor(AvlTree::Node* node) {
    if (node == nullptr) { return 0; }
    return (AvlTreeUtils::CalculateDepth(node)) - (AvlTreeUtils::CalculateHeight(node));
}

//불균형인 노드를 찾고 유형에 맞는 rotate 함수를 호출해주는 함수
<<<<<<< HEAD
void AvlRotateUtils::AvlSet(AvlTree::Node* current_node){
  AvlTree::Node* unbalanced_node = AvlRotateUtils::FindUnbalancedNode(current_node);

  //불균형인 노드가 없는 경우
  if(unbalanced_node == nullptr) {
    return;
  }

  int parent_balance_factor = CalculateBalanceFactor(unbalanced_node);
  int left_child_balance_factor = CalculateBalanceFactor(unbalanced_node -> left);
  int right_child_balance_factor = CalculateBalanceFactor(unbalanced_node -> right);

  if (parent_balance_factor < -1 && right_child_balance_factor <= 0 ){
    RR(unbalanced_node);   //RR
  }

  if (parent_balance_factor > 1 && left_child_balance_factor >= 0){
    LL(unbalanced_node);   //LL
  }
    
  if (parent_balance_factor > 1 && left_child_balance_factor < 0){
    LR(unbalanced_node);   //LR
  }
  
  if (parent_balance_factor < -1 && right_child_balance_factor > 0) {
    RL(unbalanced_node);   //RL
  }
=======
AvlTree::Node* AvlRotateUtils::AvlSet(AvlTree::Node* current_node) {
    AvlTree::Node* parent = FindUnbalancedNode(current_node);

    int parent_balance_factor = CalculateBalanceFactor(parent);
    int left_child_balance_factor = CalculateBalanceFactor(parent->left);
    int right_child_balance_factor = CalculateBalanceFactor(parent->right);

    if (parent_balance_factor < -1 && right_child_balance_factor <= 0) {
        return RR(parent);   //RR
    }

    if (parent_balance_factor > 1 && left_child_balance_factor >= 0) {
        return LL(parent);   //LL
    }

    if (parent_balance_factor > 1 && left_child_balance_factor < 0) {
        return LR(parent);   //LR
    }

    if (parent_balance_factor < -1 && right_child_balance_factor > 0) {
        return RL(parent);   //RL
    }
    //불균형인 노드가 없기에 현재 노드를 반환
    return current_node;
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8
}

AvlTree::Node* AvlRotateUtils::FindUnbalancedNode(AvlTree::Node* node) {
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
<<<<<<< HEAD
void AvlRotateUtils::RR(AvlTree::Node* parent_node){
  AvlTree::Node* temp = parent_node -> right;
  temp -> parent = parent_node -> parent;
  parent_node -> parent = temp;
  parent_node -> right = temp -> left;
  temp -> left = parent_node;
}
void AvlRotateUtils::LL(AvlTree::Node* parent_node){
  AvlTree::Node* temp = parent_node -> left;
  temp -> parent = parent_node -> parent;
  parent_node -> parent = temp;
  parent_node -> left = temp -> right;
  temp -> right = parent_node;
}
void AvlRotateUtils::LR(AvlTree::Node* parent_node){
  RR(parent_node -> left);
  LL(parent_node);
    
}
void AvlRotateUtils::RL(AvlTree::Node* parent_node){
  LL(parent_node -> right);
  RR(parent_node);
}

void AvlTree::Insert(int insert_data){ // 노드 x를 삽입하고 나서 깊이와 높이의 합을 출력
  node_count_++;
  //빈 트리일 경우 root에 삽입
  Node* newNode = new Node(insert_data);
  if(root == nullptr) {
    root = newNode;
    cout << 0 << "\n";
    return;
  }
=======
AvlTree::Node* AvlRotateUtils::RR(AvlTree::Node* parent) {
    AvlTree::Node* temp = parent->right;

    parent->right = temp->left;
    temp->left = parent;
    return temp;
}
AvlTree::Node* AvlRotateUtils::LL(AvlTree::Node* parent) {
    AvlTree::Node* temp = parent->left;

    parent->left = temp->right;
    temp->right = parent;
    return temp;
}
AvlTree::Node* AvlRotateUtils::LR(AvlTree::Node* parent) {
    parent->left = RR(parent->left);
    return LL(parent);

}
AvlTree::Node* AvlRotateUtils::RL(AvlTree::Node* parent) {
    parent->right = LL(parent->right);
    return RR(parent);
}

void AvlTree::Insert(int x) {
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8

  Node* current_node = root;
  Node* current_parent = nullptr;

  //삽입 위치 찾기
  while (current_node != nullptr) {
    current_parent = current_node;
    if (insert_data < current_node -> data) {
      current_node = current_node -> left;
    } else {
      current_node = current_node -> right;
    }
  }

  //부모 노드 기준으로 왼쪽, 오른쪽 자식 설정
  //위에서는 삽입 위치만 찾은거고 부모 노드의 자식은 설정 안 했기에
  if (insert_data < current_parent -> data) {
    current_parent -> left = newNode;
  } else {
    current_parent -> right = newNode;
  }

  newNode -> parent = current_parent;

  //삽입된 위치를 기준으로 불균형인 노드를 찾고 rotate 해주기
  AvlRotateUtils::AvlSet(newNode);
  cout << AvlTreeUtils::CalculateHeight(newNode) + AvlTreeUtils::CalculateDepth(newNode) << "\n";
  
}

void AvlTreeUtils::UpdateParentHeight(AvlTree::Node* node){
  while (node != nullptr) {
    int left_height = (node -> left != nullptr) ? node -> left -> height : -1;
    int right_height = (node -> right != nullptr) ? node -> right -> height : -1;

    node -> height = max(left_height, right_height) + 1;

    node = node -> parent;
  }
}

<<<<<<< HEAD
void AvlTree::Erase(int x){
  Node* erase_node = AvlTreeUtils::NodeFindByValue(root, x);
  Node* erase_parent_node = erase_node -> parent;
=======
void AvlTree::Erase(int x) {
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8

  if (erase_node == nullptr) {
    cout << 0 << "\n";
    return;
  }
  node_count_--;
  cout << AvlTreeUtils::CalculateHeight(erase_node) + AvlTreeUtils::CalculateDepth(erase_node) << "\n";
  //자식이 존재하지 않는 경우
  if (!(erase_node -> left && erase_node -> right)) {
    delete erase_node;
    erase_node = nullptr;
  }
  //오른쪽 자식만 존재하는 경우
  else if (erase_node -> left == nullptr && erase_node -> right != nullptr) {
    Node* temp = erase_node -> right;
    temp -> parent = erase_node -> parent;
    delete erase_node;
    erase_node = temp;
  }
  //왼쪽 자식만 존재하는 경우
  else if (erase_node -> right == nullptr && erase_node -> left != nullptr) {
    Node* temp = erase_node -> left;
    temp -> parent = erase_node -> parent;
    delete erase_node;
    erase_node = temp;
  }
  //둘 다 존재하는 경우
  else {
    Node* temp = erase_node -> right;
    //후임자 찾기
    while(temp -> left != nullptr) {
      temp = temp -> left;
    }
    //찾은 후임자 저장
    Node* successor_node = temp;
    //원래 후임자 위치는 삭제
    delete temp;
    temp = nullptr;
  
    successor_node -> parent = erase_node -> parent;
    delete erase_node;
    //후임자를 erase_node 위치로 대체한다.
    erase_node = successor_node;
  }
  //자식이 모두 존재하지 않는 경우 erase_node는 대체되지 않고 삭제되기에
  if(erase_node == nullptr) {
    AvlRotateUtils::AvlSet(erase_parent_node);
  } 
  //그 외에 경우 erase_noed부터 부모 노드를 거슬러 올라가면서 불균형인 노드 찾고 rotate
  else {
    AvlRotateUtils::AvlSet(erase_node);
  }
}


void AvlTree::Find(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    cout << ((node != nullptr) ? AvlTreeUtils::CalculateDepth(node) + AvlTreeUtils::CalculateHeight(node) : 0) << "\n";
}

void AvlTree::Ancestor(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);

    int depth = AvlTreeUtils::CalculateDepth(node);
    int height = AvlTreeUtils::CalculateHeight(node);
    int parent_path_sum = AvlTreeUtils::GetPathToRootSum(node->parent);

    cout << depth + height << " " << parent_path_sum << "\n";
}

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
    int key_sum = 0;

    while (node != nullptr) {
        key_sum += node->data;
        node = node->parent;
    }

    return key_sum;
}

int AvlTreeUtils::CalculateHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return max(CalculateHeight(node->left), CalculateHeight(node->right)) + 1;
}

int AvlTreeUtils::CalculateDepth(AvlTree::Node* node) {
    int depth = 0;
    while (node->parent != nullptr) {
        node = node->parent;
        ++depth;
    }
    return depth;
}

void AvlTree::Average(int x) {
    Node* sub_tree_root = AvlTreeUtils::NodeFindByValue(root, x);

    Node* min_node = sub_tree_root;
    while (min_node->left != NULL) {
        min_node = min_node->left;
    }

    Node* max_node = sub_tree_root;
    while (max_node->right != NULL) {
        max_node = max_node->right;
    }

    cout << static_cast<double>(min_node->data + max_node->data) / 2 << "\n";
}

void AvlTree::Height() const {
    if (root == nullptr) {
        cout << -1 << "\n";
    }
    else {
        cout << AvlTreeUtils::CalculateHeight(root) << endl;
    }
}

void AvlTree::Rank(int x) {
    Node* root = getroot();
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    int node_rank = RankUtils::RankSearch(root, x);
    if (node_rank == 0) {
        cout << 0 << "\n";
        return;
    }
    int depth_plus_height_sum = AvlTreeUtils::CalculateDepth(node) + AvlTreeUtils::CalculateHeight(node);
    cout << to_string(depth_plus_height_sum) + " " + to_string(node_rank) << "\n";
}


<<<<<<< HEAD
int RankUtils::RankSearch(AvlTree::Node* root, int find_value){
  
  if(root == nullptr) {return 0;}
    
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
  return 0;
}

int RankUtils::RankRootRightSearch(AvlTree::Node* node, int find_value){
  if (node == nullptr) {
=======
int RankUtils::RankSearch(AvlTree::Node* root, int find_value) {
    if (root == nullptr) {
        return 0;
    }
    //루트 기준 find_value가 root -> data보다 작은 경우 루트의 왼쪽 서브트리 중 find_value보다 작은 노드의 개수 + 1을 반환 
    if (find_value < root->data) {
        return RankRootEqualSearch(root->left) - RankRootLeftSearch(root->left, find_value) + 1;
    }
    //루트 기준 find_value가 root -> data랑 같은 경우 루트의 왼쪽 서브트리의 총 노드 개수 반환
    if (find_value == root->data) {
        return RankRootEqualSearch(root->left) + 1;
    }
    //루트 기준 find_value가 root -> data보다 큰 경우 루트의 오른쪽 서브트리 중 find_value를 찾을 때까지 탐색한 총 노드 수 + 루트 왼쪽 서브트리 총 개수 + 루트 
    if (find_value > root->data) {
        return 1 + RankRootRightSearch(root->right, find_value) + RankRootEqualSearch(root->left);
    }
>>>>>>> 3f0d7e3200aa23f933364952d5fbcc574fad9ec8
    return 0;
}

int RankUtils::RankRootRightSearch(AvlTree::Node* node, int find_value) {
    if (node == nullptr) {
        return 0;
    }
    if (node->data == find_value) {
        return 1;
    }
    return 1 + RankRootRightSearch(node->left, find_value) + RankRootRightSearch(node->right, find_value) + 1;
}
//루트 왼쪽 서브트리의 총 노드 개수 출력
int RankUtils::RankRootEqualSearch(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return 1 + RankRootEqualSearch(node->left) + RankRootEqualSearch(node->right);
}

//루트 기준 왼쪽 서브트리 탐색
int RankUtils::RankRootLeftSearch(AvlTree::Node* node, int find_value) {
    if (node == nullptr) {
        return 0;
    }
    if (node->data == find_value) {
        return 1;
    }

    return 1 + RankRootLeftSearch(node->left, find_value) + RankRootLeftSearch(node->right, find_value);
}


