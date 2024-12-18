# AVL Tree Range Query Project
This project implements an AVL Tree in C++ to perform range queries efficiently. 
The AVL tree is a self-balancing binary search tree (BST), where 
the difference between heights of left and right subtrees cannot be more than one for all nodes. 
The tree supports insertion, deletion, and querying of elements within a given range.

## Table of Contents
Project Summary
Features
Prerequisites
Installation
Usage
Code Structure
Example
Efficiency
Contributing
License
Project Summary
This project aims to implement range query functionality based on an AVL tree. The AVL tree is characterized by its self-balancing property, ensuring that insertion, deletion, and search operations have a time complexity of O(log(n)). The project provides the following key functionalities:

## Features

- **Find x**: Outputs the sum of the depth and height of node x (1 ≤ x ≤ 300,000). If node x does not exist, it outputs 0.
- **Insert x**: Inserts a new node x and outputs the sum of the depth and height of node x. The value x is guaranteed to be unique in the current set.
- **Empty**: Outputs 1 if the set is empty, otherwise outputs 0.
- **Size**: Outputs the number of elements stored in the set.
- **Height**: Outputs the height of the AVL tree. If the tree is empty, it outputs -1.
- **Ancestor x**: Outputs the sum of the depth and height of node x, along with the sum of the key values from x's parent to the root.
- If x is the root, it outputs 'K 0' (where K is the sum of depth and height).
- **Average x**: Outputs the arithmetic mean of the minimum (a) and maximum (b) key values in the subtree rooted at node x.
-
- **Rank x**: Outputs the sum of the depth and height of node x, along with its rank. If node x does not exist,
- it outputs 0. The rank is defined as the number of elements in the set that are less than x, plus one.
- **Erase x**: Outputs the sum of the depth and height of node x and deletes the node. If node x does not exist,
- it outputs 0. If x has two children, it uses the successor to perform the deletion.

## Prerequisites
To run this project

#### following:
- A C++ compiler (such as GCC or Clang)
- Familiarity with command line operations
- An Integrated Development Environment (IDE) like Visual Studio Code, 
- CLion, or any other suitable C++ development platform

## Installation

Clone the repository:

bash

```bash
git clone https://github.com/prxxchi/AVLTreeRangeQuery.git
Navigate to the project directory:
```

bash


cd avl-tree-range-query
Compile the code:

bash


g++ -o avl_tree main.cpp avl_tree.cpp
Run the executable:

bash


./avl_tree
Usage
The project demonstrates basic operations of the AVL Tree. After compiling and running, you will be prompted to insert, delete, or perform range queries.

Example Operations:
Insert Element: Adds a new node to the AVL tree.
Delete Element: Removes a node from the tree while keeping it balanced.
Range Query: Returns all elements between two values (inclusive).
Code Structure
avl_tree.h: Header file containing the definition of the AVL Tree class.
avl_tree.cpp: Implements the AVL Tree operations like insertion, deletion, and balancing.
main.cpp: The main file to run and test the AVL Tree with example inputs.
The key class and functions are:

Node: Represents a node in the AVL tree.
insert(): Inserts a node and rebalances the tree.
deleteNode(): Deletes a node and ensures balance.
rangeQuery(): Returns all values between a given range.
Example
Here’s an example of how the project works:

cpp


int main() {
    AVLTree tree;
    
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    
    tree.deleteNode(20);
    
    std::vector<int> result = tree.rangeQuery(5, 25);
    
    for (int val : result) {
        std::cout << val << " ";
    }
    
    return 0;
}
Expected Output:


10 30
Efficiency
Empty, Size, Height: O(1) time complexity.
Other operations: Each has a time complexity of O(log(n)).
Contributing
Contributions are welcome! If you’d like to improve this project, feel free to fork the repository and submit a pull request.

Fork the project.
Create your feature branch:
bash


git checkout -b feature/AmazingFeature
Commit your changes:
bash


git commit -m 'Add AmazingFeature'
Push to the branch:
bash


git push origin feature/AmazingFeature
Open a pull request.
