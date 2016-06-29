## Technical Interview Questions
Here you will find various technical interview questions and their solutions.

* [Linked List Reversal](#linked-list-reversal) \[[Solution](solutions/linked-list-reversal.cpp)\]

* [Minimum Stack Element](#minimum-stack-element) \[[Solution](solutions/minimum-stack-element.cpp)\]

* [Balanced Binary Tree](#balanced-binary-tree) \[[Solution](solutions/balanced-binary-tree.cpp)\]

* [Balanced BST Generation](#balanced-bst-generation) \[[Solution](solutions/balanced-bst-generation.cpp)\]

* [Greatest Common Divisor](#greatest-common-divisor) \[[Solution](solutions/greatest-common-divisor.cpp)\]

---------------

#### Linked List Reversal

Write a function that reverses a singly linked list. For example, if your linked list initially looks like this:

    2 -> 15 -> 6 -> 1 -> [NULL]

Your function would modify the linked list such that it looks like this:

    1 -> 6 -> 15 -> 2 -> [NULL]

Assume that you are implementing a member function of a LinkedList class, where you have access to the private instance variable `head`. There is no instance variable that holds the size. Use the following function declaration:

    void reverse();

\[[Solution](solutions/linked-list-reversal.cpp)\]

---------------

#### Minimum Stack Element

Use the [STL stack](http://www.cplusplus.com/reference/stack/stack/) and its provided functionality to find the minimum element in a stack.

You may ONLY use stacks to complete this project (no other data structures, such as vectors or lists, are allowed). Moreover, the input stack MUST remain unchanged from its original state after the function returns; in other words, the stack has the same values in the same order after the function has completed.

\[[Solution](solutions/minimum-stack-element.cpp)\]

---------------

#### Balanced Binary Tree

Use the given Tree class and implement a function that returns whether the binary tree is balanced or not.

An empty tree is considered height-balanced.

A non-empty binary tree T is balanced if:
* Left subtree of T is balanced
* Right subtree of T is balanced
* The difference between heights of left subtree and right subtree is not more than 1.

\[[Solution](solutions/balanced-binary-tree.cpp)\]

---------------

#### Balanced BST Generation

Given a sorted vector, generate a balanced Binary Search Tree with minimal height.

\[[Solution](solutions/balanced-bst-generation.cpp)\]

---------------

#### Greatest Common Divisor

Write a function to compute the greatest common divisor (GCD) between two numbers. Recall that the GCD of two numbers, a and b, is defined as follows:

    gcd(a, b) = b               If a is divisible by b
    gcd(a, b) = gcd(b, a%b)     Otherwise

\[[Solution](solutions/greatest-common-divisor.cpp)\]
