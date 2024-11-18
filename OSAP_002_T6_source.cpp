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



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
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

int AvlTreeUtils::GetPathToRootSum(AvlTree::Node* node) {
    int key_sum = 0;

    while (node != nullptr) {
        key_sum += node->data;
        node = node->parent;
    }

    return key_sum;
}

AvlTree::Node* AvlTreeUtils::FindSuccessor(AvlTree::Node* node) {
    if (node == nullptr) {
        return node;
    }
    AvlTree::Node* temp = node;
    while (temp && temp->left != nullptr) {
        temp = temp->left;
    }
    return temp;
}


AvlTree::Node* AvlTreeUtils::NodeFindByValue(AvlTree::Node* node, int find_data) { 
    while (node != nullptr) {
        if (node->data == find_data) {
            return node;
        }
        else if (node->data > find_data) {
            node = node->left;
        }
        else {
            node = node->right;
        }
    }
    return node;
}

int AvlTreeMetrics::CalculateDepth(AvlTree::Node* node) {
    int depth = 0;
    if (node == nullptr) {
        return 0;
    }
    while (node->parent != nullptr) {
        node = node->parent;
        ++depth;
    }

    return depth;
}

void AvlTreeMetrics::UpdateHeight(AvlTree::Node* node) {
    if (node) {
        node->height = 1 + std::max(node->left ? GetHeight(node->left) : -1, node->right ? GetHeight(node->right) : -1);
    }
    return;
}

void AvlTreeMetrics::UpdateSize(AvlTree::Node* node) {
    if (node) {
        node->size = 1 + AvlTreeMetrics::GetSize(node->left) + AvlTreeMetrics::GetSize(node->right);
    }
}

int AvlTreeMetrics::GetHeight(AvlTree::Node* node) {
    if (node == nullptr) {
        return -1;
    }
    return node->height;
}

int AvlTreeMetrics::GetSize(AvlTree::Node* node) {
    if (node == nullptr) {
        return 0;
    }
    return node->size;
}

void AvlTree::Size() const {
        if (root == nullptr) {
            cout << 0 << "\n";
            return;
        }
        cout << root->size << "\n";
    }

void AvlTree::Clear(AvlTree::Node* node) {
    if (node != nullptr) {
        Clear(node->left);
        Clear(node->right);
        delete node;
    }
}
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
AvlTree::Node* AvlTree::InsertNode(AvlTree::Node* node, int insert_data, int& depth_height_sum, int depth) {
    if (!node) {
        depth_height_sum = depth + 1;
        return new Node(insert_data);
    }
    if (insert_data < node->data) {
        node->left = InsertNode(node->left, insert_data, depth_height_sum, depth + 1);
        node->left->parent = node;
    }
    else if (insert_data > node->data) {
        node->right = InsertNode(node->right, insert_data, depth_height_sum, depth + 1);
        node->right->parent = node;
    }

    AvlTreeMetrics::UpdateHeight(node);
    AvlTreeMetrics::UpdateSize(node);

    int balance = AvlTreeRotate::CalculateBalanceFactor(node);
    int left_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->left); // 왼쪽 자식 노드의 균형 인수 계산
    int right_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->right); // 오른쪽 자식 노드의 균형 인수 계산

    if (balance > 1 && left_child_balance >= 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        return AvlTreeRotate::RightRotate(node);
    }

    if (balance < -1 && right_child_balance <= 0) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
        return AvlTreeRotate::LeftRotate(node);
    }

    if (balance > 1 && left_child_balance < 0) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
        AvlTreeRotate::LeftRotate(node->left);
        return AvlTreeRotate::RightRotate(node);
    }

    if (balance < -1 && right_child_balance > 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
        AvlTreeRotate::RightRotate(node->right);
        return AvlTreeRotate::LeftRotate(node);
    }

    return node;
}

void AvlTree::Insert(int insert_data) {
    int depth_height_sum = 0;
    Node* cNode = AvlTreeUtils::NodeFindByValue(root, insert_data);
    if (cNode != nullptr) {
        return;
    }
    root = InsertNode(root, insert_data, depth_height_sum, -1);
    Node* fNode = AvlTreeUtils::NodeFindByValue(root, insert_data);
    cout << fNode->height + AvlTreeMetrics::CalculateDepth(fNode) << "\n";

}

