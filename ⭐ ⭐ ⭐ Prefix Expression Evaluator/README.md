### Prefix Expression Evaluation

Given a string containing a prefix expression, compute the value of the expression. For example:

Prefix expression:
`/ - 15 * / 3 2 5 5`
(Result = 1.5)

Relevant infix expression:
`(15 - (3 / 2) * 5) / 5`

You could also make this an infix or postfix evaluation problem, but you can just change the order
of where an expression is evaluated via the stack.

\[[Solution](solution.cpp)\]
