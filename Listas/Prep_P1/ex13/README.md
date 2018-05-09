# Router entries and exits

Program receives a sequence of N pairs ```(X, Y)```, ```X = {'E', 'S'}``` and ```Y``` is a integer.
If ```X = 'E'```, the entry must be stored, if ```X = 'S'```, the first entry must be removed and displayed.

Example:

```(E, 10)``` => store 10

```(E, 19)``` => store 19

```(S, 4)``` => remove 10

display

```10 4```

# Implementation

To solve the exercise I used a queue structure, because it is FIFO (first-in, first-out) structure.
As when ```X = 'S'``` the very first element (first in the queue) is supposed to be removed, this kind of structure can do this.
