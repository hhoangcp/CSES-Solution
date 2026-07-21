# Stick Divisions - Solution

**ID:** 1161 | **URL:** https://cses.fi/problemset/task/1161

## Problem Statement

You have a stick of length $x$ and want to divide it into $n$ sticks of given lengths, with total length equal to $x$. At each step, you can take any stick and divide it into two sticks. The cost of this operation equals the length of the original stick. What is the minimum total cost?

## Approach

### Step 1: Reverse the problem — From cutting to merging

Instead of cutting a large stick into small ones (forward), think backward: start from $n$ small sticks, each step merge two sticks into a larger one, with cost equal to the sum of their lengths. The process ends when only 1 stick of length $x$ remains. Each cut of stick $d$ into $a+b$ costs $d$, corresponding to merging $a$ and $b$ at cost $a+b=d$, so the total costs of both processes are equal.

### Step 2: Greedy algorithm

The reverse process is solved by a greedy strategy: always merge the two shortest sticks at each step.

**Algorithm:**
1. Push all $n$ lengths into a min-heap.
2. Repeat while the heap has more than 1 element:
   - Extract the two smallest elements $a$ and $b$.
   - Add $a + b$ to the answer.
   - Push $a + b$ back into the heap.
3. Output the answer.

**Optimality (Exchange argument):** The total cost can be written as $\sum d_i \times \text{depth}_i$, where $\text{depth}_i$ is the number of times stick $d_i$ participates in merges. Suppose an optimal solution has a small stick $d_{small}$ at a shallow depth and a large stick $d_{large}$ at a deeper depth. Swapping their positions: $d_{small}$ goes deeper by $\Delta d$, $d_{large}$ goes shallower by $\Delta d$. The total change is $\Delta = (d_{small} - d_{large}) \times \Delta d < 0$ since $d_{small} < d_{large}$. Thus the cost decreases after swapping, contradicting optimality. Cost is minimized only when the smallest sticks are always merged first (placed at the deepest levels).

**Theorem:** The greedy algorithm gives minimum cutting cost. Proof by induction: $n=1$ cost 0, correct. For $n>1$: the two shortest sticks must be merged first (by the exchange argument), reducing to an $n-1$ stick subproblem with the merged length $a+b$. By the inductive hypothesis, the algorithm is optimal on the subproblem.

### Example

$x = 8$, $n = 3$, lengths: $2, 3, 3$.

- Heap: $\{2, 3, 3\}$. Merge $2+3=5$, cost 5. Heap: $\{3, 5\}$.
- Merge $3+5=8$, cost 8. Heap: $\{8\}$.
- Total cost: $5 + 8 = 13$.

Alternative: cut 8 into (2,6) cost 8, cut 6 into (3,3) cost 6. Total: 14 > 13. Huffman is optimal.

## Complexity

- **Time:** $O(n \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Stick%20Divisions.cpp)