AvlTree::Node* AvlTree::EraseNode(Node* node, int erase_data) {
    if (!node) {
        return nullptr;
    }
    //cout << "moving, current loc: " << node->data << endl;
    if (erase_data < node->data) { // 왼쪽 서브트리에 있을 경우
        //cout << "moving to left" << endl;
        node->left = EraseNode(node->left, erase_data);
    }
    else if (erase_data > node->data) { // 오른쪽 서브트리에 있을 경우
        //cout << "moving to right" << endl;
        node->right = EraseNode(node->right, erase_data);
    }
    else { //삭제할 노드인 경우
        //cout << "find node to erase" << node->data << endl;
        if (!node->left || !node->right) { // 자식이 하나 이하인 경우
            if (node->left && !(node->right)) {
                node->data = node->left->data;
                delete node->left;
                node->left = nullptr;
            }
            else if (!(node->left) && node->right) {
                node->data = node->right->data;
                delete node->right;
                node->right = nullptr;
            }
            else {//무자식
                if (node->parent) {
                    if (node->parent->left == node) {
                        node->parent->left = nullptr;
                    }
                    else if(node->parent->right == node){
                        node->parent->right = nullptr;
                    }
                }
                delete node;
                node = nullptr;
            }     
        }
        else { //자식이 둘인 경우
            //후임자 노드 찾기
            Node* temp = AvlTreeUtils::FindSuccessor(node->right);

            node->data = temp->data;
            EraseNode(node->right, temp->data);
        }
    }

    if (node) {
        AvlTreeMetrics::UpdateHeight(node);
        AvlTreeMetrics::UpdateSize(node);
        int balance = AvlTreeRotate::CalculateBalanceFactor(node);
        int left_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->left); // 왼쪽 자식 노드의 균형 인수 계산
        int right_child_balance = AvlTreeRotate::CalculateBalanceFactor(node->right); // 오른쪽 자식 노드의 균형 인수 계산
        if (balance > 1 && left_child_balance >= 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
            return AvlTreeRotate::RightRotate(node);
        }
        if (balance < -1 && right_child_balance <= 0) { // 오른쪽으로 불균형이 생겼을 경우 왼쪽 회전
            return AvlTreeRotate::LeftRotate(node);
        }
        if (balance > 1 && left_child_balance < 0) { // 왼쪽-오른쪽 불균형일 경우 왼쪽 회전 후 오른쪽 회전
            AvlTreeRotate::LeftRotate(node->left);
            return AvlTreeRotate::RightRotate(node);
        }
        if (balance < -1 && right_child_balance > 0) { // 왼쪽으로 불균형이 생겼을 경우 오른쪽 회전
            AvlTreeRotate::RightRotate(node->right);
            return AvlTreeRotate::LeftRotate(node);
        }
    }
    return node;
}

void AvlTree::Erase(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    if (node == nullptr) {
        cout << 0 << "\n";
        return;
    }
    int depth_height_sum = node->height + AvlTreeMetrics::CalculateDepth(node);
    cout << depth_height_sum << "\n";
    root = EraseNode(root, x);
}

void AvlTree::Find(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    cout << ((node != nullptr) ? AvlTreeMetrics::CalculateDepth(node) + node->height : 0) << "\n";
}

void AvlTree::Ancestor(int x) {//존재하는 값
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    int depth = AvlTreeMetrics::CalculateDepth(node);
    int height = node->height;
    int parent_path_sum = AvlTreeUtils::GetPathToRootSum(node->parent);
    cout << depth + height << " " << parent_path_sum << "\n";
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
    cout << (min_node->data + max_node->data) / 2 << "\n";
}

void AvlTree::Height() const {
    if (root == nullptr) {
        cout << -1 << "\n";
    }
    else {
        cout << root->height << "\n";
    }
}

void AvlTree::Rank(int x) {
    Node* node = AvlTreeUtils::NodeFindByValue(root, x);
    if (node == nullptr) {//비어있을 경우 , 루트인 경우, 일반 경우
        cout << 0 << "\n";
        return;
    }

    int depth_plus_height_sum = AvlTreeMetrics::CalculateDepth(node) + node->height;
    cout << depth_plus_height_sum << " " << CalculateRank(root, x) << "\n";
}

int AvlTree::CalculateRank(Node* node, int x) {
    if (node == nullptr) {
        return 0;
    }

    if (x < node->data) {
        return CalculateRank(node->left, x);
    }
    else if (x > node->data) {
        return AvlTreeMetrics::GetSize(node->left) + 1 + CalculateRank(node->right, x);
    }
    else {
        return AvlTreeMetrics::GetSize(node->left) + 1;
    }
}

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