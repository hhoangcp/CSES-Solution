# Advertisement - Solution

**ID:** 1142 | **URL:** https://cses.fi/problemset/task/1142

## Problem Statement

A fence consists of $n$ boards, each of width $1$ and height $h_i$. Find the largest area of a rectangle that can be placed on the fence.

## Approach

### Step 1: Problem analysis

Each board has width 1, so a rectangle on the fence spans a contiguous segment of boards with height equal to the shortest board in the segment. Area = minimum height $\times$ segment width.

For each board $i$, the largest rectangle using the full height $h[i]$ must extend left and right as far as possible, as long as all boards in the range have height $\geq h[i]$.

### Step 2: Compute left and right boundaries using monotone stacks

Let $L[i]$ be the nearest index to the left of $i$ such that $h[L[i]] < h[i]$, and $R[i]$ be the nearest index to the right of $i$ such that $h[R[i]] < h[i]$. The largest rectangle using the full height $h[i]$ has area:

$\text{area}(i) = h[i] \times (R[i] - L[i] - 1)$

Compute $L[i]$ using an increasing monotone stack:
- Scan left to right, maintaining a stack of indices with increasing heights.
- When encountering $h[i]$: pop all elements with height $\geq h[i]$. After popping, the stack top (if any) is $L[i]$; if empty, $L[i] = 0$.
- Push $i$ onto the stack.

Compute $R[i]$ similarly by scanning right to left.

### Proof of Correctness

**Monotone stack correctness:** After popping all elements $\geq h[i]$, the stack top contains the nearest index to the left with height smaller than $h[i]$. Popped elements have height $\geq h[i]$, so they don't constrain the leftward expansion of $h[i]$'s rectangle.

**Area formula:** The rectangle using height $h[i]$ extends from $L[i]+1$ to $R[i]-1$, with width $R[i] - L[i] - 1$. All boards in $[L[i]+1, R[i]-1]$ have height $\geq h[i]$, and $h[L[i]] < h[i]$, $h[R[i]] < h[i]$, so no further extension is possible.

**Optimality:** Every valid rectangle has height equal to $h[i]$ for some $i$ in the segment. Iterating all $i$ and taking the maximum suffices.

### Example

$n = 8$, $h = [4, 1, 5, 3, 3, 2, 4, 1]$:

| $i$ | $h[i]$ | $L[i]$ | $R[i]$ | Width $(R-L-1)$ | Area |
|-----|--------|--------|--------|-----------------|------|
| 1 | 4 | 0 | 2 | 1 | 4 |
| 2 | 1 | 0 | 9 | 8 | 8 |
| 3 | 5 | 2 | 4 | 1 | 5 |
| 4 | 3 | 2 | 6 | 3 | 9 |
| 5 | 3 | 2 | 6 | 3 | 9 |
| 6 | 2 | 2 | 8 | 5 | 10 |
| 7 | 4 | 6 | 8 | 1 | 4 |
| 8 | 1 | 0 | 9 | 8 | 8 |

Result: $10$ (at $i=6$, the rectangle covers boards from position $3$ to $7$).

## Complexity

- **Time:** $O(n)$ (each element is pushed/popped exactly once)
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Advertisement.cpp)
