#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "OSAP_002_T6_source.h"
using namespace std;


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
