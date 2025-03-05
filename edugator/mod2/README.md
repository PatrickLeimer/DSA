Search In List

Author: Brian Magnuson
Easy
Problem Statement
Write a function find(Node* node, int valueInput) that starts at the given node and returns the index of the node with the value valueInput. Indices start at 0.  Return -1 if valueinput does not exist.

We have defined the following C++ class for you:

class Node {
    public:
        int value;
        Node* next = NULL;
        ~Node() { if (next != nullptr) delete next; }
};
Sample Input
3 5
1 2 5
Sample Output
2
Explanation
We have implemented the main( ) for you. The main calls your find( ) method.

Input:

Line 1 contains 2 integers:

The first integer is the size of the linked list. This is for parsing the input in main only and will NOT be accessible to your function.

The second integer is the target value to find.

Line 2 is the linked list with elements separated by spaces.

Output: Index of the found value. -1 if the value was not present in the list.

In this case, 5 is in the list and is located at index 2.

Constraints
The list is not empty

The target value appears at most once in the linked list