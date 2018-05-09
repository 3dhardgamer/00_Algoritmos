# Queue operations with 2 stacks

Write the QUEUE operations (enqueue, dequeue, peek) using 2 STACKS as auxiliary structures.

# Operations
## CREATE
**queue_create()**:

Creates 2 stacks (default and auxiliary)

## ENQUEUE
**queue_enqueue(queue\* qe, int value)**:

Push the value to default stack.

## DEQUEUE
**queue_dequeue(queue\* qe)**:

Until the last element is left in the default stack: pop from default and push to auxiliary.

Pop last element in default stack to user.

Until auxiliary stack is not empty: pop from auxiliary and push back to default stack.

## PEEK
**queue_peek(queue\* qe)**:

The same procedure as dequeue, but instead of removing the last element in default stack, it just shows the value and then enqueue everything back.

# Time Complexity
- enqueue: theta(1)
- dequeue: O(n)
- peek: O(n)

