# Projects - Solution

**ID:** 1140 | **URL:** https://cses.fi/problemset/task/1140

## Approach

### Problem Restatement

There are $n$ projects, each with start day $a_i$, end day $b_i$, and reward $p_i$. Selected projects must not overlap (share a day). Find the maximum total reward.

### Core Idea

This is the **Weighted Interval Scheduling** problem. Sort projects by end day $b_i$ increasing. Let $dp[i]$ be the maximum reward considering only the first $i$ sorted projects. For each project $i$:

- **Skip $i$:** $dp[i-1]$
- **Take $i$:** find the largest $p$ such that $b_p < a_i$ (last project ending before $i$ starts), then $dp[p] + p_i$

$$dp[i] = \max(dp[i-1], dp[p] + p_i)$$

Find $p$ by binary search on the sorted $b$ array. Base case: $dp[0] = 0$.

**Why sorting by end time works:** After sorting, if $b_i < a_j$, then every project $k < i$ also satisfies $b_k \le b_i < a_j$, so all projects before $i$ are compatible with $j$. This enables binary search — we only need to find the boundary.

**Correctness (optimal substructure):** If project $i$ is in the optimal solution, the remainder must be optimal for $\{1, \ldots, p\}$ — otherwise replacing it with the true optimum for $\{1, \ldots, p\}$ would yield a better solution, contradicting optimality. By induction on $i$, $dp[i]$ correctly equals the maximum reward for the first $i$ projects.

### Algorithm

1. Sort projects by $b_i$ increasing.
2. For $i = 1$ to $n$:
   - Binary search for the largest $p$ with $b_p < a_i$.
   - $dp[i] = \max(dp[i-1], dp[p] + p_i)$.
3. Output $dp[n]$.

### Example

Input: 4 projects — $(2,4,4)$, $(3,6,6)$, $(6,8,2)$, $(5,7,3)$.

After sorting by $b_i$: $(2,4,4)$, $(3,6,6)$, $(5,7,3)$, $(6,8,2)$.

| $i$ | $(a_i, b_i, p_i)$ | $p$ | $dp[i-1]$ | $dp[p]+p_i$ | $dp[i]$ |
|-----|---------------------|-----|-----------|-------------|---------|
| 1 | $(2, 4, 4)$ | 0 | 0 | 4 | 4 |
| 2 | $(3, 6, 6)$ | 0 | 4 | 6 | 6 |
| 3 | $(5, 7, 3)$ | 1 | 6 | $4+3=7$ | 7 |
| 4 | $(6, 8, 2)$ | 1 | 7 | $4+2=6$ | 7 |

Result: $dp[4] = 7$. Select projects $(2,4,4)$ and $(5,7,3)$.

## Complexity

- **Time:** $O(n \log n)$ — sorting + $n$ binary searches each $O(\log n)$
- **Space:** $O(n)$ — for $dp$ array and project list

## Code (C++)

[Solution Code](../code/Projects.cpp)
