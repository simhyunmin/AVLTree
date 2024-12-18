/*
MIT License

Copyright (c) 2024 INHA_OSAP_002_T6

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

Author: INHA_OSAP_002_T6
Date: 2024-11-20
*/

#include "OSAP_002_T6_source.h"

/**
 * @brief Main function handling test cases and queries
 */
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int num_test_cases;
  cin >> num_test_cases;
  while (num_test_cases--) {
    int num_queries;
    cin >> num_queries;
    AvlTree avl_tree;
    for (int i = 0; i < num_queries; ++i) {
      string command;
      cin >> command;

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
        avl_tree.Find(x);
      } else if (command == "Ancestor") {
        int x;
        cin >> x;
        avl_tree.Ancestor(x);
      } else if (command == "Average") {
        int x;
        cin >> x;
        avl_tree.Average(x);
      } else if (command == "Rank") {
        int x;
        cin >> x;
        avl_tree.Rank(x);
      } else if (command == "Erase") {
        int x;
        cin >> x;
        avl_tree.Erase(x);
      } else if (command == "PrintTree") {
        avl_tree.PrintTree();
      }
      cin.clear();
    }
  }

  return 0;
}
