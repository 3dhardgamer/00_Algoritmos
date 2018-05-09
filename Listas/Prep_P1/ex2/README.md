# Stack operations with 2 queues

Write the STACK operations (push, pop, peek) using 2 QUEUES as auxiliary structures.

# Operations
## CREATE

**stack_create()**:
Creates 2 queues (default and auxiliary)

## PUSH

**stack_push(stack\* stk, int value)**:
Receives the stack and the value.
Performs a simple queue_enqueue.

## POP

**stack_pop(stack\* stk)**:
Dequeue from default queue and enqueue in the auxiliary one until one element is left in default queue.
Removes the only element left in default queue.
Dequeue from auxiliary queue and enqueue back into default queue.


# Time Complexity
- push: theta(1)
- pop: O(n)
- peek: O(n)



