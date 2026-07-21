# Josephus Problem II - Solution

**ID:** 2163 | **URL:** https://cses.fi/problemset/task/2163

## Approach

### Problem Restatement

There are $n$ children in a circle, numbered $1$ to $n$. Starting from child $1$, skip $k$ children and eliminate the next. Repeat until all are eliminated. Print the elimination order.

### Core Idea

Generalized Josephus problem with arbitrary step $k$. Arrays give $O(n^2)$. Instead, use an order-statistic tree supporting $O(\log n)$ index-based access and deletion. Maintain `cur`, the 0-indexed position of the next child to eliminate. Each step: find the element at `cur`, print it, erase it. After erasing at `cur`, elements to the right shift left by 1, so position `cur` is now the new starting point in the shrunk set — we then skip $k$ children forward: `cur = (cur % n + k) % n` (where $n$ is the new tree size). The modulo ensures `cur` stays valid even when $k$ is very large ($10^9$).

### Algorithm

1. Insert $1, 2, \dots, n$ into an order-statistic tree.
2. Set `cur = k % n`.
3. Repeat $n$ times:
   - Find element at index `cur`, print it, erase from tree.
   - If elements remain: `cur = (cur % n + k) % n` ($n$ is the new size).

### Example

$n = 7$, $k = 2$. Initial tree: $\{1,2,3,4,5,6,7\}$, `cur = 2%7 = 2`.

| Step | `cur` | Eliminated | Remaining | New `cur` |
|------|-------|------------|-----------|-----------|
| 1 | 2 | **3** | $\{1,2,4,5,6,7\}$ | $(2\%6+2)\%6=4$ |
| 2 | 4 | **6** | $\{1,2,4,5,7\}$ | $(4\%5+2)\%5=1$ |
| 3 | 1 | **2** | $\{1,4,5,7\}$ | $(1\%4+2)\%4=3$ |
| 4 | 3 | **7** | $\{1,4,5\}$ | $(3\%3+2)\%3=2$ |
| 5 | 2 | **5** | $\{1,4\}$ | $(2\%2+2)\%2=0$ |
| 6 | 0 | **1** | $\{4\}$ | $(0\%1+2)\%1=0$ |
| 7 | 0 | **4** | $\emptyset$ | — |

Result: **3 6 2 7 5 1 4**.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Josephus%20Problem%20II.cpp)
