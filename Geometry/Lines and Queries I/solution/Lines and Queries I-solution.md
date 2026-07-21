# Lines and Queries I - Solution

**ID:** 3429 | **URL:** https://cses.fi/problemset/task/3429

## Approach

### Problem Restatement

Process online queries: (1) add a line $y = ax + b$, (2) find the maximum value among all added lines at position $x$.

### Core idea

Use a Li Chao tree on domain $x \in [0, 10^5]$. Each node covers interval $[l, r]$ and stores one dominant line. When inserting a new line $f$ at a node with existing line $g$:

1. Compare $f(\text{mid})$ and $g(\text{mid})$ where $\text{mid} = \lfloor(l+r)/2\rfloor$. If $f$ is better, swap so the better line stays at this node.
2. The worse line at mid can only be better in one half — since two lines intersect at most once, the worse line at mid is either always worse, or better in exactly one half. If the worse line has a smaller slope, recurse into the left half $[l, \text{mid}]$; if larger, recurse into $[\text{mid}+1, r]$. If slopes are equal (parallel), stop.
3. To query at $x$, traverse root to leaf and evaluate the stored line at each node on the path. The optimal line at $x$ must be stored at some node on this path — it was either kept at a node or pushed to the correct branch, which lies on the path.

Each operation recurses through at most $O(\log m)$ depth since the interval halves at each step. Nodes are initialized with a line having $b = \text{LLONG\_MIN}$ so they never contribute to max queries before a real line is inserted.

### Algorithm

1. Build a Li Chao tree on $[0, 10^5]$, each node storing a line with $b = \text{LLONG\_MIN}$.
2. For each query:
   - Type 1 ($a, b$): insert line $f(x) = ax + b$.
   - Type 2 ($x$): query maximum at $x$, output the result.

### Example

6 queries from the problem:

| # | Query | Action | Result |
|---|-------|--------|--------|
| 1 | `1 1 2` | Insert $y = x + 2$ | — |
| 2 | `2 1` | $\max(x+2)$ at $x=1$ | 3 |
| 3 | `2 3` | $\max(x+2)$ at $x=3$ | 5 |
| 4 | `1 0 4` | Insert $y = 4$ | — |
| 5 | `2 1` | $\max(3, 4)$ at $x=1$ | 4 |
| 6 | `2 3` | $\max(5, 4)$ at $x=3$ | 5 |

Output: `3 5 4 5`.

## Complexity

- **Time:** $O(\log m)$ per operation
- **Space:** $O(m)$

## Code (C++)

[Solution Code](../code/Lines%20and%20Queries%20I.cpp)
