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
