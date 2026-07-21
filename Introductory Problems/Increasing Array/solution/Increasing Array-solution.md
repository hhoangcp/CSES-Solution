# Increasing Array - Solution

**ID:** 1094 | **URL:** https://cses.fi/problemset/task/1094

## Approach

### Problem Restatement

Given an array of $n$ integers ($1 \le n \le 2 \times 10^5$, $1 \le a_i \le 10^9$), find the minimum total number of increment-by-1 operations needed to make the array non-decreasing ($a_1 \le a_2 \le \cdots \le a_n$).

### Core Idea

Since we can only increase elements, if $a_i$ is smaller than the maximum of all preceding elements, it must be raised to at least that maximum. Process left to right, maintaining `pre` = running maximum of all processed elements (after adjustments):

- If $a_i < pre$: increase $a_i$ to `pre`, costing $pre - a_i$ operations.
- If $a_i \geq pre$: no operation needed; update `pre = a_i`.

**Optimality:** Any valid result array $b$ must satisfy $b_i \geq \max(a_1, \ldots, a_i)$ (since $b$ is non-decreasing and $b_j \geq a_j$). To minimize $\sum(b_i - a_i)$, set each $b_i$ to the smallest valid value: $b_i = \max(a_1, \ldots, a_i)$. This is exactly the running maximum strategy. Any larger choice for $b_i$ costs more at position $i$ and imposes a stricter constraint on later elements, so it cannot be optimal.

### Algorithm

1. Initialize `pre = 0`, `ans = 0`.
2. For each element $a_i$: if $a_i < pre$, add $pre - a_i$ to `ans`; otherwise set `pre = a_i`.
3. Output `ans`.

### Example

Array: `[3, 2, 5, 1, 7]`

| $i$ | $a_i$ | `pre` | Cost | New `pre` |
|-----|-------|--------|------|-----------|
| 1 | 3 | 0 | 0 | 3 |
| 2 | 2 | 3 | 1 | 3 |
| 3 | 5 | 3 | 0 | 5 |
| 4 | 1 | 5 | 4 | 5 |
| 5 | 7 | 5 | 0 | 7 |

Total: **5** operations. Result: `[3, 3, 5, 5, 7]`.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Increasing%20Array.cpp)
