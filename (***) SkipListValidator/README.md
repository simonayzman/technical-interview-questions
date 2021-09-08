### Skip Linked List Validation

Assume that you have a singly linked list that has nodes with an extra pointer called `skip`. Implement a function that validates that a given list is valid, given its head.

```
 _________      ____    
|         ↓    |    ↓
1 -> 2 -> 3 -> 4 -> 5 -> X
     ↓    ↓         ↓
     X    X         X
```

1. `next` and `skip` form no loops.
2. `skip` always points forward in the linked list
3. `skip` always points to a node that exists in the list.


\[[Solution](solution.cpp)\]
