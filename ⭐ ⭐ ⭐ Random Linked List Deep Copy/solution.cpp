// Solution 1
// Create intermediary nodes between each node such that the intermediary nodes
// build up to the new list. (Note that this modifies the original list)

RandomListNode* copyRandomListNode(RandomListNode* head){
  // 1st round, create new nodes in O(n)
  RandomListNode* current = head;
  while (current != NULL) {
    RandomListNode* newCurrent = new RandomListNode(current->value);
    RandomListNode* next = current->next;
    current->next = newCurrent;
    newCurrent->next = next;
    current = next;
  }

  // 2nd round, copy random pointer
  current = head;
  while (current != NULL && current->next != NULL) {
    current->next->random = current->random->next; // Think about it!
    current = current->next->next; // Iterate twice to get to next "old" node
  }

  // 3rd round, extract new list
  current = head;
  RandomListNode* newHead = NULL;
  while (current != NULL) {
    RandomListNode* newCurrent = current->next;
    current->next = newCurrent->next;
    newCurrent->next = current->next;
    if (newHead == NULL) {
      newHead = newCurrent;
    }
    if (current->next == NULL) {
      break;
    }
    current = current->next;
  }
  return newHead;
}

// TODO: Solution 2
// Use a hash table to map old nodes to new nodes. Iterate through the linked list,
// creating new nodes as you go, linked to the correct next node, and updating the
// hash table with the correct new node values. Then, perform a second iteration
// whereby you populate the random pointer based on the values in the hash table.
