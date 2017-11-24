## Linked Lists

#### Linked List Reversal

Implement a function that reverses a singly linked list. For example:

    // Before reversal
    2 -> 15 -> 6 -> 1 -> [NULL]

    // After reversal
    1 -> 6 -> 15 -> 2 -> [NULL]

Assume that you are implementing a member function of a LinkedList class, where you have access to the private instance variable `head`. There is no instance variable that holds the size. You must modify the data structure, not return a copy. Use the following function declaration:

    void reverse();

\[[Solution](solutions/linked-list-reversal.cpp)\]

#### Linked List Ancestor

Given two linked lists, find the first node of intersection.

#### Linked List Common Ancestors

![Linked List Common Ancestors Image](/assets/linked-list-common-ancestors.png)

Note that linked lists will always share AT LEAST the tail node.

\[[Solution](solutions/linked-list-common-ancestors.cpp)\]

#### Skip Pointer Validation

Assume that you have a singly linked list that has nodes with an extra pointer called `skip`.
Implement a function that validates that a given list is valid--no loops and `skip` always points
forward in the linked list.

#### Random Node Deep Copy

Assume you have a linked list, whose internal node contains data, a pointer to
the next node, and a pointer to a random node somewhere in the linked list.
Implement an algorithm that performs a deep copy of this linked list.

Solution 1
Create intermediary nodes between each node such that the intermediary nodes
build up to the new list. (Note that this modifies the original list)

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

Solution 2
Use a hash table to map old nodes to new nodes. Iterate through the linked list,
creating new nodes as you go, linked to the correct next node, and updating the
hash table with the correct new node values. Then, perform a second iteration
whereby you populate the random pointer based on the values in the hash table.
