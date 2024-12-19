# AVL Tree Project
This project implements an AVL tree in C++ to efficiently perform rotations during each insertion and deletion. An AVL tree is a self-balancing binary search tree (BST) where the height difference between the left and right subtrees of any node cannot exceed 1. Additionally, it supports both basic and advanced functionalities.

## Table of Contents
- [Features](#features)
- [Prerequisites](#prerequisites)
- [Installation](#installation)
- [Usage](#usage)
- [Code structure](#code-structure)
- [Example Operations](#example-Operations)
- [Example](#example)
- [Efficiency](#efficiency)


## Project Summary
This project provides basic and advanced functionalities based on an AVL tree. The AVL tree is an efficient tree structure that, due to its self-balancing property, has a time complexity of O(log(n)) for insertion, deletion, and search operations. 

This project offers the following key features:

## Features

### Basic Features:
- **Find x**: Outputs the sum of the depth and height of node x (1 ≤ x ≤ 300,000). If node x does not exist, it outputs 0.
- **Insert x**: Inserts a new node x and outputs the sum of the depth and height of node x. The value x is guaranteed to be unique in the current set.
- **Empty**: Outputs 1 if the set is empty, otherwise outputs 0.
- **Size**: Outputs the number of elements stored in the set.
- **Height**: Outputs the height of the AVL tree. If the tree is empty, it outputs -1.
- **Ancestor x**: Outputs the sum of the depth and height of node x, along with the sum of the key values from x's parent to the root.
- If x is the root, it outputs 'K 0' (where K is the sum of depth and height).
- **Average x**: Outputs the arithmetic mean of the minimum (a) and maximum (b) key values in the subtree rooted at node x.
### Advanced Features:
- **Rank x**: Outputs the sum of the depth and height of node x, along with its rank. If node x does not exist,
- it outputs 0. The rank is defined as the number of elements in the set that are less than x, plus one.
- **Erase x**: Outputs the sum of the depth and height of node x and deletes the node. If node x does not exist, it outputs 0. If x has two children, it uses the successor to perform the deletion.

## Prerequisites
To run this project

#### following:
- A C++ compiler (such as GCC or Clang)
- Familiarity with command line operations
- An Integrated Development Environment (IDE) like CLion, Eclipse, or any other suitable C++ development platform

## Installation

1. Clone the repository:
```bash
git clone https://github.com/simhyunmin/INHA_OSAP_002_T6.git
```

2. you will use 'cd' and go the project directory:
```bash
cd INHA_OSAP_002_T6
```

3. Compile the code:
```bash
g++ -o avl_tree OSAP_002_T6_source.cpp
```

4. Run the executable:
```bash
./avl_tree
```

## Usage
This project allows you to choose how many commands to execute for each test case, and It provides the basic functionalities of an AVL tree, as well as advanced features beyond the basics.

## Code Structure:

- **AvlTree Folder**: A folder containing the split files for implementing the AVL tree.
- **OSAP_002_T6 Folder**: A cpp file that combines the split files into a single cpp file.
- **OSAP_002_T6_source.cpp**: Implements AVL tree operations such as insertion, deletion, and balancing. You can run the AvlTree and input examples.

## Example Operations:

#### Example Tasks:
- Input the number of test cases and the number of commands to be entered.
- Element Insertion: Adds a new node to the AVL tree.
- Element Deletion: Removes a node from the tree while maintaining balance.

#### Key Classes and Functions:

- **Node**: Represents a node in the AVL tree.
- **insert()**: Inserts a node and maintains the balance of the tree.
- **Erase()**: Deletes a node and keeps the balance.

## Example
how the project works:

```shell
1 17
Height
Height
Height
Empty
Insert 157731
Ancestor 157731
Height
Height
Size
Find 218367
Average 157731
Average 157731
Find 254641
Empty
Average 157731
Ancestor 157731
Empty
```

**Expected Output:**

```shell
-1
-1
-1
1
1
1 0
1
1
1
0
157731
157731
0
0
157731
1 0
0
```
## Efficiency
Empty, Size, Height operations are performed in O(1) time.
The remaining operations are performed in O(log(n)) time.
