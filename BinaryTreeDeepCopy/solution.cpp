Node* duplicateTree(Node* root) {
  if (root == NULL) {
    return NULL;
  }
  Node* node = new Node(root->value);
  node->left = duplicateTree(root->left);
  node->right = duplicateTree(root->right);
  return node;
}
