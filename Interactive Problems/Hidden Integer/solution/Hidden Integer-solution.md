# Hidden Integer - Solution

**ID:** 3112 | **URL:** https://cses.fi/problemset/task/3112

## Approach

### Problem Restatement

There is a hidden integer $x$ in the range $[1, 10^9]$. Find $x$ by asking questions of the form "$y < x$?", using at most 30 queries.

### Core Idea

Each query partitions the search range into two halves: values $< mid$ and values $\ge mid$. This is exactly a binary search over a sorted interval. Since $\lceil \log_2(10^9) \rceil = 30$, binary search fits within the query limit.

**Invariant:** After each step, $x \in [l, r]$. Initially $l = 1, r = 10^9$. After querying $mid$:
- If `YES` ($mid < x$): since $x$ is an integer and $x > mid$, we have $x \ge mid + 1$, so $l = mid + 1$.
- If `NO` ($mid \ge x$): we have $x \le mid$, so $r = mid$.

When $l = r$, the range contains a single value, which must be $x$.

### Algorithm

1. Set $l = 1$, $r = 10^9$.
2. While $l < r$:
   - $mid = \lfloor(l + r) / 2\rfloor$. Ask "? $mid$".
   - If `YES`: $l = mid + 1$.
   - If `NO`: $r = mid$.
3. Output "! $l$".

### Example

For clarity, suppose the search range were $[1, 16]$ and $x = 7$ (matching the problem statement's example):

| Step | $l$ | $r$ | $mid$ | Query | Answer | New range |
|------|-----|-----|-------|-------|--------|-----------|
| 1 | 1 | 16 | 8 | ? 8 | NO | $[1, 8]$ |
| 2 | 1 | 8 | 4 | ? 4 | YES | $[5, 8]$ |
| 3 | 5 | 8 | 6 | ? 6 | YES | $[7, 8]$ |
| 4 | 7 | 8 | 7 | ? 7 | NO | $[7, 7]$ |

Result: $x = 7$.

## Complexity

- **Time:** $O(\log(10^9)) = 30$ queries
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Hidden%20Integer.cpp)
