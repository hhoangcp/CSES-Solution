# Josephus Problem I - Solution

**ID:** 2162 | **URL:** https://cses.fi/problemset/task/2162

## Approach

### Problem Restatement

There are $n$ children in a circle, numbered $1$ to $n$. Starting from child $1$, every second child is eliminated (skip $1$, eliminate next, $k=2$). Print the elimination order.

### Core Idea

A classical Josephus problem with step $k=2$. Arrays/linked lists give $O(n^2)$ due to mid-deletion cost. Instead, use an order-statistic tree supporting $O(\log n)$ index-based access and deletion. Maintain `cur`, the 0-indexed position of the next child to eliminate. Each step: find the element at index `cur`, print it, erase it. After erasing at `cur`, elements to the right shift left by 1, so the next child in the circle is now at index `cur` in the new tree — we then skip $1$ position forward: `cur = (cur % n + 1) % n` (where $n$ is the new tree size).

### Algorithm

1. Insert $1, 2, \dots, n$ into an order-statistic tree.
2. Set `cur = 1 % n`.
3. Repeat $n$ times:
   - Find element at index `cur`, print it, erase from tree.
   - If elements remain: `cur = (cur % n + 1) % n` ($n$ is the new size).

### Example

$n = 7$. Initial tree: $\{1,2,3,4,5,6,7\}$, `cur = 1`.

| Step | `cur` | Eliminated | Remaining | New `cur` |
|------|-------|------------|-----------|-----------|
| 1 | 1 | **2** | $\{1,3,4,5,6,7\}$ | $(1\%6+1)\%6=2$ |
| 2 | 2 | **4** | $\{1,3,5,6,7\}$ | $(2\%5+1)\%5=3$ |
| 3 | 3 | **6** | $\{1,3,5,7\}$ | $(3\%4+1)\%4=0$ |
| 4 | 0 | **1** | $\{3,5,7\}$ | $(0\%3+1)\%3=1$ |
| 5 | 1 | **5** | $\{3,7\}$ | $(1\%2+1)\%2=0$ |
| 6 | 0 | **3** | $\{7\}$ | $(0\%1+1)\%1=0$ |
| 7 | 0 | **7** | $\emptyset$ | — |

Result: **2 4 6 1 5 3 7**.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Josephus%20Problem%20I.cpp)
