# Course Schedule II - Solution

**ID:** 1757 | **URL:** https://cses.fi/problemset/task/1757

## Approach

### Problem Restatement

Given $n$ courses and $m$ prerequisite pairs $(a, b)$ meaning course $a$ must be completed before course $b$, find a valid topological order that is lexicographically smallest (course 1 as early as possible, then course 2, etc.).

### Core idea

A common mistake is using Kahn's algorithm with a min-heap to extract the smallest vertex first — this does not guarantee global optimality because picking a small vertex early can "trap" other smaller vertices later.

The correct strategy is to **build from the bottom up**: always pick the course with the largest index to place at the last position. Deferring the largest available node to the latest position frees smaller nodes to occupy earlier positions. After reversing, the resulting sequence is lexicographically smallest.

### Algorithm

1. Build the reverse graph: for each prerequisite $a \to b$, store edge $b \to a$ and increment out-degree of $a$.
2. Initialize a **max-heap** with all nodes of out-degree 0.
3. Repeatedly extract the maximum node $u$ from the heap, append it to the answer list, and decrement the out-degree of all its predecessors. If any predecessor's out-degree becomes 0, push it into the heap.
4. Reverse the answer list and output it.

### Example

$n=4$, $m=2$, prerequisites: $2 \to 1$, $2 \to 3$.

Out-degrees: out$[2]=2$, out$[1]=0$, out$[3]=0$, out$[4]=0$. Heap = $\{4, 3, 1\}$.

- Pop 4. Answer: [4].
- Pop 3. Answer: [4, 3]. out$[2]=1$.
- Pop 1. Answer: [4, 3, 1]. out$[2]=0$. Push 2.
- Pop 2. Answer: [4, 3, 1, 2].

Reversed: **2 1 3 4**.

## Complexity

- **Time:** $O((n + m) \log n)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Course%20Schedule%20II.cpp)
