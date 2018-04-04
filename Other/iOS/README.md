### iOS

##### Intermodule Communication

Discuss some ways that modules can asynchronously communicate with one another.

Solution: There are at least three ways to communicate asycnchronously in iOS: (1) delegates, (2) blocks, and (3) notifications.

##### Automatic Reference Counting

Discuss how Automatic Reference Counting (ARC) works. When and why might you declare a property as "weak"?

Solution: The system keeps track of references to objects by incrementing/decrementing the reference count as you create/destroy object pointers. You would declare a property as "weak" if you wanted to signify that you don't technically own that property, but want to be able to reference it with your pointer. Using "weak" prevents retain cycles/memory leaks, whereby two objects hold references to one another and preclude ARC from destroying them. A common structure is when a parent references a child "strong"ly (aka, it owns the child), and the child references the parent "weak"ly (aka, no ownership, but needs to access it).
