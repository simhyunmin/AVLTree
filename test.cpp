#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class AvlTree {
public:
    AvlTree() : root(nullptr), node_count_(0) {};
    ~AvlTree() { Clear(root); };

    struct Node {
        int data;
        int height;
        Node* left;
        Node* right;
        Node* parent;

        Node(int data_) : data(data_), height(0), left(nullptr), right(nullptr), parent(nullptr) {}
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
        cout << node_count_ << "\n";
    }
    void Height() const;
    void Ancestor(int x);
    void Average(int x);
    void Rank(int x);
    Node* EraseNode(Node* node, int x, bool& found);
    void Erase(int x);
    //모든 노드를 삭제해주는 함수 (소멸자 부분에서 호출)
    void Clear(Node* node);

    int CalculateBalanceFactor(AvlTree::Node* node); //특정 노드의 균형인수 계산
    Node* FindUnbalancedNode(AvlTree::Node* node); // 특정 노드를 기준으로 부모 노드를 거슬러 올라가면서 불균형인 노드를 찾는 함수

    //불균형인 노드를 rotate 해주는 함수
    Node* RightRotate(AvlTree::Node* node);
    Node* LeftRotate(AvlTree::Node* node);

    void PrintTree() const {
        cout << "\n=== Tree Visualization ===\n";
        if (root == nullptr) {
            cout << "Empty tree\n";
            return;
        }
        PrintTreeRecursive(root, "", true);
        cout << "=======================\n";
    }

private:
    Node* root;  //루트 노드를 가리키는 포인터
    int node_count_; //트리의 노드수
    void PrintTreeRecursive(Node* node, string prefix, bool isLeft) const {
        if (node == nullptr) return;

        cout << prefix;
        cout << (isLeft ? "--- " : "+-- ");

        // 노드의 값과 높이 출력
        cout << node->data << " (h:" << node->height << ")" << endl;

        // 자식 노드 출력을 위한 새로운 prefix 생성
        string newPrefix = prefix + (isLeft ? "|   " : "    ");

        // 왼쪽 자식을 먼저 출력한 후 오른쪽 자식 출력
        PrintTreeRecursive(node->left, newPrefix, true);
        PrintTreeRecursive(node->right, newPrefix, false);
    }
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
//   std::ifstream inputFile("input.txt");

  int T;
  cin >> T;
  while(T--){
    int Q;
    cin >> Q;
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
      else if (command == "PrintTree") {
        avl_tree.PrintTree();
      }
    cin.clear();
    }
  }
  return 0;
}


int AvlTreeUtils::CalculateDepth(AvlTree::Node* node) {
    int depth = 0;
    while (node->parent != nullptr) {
        node = node->parent;
        ++depth;
    }
    return depth;
}

AvlTree::Node* AvlTreeUtils::MinValueNode(AvlTree::Node* node) {
    AvlTree::Node* temp = node;
    while (temp && temp->left != nullptr) {
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

AvlTree::Node* AvlTreeUtils::NodeFindByValue(AvlTree::Node* node, int find_data) {
    if (node == nullptr || node->data == find_data) {
        return node;
    }
    if (find_data > node->data) {
        return NodeFindByValue(node->right, find_data);
    }
    else {
        return NodeFindByValue(node->left, find_data);
    }
}

void AvlTreeUtils::UpdateHeight(AvlTree::Node* node) {
    if (node) {
        node->height = 1 + std::max(node->left ? node->left->height : -1, node->right ? node->right->height : -1);
    }
    return;
}

int AvlTreeUtils::SubtreeHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->height + 1;
}

int AvlTreeUtils::GetHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}


//특정 노드의 균형인수 계산
int AvlTree::CalculateBalanceFactor(AvlTree::Node* node) {
    if (node == nullptr) { return 0; }
    return AvlTreeUtils::SubtreeHeight(node->left) - AvlTreeUtils::SubtreeHeight(node->right);
}

