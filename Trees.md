## Trees

#### Balanced Binary Tree

Implement a function that returns whether a given binary tree is balanced or not.

An empty tree is considered height-balanced. A non-empty binary tree T is balanced if and only if
T's left and right subtrees are both balanced, and the heights of T's left and right subtrees do
not differ by more than 1.

\[[Solution](solutions/balanced-binary-tree.cpp)\]

#### BST String Printing

Given a binary tree of characters, print out all the possible strings going from the root to
a leaf node.

void leafPrint(Node* node) {
  leafPrintHelper(node, "");
}

void leafPrintHelper(Node* node, const string& current) {
  string appendedString = current + node->data;
  if (node->isLeaf()) {
    cout << appendedString << endl;
  } else if (node->hasBothChildren()) {
    leafPrintHelper(node->left, appendedString);
    leafPrintHelper(node->right, appendedString);
  } else if (node->hasLeftChild()) {
    leafPrintHelper(node->left, appendedString);
  } else if (node->hasRightChild()) {
    leafPrintHelper(node->right, appendedString);
  }
}

#### Deep Tree Copy

Given the root of a binary tree, implement a function that performs a deep copy of the binary tree
and returns the root of the newly duplicated tree.

Node* duplicateTree(Node* root) {
  if (root == NULL) {
    return NULL;
  }
  Node* node = new Node(root->value);
  node->left = duplicateTree(root->left);
  node->right = duplicateTree(root->right);
  return node;
}

#### Balanced BST Generation

Given an array of unique words, write a member function of the BST class that
creates a balanced binary search tree with minimal height.

Note, if the candidate realizes that a sorted vector is good, then you may let
them assume that the provided vector is sorted.

\[[Solution](solutions/balanced-bst-generation.cpp)\]
