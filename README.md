# Technical Interview Questions

### Data Structures & Algorithms

##### Linked Lists
* [Linked List Reversal](#linked-list-reversal)
\[[Solution](solutions/linked-list-reversal.cpp)\]

* [Linked List Common Ancestors](#linked-list-common-ancestors)
\[[Solution](solutions/linked-list-common-ancestors.cpp)\]

##### Stacks/Queues
* [Math Stack](#math-stack)
\[[Solution](solutions/math-stack.cpp)\]

##### Trees
* [Balanced Binary Tree](#balanced-binary-tree)
\[[Solution](solutions/balanced-binary-tree.cpp)\]

* [Balanced BST Generation](#balanced-bst-generation)
\[[Solution](solutions/balanced-bst-generation.cpp)\]

##### Miscellaneous
* [Fizz Buzz](#fizz-buzz)
\[[Solution](solutions/fizz-buzz.cpp)\]

* [Integer Set Duplicates](#integer-set-duplicates)
\[[Solution](solutions/integer-set-duplicates.cpp)\]

* [Greatest Common Divisor](#greatest-common-divisor)
\[[Solution](solutions/greatest-common-divisor.cpp)\]

### iOS

* [Intermodule Communication](#intermodule-communication) \[[Discussion](solutions/ios-intermodule-communication.txt)\]

* [Automatic Reference Counting](#automatic-reference-counting)
\[[Discussion](solutions/arc.txt)\]

### Design

* How would you unit test a sorted list?

### Personal

* Discuss a technical project that you did recently, some engineering problems you faced, and how you solved them.

* Discuss a tool/technology/framework that you used recently that increased all or part of your workflow.

---------------
### Data Structures & Algorithms
---------------


#### Linked Lists

###### Linked List Reversal

Implement a function that reverses a singly linked list. For example:

    // Before reversal
    2 -> 15 -> 6 -> 1 -> [NULL]

    // After reversal
    1 -> 6 -> 15 -> 2 -> [NULL]

Assume that you are implementing a member function of a LinkedList class, where you have access to the private instance variable `head`. There is no instance variable that holds the size. You must modify the data structure, not return a copy. Use the following function declaration:

    void reverse();

\[[Solution](solutions/linked-list-reversal.cpp)\]

###### Linked List Common Ancestors

![Linked List Common Ancestors Image](/assets/linked-list-common-ancestors.png)

\[[Solution](solutions/linked-list-common-ancestors.cpp)\]

#### Stacks/Queues

###### Math Stack

Implement a class called `MathStack` that allows for certain operations. Given a stack of integers Use the [STL stack](http://www.cplusplus.com/reference/stack/stack/) and its provided functionality to find the minimum element in a stack.

You may ONLY use stacks to complete this project (no other data structures, such as vectors or lists, are allowed). Moreover, the input stack MUST remain unchanged from its original state after the function returns; in other words, the stack has the same values in the same order after the function has completed.

\[[Solution](solutions/math-stack.cpp)\]

Use the [STL stack](http://www.cplusplus.com/reference/stack/stack/) and its provided functionality to find the minimum element in a stack.

You may ONLY use stacks to complete this project (no other data structures, such as vectors or lists, are allowed). Moreover, the input stack MUST remain unchanged from its original state after the function returns; in other words, the stack has the same values in the same order after the function has completed.

\[[Solution](solutions/minimum-stack-element.cpp)\]

#### Trees

###### Balanced Binary Tree

Implement a function that returns whether a given binary tree is balanced or not.

An empty tree is considered height-balanced. A non-empty binary tree T is balanced if and only if T's left and right subtrees are both balanced, and the heights of T's left and right subtrees do not differ by more than 1.

\[[Solution](solutions/balanced-binary-tree.cpp)\]

###### Balanced BST Generation

Given a sorted vector, generate a balanced Binary Search Tree with minimal height.

\[[Solution](solutions/balanced-bst-generation.cpp)\]

###### Fizz Buzz

Write a function that cycles through the integers between 1 and n, inclusive.
If the integer is divisible by 3, output "Fizz" on its own line.
If the integer is divisible by 5, output "Buzz" on its own line.
If the integer is divisible by both, output "FizzBuzz" on its own line.
If the integer is divisible by neither, output the integer itself on its own line.

For example, cycling between 1 and 16 would produce the following output (condensed to fit on one line):

    1, 2, Fizz, 4, Buzz, Fizz, 7, 8, Fizz, Buzz, 11, Fizz, 13, 14, FizzBuzz, 16

Use the following function declaration:

    void fizzBuzz(int n);

\[[Solution](solutions/fizz-buzz.cpp)\]

###### Integer Set Duplicates
Based on a set containing integers from 1 to n (e.g., {1, 2, 3, 4}), you can create an array of n+1 integers that are selected from that set (e.g., [2, 3, 3, 1, 1], [4, 1, 3, 2, 4], [2, 2, 2, 2, 2]). Implement a function that finds *a* duplicate in a given array with such specifications.

\[[Solution](solutions/integer-set-duplicates.cpp)\]

###### Greatest Common Divisor

Write a function to compute the greatest common divisor (GCD) between two numbers. Recall that the GCD of two numbers, a and b, is defined as follows:

    gcd(a, b) = b               If a is divisible by b
    gcd(a, b) = gcd(b, a%b)     Otherwise

\[[Solution](solutions/greatest-common-divisor.cpp)\]

---------------
### iOS
---------------

##### Intermodule Communication

Discuss some ways that modules can asynchronously communicate with one another.

Solution: There are at least three ways to communicate asycnchronously in iOS: (1) delegates, (2) blocks, and (3) notifications.

##### Automatic Reference Counting

Discuss how Automatic Reference Counting (ARC) works. When and why might you declare a property as "weak"?

Solution: The system keeps track of references to objects by incrementing/decrementing the refereance count as you create/destroy
object pointers. You would declare a property as "weak" if you wanted to signify that you don't technically own that property, but
want to be able to reference it with your pointer. Using "weak" prevents retain cycles/memory leaks, whereby two objects hold
references to one another and preclude ARC from destroying them. A common structure is when a parent references a child "strong"ly
(aka, it owns the child), and the child references the parent "weak"ly (aka, no ownership, but needs to access it).
