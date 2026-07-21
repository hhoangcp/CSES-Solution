# Lines and Queries II - Solution

**ID:** 3430 | **URL:** https://cses.fi/problemset/task/3430

## Approach

### Problem Restatement

Process online queries: (1) add a line $y = ax + b$ active on interval $[l, r]$, (2) find the maximum value among all active lines at position $x$. If no line is active, print `NO`.

### Core idea

This problem extends Lines and Queries I: each line is now only active on a specific interval $[l, r]$, not the entire domain. A simple Li Chao tree cannot handle this — it assumes every inserted line is valid everywhere, so it would return values of lines that are inactive at the query point.

**Solution: Segment tree + Li Chao insert logic.** Build a segment tree on $x \in [0, m]$. Each segment tree node stores one line, using the Li Chao insert mechanism.

**Inserting line $f$ on $[l, r]$:** Perform a standard segment tree range update. The range $[l, r]$ decomposes into $O(\log m)$ fully covered nodes. At each such node, apply the Li Chao insert: compare $f$ with the stored line $g$ at mid. If $f$ is better at mid, swap so the better line stays. The worse line can only dominate in one half (two lines intersect at most once), so push it down to the appropriate child based on slope comparison. This recursion reuses the segment tree's own children — the pushed line remains valid at descendants because the current node's range is entirely within $[l, r]$.

**Querying at $x$:** Traverse root to leaf at position $x$. At each node on the path, evaluate the stored line at $x$ and take the maximum. This works because any line active at $x$ was inserted at some fully covered segment tree node whose interval contains $x$; that node lies on the root-to-leaf path, and the Li Chao insert ensures the optimal line at each position within the node's range is either stored there or pushed to a descendant on the path. If the result is `LLONG_MIN`, no line covers $x$, so output `NO`.

**Key difference from Lines and Queries I:** In problem I, a single Li Chao tree suffices because all lines span the entire domain. Here, the segment tree restricts each line to its active interval — a line inserted on $[l, r]$ is only stored at nodes whose ranges lie within $[l, r]$, so it is never evaluated at points outside $[l, r]$.

### Algorithm

1. Build a segment tree on $[0, m]$ ($m = 10^5$), each node initialized with line $b = \text{LLONG\_MIN}$.
2. For each query:
   - Type 1 ($a, b, l, r$): call `update(root, 0, m, l, r, line(a, b))`.
   - Type 2 ($x$): call `query(root, 0, m, x)`. If result is `LLONG_MIN`, print `NO`; otherwise print the result.
3. `update(i, l, r, u, v, f)`: if $[l, r] \subseteq [u, v]$, call `insertLine(i, l, r, f)`; otherwise recurse to children.
4. `insertLine(i, l, r, f)`: compare $f$ with `liChao[i]` at mid, swap if needed, recurse the worse line to one child by slope.
5. `query(i, l, r, x)`: evaluate `liChao[i]` at $x$, recurse to the child containing $x$, return the maximum.

### Example

6 queries from the problem:

| # | Query | Action | Result |
|---|-------|--------|--------|
| 1 | `1 1 2 1 3` | Insert $y = x + 2$ on $[1, 3]$ | — |
| 2 | `2 3` | $f(3) = 5$ | 5 |
| 3 | `2 4` | No line active at $x = 4$ | NO |
| 4 | `1 0 4 1 5` | Insert $y = 4$ on $[1, 5]$ | — |
| 5 | `2 3` | $\max(5, 4) = 5$ | 5 |
| 6 | `2 4` | $f(4) = 4$ | 4 |

Output: `5 NO 5 4`.

## Complexity

- **Time:** $O(\log^2 m)$ per insert, $O(\log m)$ per query
- **Space:** $O(m)$

## Code (C++)

[Solution Code](../code/Lines%20and%20Queries%20II.cpp)