AvlTree::Node* AvlTree::FindUnbalancedNode(AvlTree::Node* node) {
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
AvlTree::Node* AvlTree::RightRotate(Node* parent_node){
  Node* ch = parent_node->left;
  Node* ch_right = ch->right;

  ch->right = parent_node;
  parent_node->left = ch_right;

  if(ch_right) {ch_right -> parent = parent_node;}
  ch -> parent = parent_node -> parent;
  parent_node -> parent = ch;

  
  if (ch -> parent) {
    if (ch -> parent -> left == parent_node) {
      ch -> parent -> left = ch;
    } else {
      ch -> parent -> right = ch;
    }
  }  
  parent_node -> height = max(AvlTreeUtils::GetHeight(parent_node -> left), AvlTreeUtils::GetHeight(parent_node -> right)) + 1;
  ch -> height = max(AvlTreeUtils::GetHeight(ch -> left), AvlTreeUtils::GetHeight(ch -> right)) + 1;

  return ch;
}
AvlTree::Node* AvlTree::LeftRotate(Node* parent_node){
  Node* ch = parent_node->right;
  Node* ch_left = ch->left;
  //부모 노드의 오른쪽 자식의 왼쪽 자식을 부모 노드로 설정
  //원래 부모 노드의 오른쪽 자식의 왼쪽 자식을 원래 부모 노드의 오른쪽 자식으로 설정
  ch->left = parent_node;
  parent_node->right = ch_left;

  //각 위치가 바뀐 노드에 대해서 부모 노드 업데이트
  if(ch_left) {ch_left -> parent = parent_node;}
  ch -> parent = parent_node -> parent;
  parent_node -> parent = ch;
  //parent_node가 원래 부모의 왼쪽 자식이었는지 오른쪽 자식이었는지에 따라 ch -> parent에서 left, right 자식 설정
  if (ch -> parent) {
    if (ch -> parent -> left == parent_node) {
      ch -> parent -> left = ch;
    } else {
      ch -> parent -> right = ch;
    }
  }
  //높이 업데이트 해주는 부분
  //parent_node -> height 먼저 수정하고 ch -> height 수정
  parent_node->height = max(AvlTreeUtils::GetHeight(parent_node -> left), AvlTreeUtils::GetHeight(parent_node -> right)) + 1;
  ch->height = max(AvlTreeUtils::GetHeight(ch -> left), AvlTreeUtils::GetHeight(ch -> right)) + 1;

  return ch;
}
AvlTree::Node* AvlTree::InsertNode(AvlTree::Node* node, int insert_data, int& depth_height_sum, int depth) {
    //노드가 nullptr일 경우
    if (!node) {
        ++node_count_;
        depth_height_sum = depth + 1;
        return new Node(insert_data);
    }
    //삽입할 insert_data가 현재 노드 data보다 작으면 왼쪽 서브트리 삽입
    if (insert_data < node->data) {
        node->left = InsertNode(node->left, insert_data, depth_height_sum, depth + 1);
        node->left->parent = node;
    }
    else if (insert_data > node->data) {
        node->right = InsertNode(node->right, insert_data, depth_height_sum, depth + 1);
        node->right->parent = node;
    }

    AvlTreeUtils::UpdateHeight(node);

    int balance = CalculateBalanceFactor(node);

    if (balance > 1 && insert_data < node->left->data) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return RightRotate(node);
    }
    if (balance < -1 && insert_data > node->right->data) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return LeftRotate(node);
    }

    if (balance > 1 && insert_data > node->left->data) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && insert_data < node->right->data) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

void AvlTree::Insert(int insert_data) {
    int depth_height_sum = 0;
    root = InsertNode(root, insert_data, depth_height_sum, -1);
    //cout << depth_height_sum << "\n";
    Node* fNode = AvlTreeUtils::NodeFindByValue(root,insert_data);
    cout << fNode->height + AvlTreeUtils::CalculateDepth(fNode) << endl;

}

AvlTree::Node* AvlTree::EraseNode(Node* node, int erase_data, bool& found) {
    if (!node) {
        return nullptr;
    }

    if (erase_data < node->data) { // 왼쪽 서브트리에 있을 경우
        node->left = EraseNode(node->left, erase_data, found);
    }
    else if (erase_data > node->data) { // 오른쪽 서브트리에 있을 경우
        node->right = EraseNode(node->right, erase_data, found);
    }
    else {
        found = true; // 노드 발견
        node_count_--;

        if (!node->left || !node->right) { // 자식이 하나 이하인 경우
            Node* temp = node->left ? node->left : node->right; // 자식 선택
            delete node;
            return temp;
        }
        else { //자식이 둘인 경우
            Node* temp = AvlTreeUtils::MinValueNode(node->right);
            node->data = temp->data;
            node->right = EraseNode(node->right, temp->data, found);
        }
    }

    AvlTreeUtils::UpdateHeight(node);

    int balance = CalculateBalanceFactor(node);
    int left_child_balance = CalculateBalanceFactor(node->left); // 왼쪽 자식 노드의 균형 인수 계산
    int right_child_balance = CalculateBalanceFactor(node->right); // 오른쪽 자식 노드의 균형 인수 계산

    if (balance > 1 && left_child_balance >= 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return RightRotate(node);
    }

    if (balance < -1 && right_child_balance <= 0) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return LeftRotate(node);
    }

    if (balance > 1 && left_child_balance < 0) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        node->left = LeftRotate(node->left);
        return RightRotate(node);
    }

    if (balance < -1 && right_child_balance > 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        node->right = RightRotate(node->right);
        return LeftRotate(node);
    }

    return node;
}

void AvlTree::Erase(int x) {
    bool found = false;
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    if (node == nullptr) {
        cout << 0 << "\n";
        return;
    }
    int depth_height_sum = node->height + AvlTreeUtils::CalculateDepth(node);
    cout << depth_height_sum << "\n";
    root = EraseNode(root, x, found);
}


void AvlTree::Find(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    //cout << AvlTreeUtils::CalculateDepth(node) << ", " << node->height << endl;
    cout << ((node != nullptr) ? AvlTreeUtils::CalculateDepth(node) + node->height : 0) << "\n";
}

void AvlTree::Ancestor(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);

    int depth = AvlTreeUtils::CalculateDepth(node);
    int height = node->height;
    int parent_path_sum = AvlTreeUtils::GetPathToRootSum(node->parent);
    //cout << depth << " " << height << "\n";
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
        cout << root->height << endl;
    }
}

void AvlTree::Rank(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);/////////////////////////////////////////////////
    if (node == nullptr) {
        cout << 0 << "\n";
        return;
    }
    int node_rank = RankUtils::RankSearch(root, x);
    if (node_rank == 0) {
        cout << 0 << "\n";
        return;
    }
    int depth_plus_height_sum = AvlTreeUtils::CalculateDepth(node) + node->height;
    cout << to_string(depth_plus_height_sum) + " " + to_string(node_rank) << "\n";
}


int RankUtils::RankSearch(AvlTree::Node* root, int find_value) {

    if (root == nullptr) { return 0; }

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


