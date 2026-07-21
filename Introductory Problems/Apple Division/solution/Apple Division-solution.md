# Apple Division - Solution

**ID:** 1623 | **URL:** https://cses.fi/problemset/task/1623

## Approach

### Problem Restatement

Given $n$ apples with weights $p_1, p_2, \ldots, p_n$ ($1 \le n \le 20$, $1 \le p_i \le 10^9$), partition them into two groups minimizing $|S_1 - S_2|$, where $S_1, S_2$ are the total weights of each group. Equivalently, with $T = \sum_{i=1}^{n} p_i$, find a subset with sum $S$ minimizing $|T - 2S|$, i.e., as close to $T/2$ as possible.

### Core Idea

With $n \le 20$, there are at most $2^n \approx 10^6$ partitions — small enough to enumerate all. Each apple has two choices (group 0 or group 1), forming a binary decision tree of depth $n$. Recursion explores every leaf, so the optimal answer is guaranteed to be found. This exhaustive search is necessary because greedy approaches fail for this NP-hard partition problem.

**Why greedy fails:** Sorting descending and assigning each apple to the lighter group only optimizes locally. Counter-example: weights $[8, 7, 6, 5, 4]$:
- Greedy: $G_1 = \{8, 5, 4\} = 17$, $G_2 = \{7, 6\} = 13$, difference = 4.
- Optimal: $G_1 = \{8, 7\} = 15$, $G_2 = \{6, 5, 4\} = 15$, difference = 0.

Since greedy cannot guarantee optimality, complete enumeration is required. The recursion explores all $2^n$ binary assignments of apples to groups, ensuring no partition is missed.

**Recursion vs. Bitmask:** Both enumerate $2^n$ partitions. Recursion maintains running sums in $O(1)$ per step, totaling $O(2^n)$. Bitmask recomputes the sum for each mask in $O(n)$, totaling $O(n \cdot 2^n)$. Recursion is faster in practice and also allows early termination when the difference reaches 0.

### Algorithm

1. Initialize `sum[0] = sum[1] = 0`, `res = ∞`.
2. Recurse on apple $i$: try adding $p_i$ to `sum[0]`, recurse to $i+1$, then backtrack; try adding $p_i$ to `sum[1]`, recurse to $i+1$, then backtrack.
3. When $i > n$: update `res = min(res, |sum[0] - sum[1]|)`. If `res == 0`, terminate early.
4. Output `res`.

### Example

$n = 5$, weights $[3, 2, 7, 4, 1]$. Total $T = 17$, target $T/2 = 8.5$.

The recursion finds the subset $\{1, 7\}$ with sum $S = 8$: $|T - 2S| = |17 - 16| = 1$. Equivalently, group 1 = $\{2, 3, 4\}$ (sum 9), group 2 = $\{1, 7\}$ (sum 8), difference = 1.

## Complexity

- **Time:** $O(2^n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Apple%20Division.cpp)
