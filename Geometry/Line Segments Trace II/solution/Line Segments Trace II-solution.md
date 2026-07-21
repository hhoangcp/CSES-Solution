# Line Segments Trace II - Solution

**ID:** 3428 | **URL:** https://cses.fi/problemset/task/3428

## Approach

### Problem Restatement

Given $n$ line segments with integer endpoints, each active on interval $[x_1, x_2]$, find the maximum value at each $x \in \{0, 1, \ldots, m\}$. If no segment covers $x$, the value is $-1$.

### Core idea

Each segment from $(x_1, y_1)$ to $(x_2, y_2)$ corresponds to $f(x) = ax + b$ where $a = (y_2 - y_1)/(x_2 - x_1)$ and $b = y_1 - a \cdot x_1$. Unlike Line Segments Trace I where every line spans $[0, m]$, here each line is active only on its own $[x_1, x_2]$. We need a data structure supporting range insert of a line and point query of the maximum.

Use a **segment tree on $[0, m]$ where each node stores one line** with the Li Chao insert logic. To insert line $f$ on $[l, r]$: decompose $[l, r]$ into $O(\log m)$ fully covered segment tree nodes (standard segment tree range update). At each such node, apply the Li Chao insert — compare the new line with the stored line at mid, keep the better one, and push the worse line down to one child based on slope comparison. This works because two lines intersect at most once, so the line that loses at mid can only win in one half.

To query at point $x$: traverse root to leaf, evaluate the stored line at each node on the path, and return the maximum. This is correct because every line active at $x$ was inserted at some fully covered node whose interval contains $x$; that node lies on the root-to-leaf path, and the Li Chao insert ensures the optimal line at each position is preserved through the tree. The default line has value $-1$, handling the case of no segment.

### Algorithm

1. Build a segment tree on $[0, m]$, each node initialized with line $y = -1$.
2. For each segment $(x_1, y_1) \to (x_2, y_2)$:
   - Compute $a = (y_2 - y_1) / (x_2 - x_1)$ and $b = y_1 - a \cdot x_1$.
   - Insert line $f(x) = ax + b$ on range $[x_1, x_2]$.
3. For each $x$ from 0 to $m$, query the maximum and output it.

### Example

$n = 4$, $m = 5$. Segments: $(1,1)\text{–}(3,3)$, $(1,2)\text{–}(4,2)$, $(2,4)\text{–}(5,7)$, $(2,8)\text{–}(5,2)$.

Lines: $f_1 = x$ on $[1,3]$, $f_2 = 2$ on $[1,4]$, $f_3 = x+2$ on $[2,5]$, $f_4 = -2x+12$ on $[2,5]$.

| $x$ | Active lines | Values | max |
|-----|--------------|--------|-----|
| 0   | (none)       | —      | $-1$ |
| 1   | $f_1, f_2$  | $1, 2$ | 2   |
| 2   | $f_1, f_2, f_3, f_4$ | $2, 2, 4, 8$ | 8   |
| 3   | $f_1, f_2, f_3, f_4$ | $3, 2, 5, 6$ | 6   |
| 4   | $f_2, f_3, f_4$ | $2, 6, 4$ | 6   |
| 5   | $f_3, f_4$  | $7, 2$ | 7   |

Result: `-1 2 8 6 6 7`.

## Complexity

- **Time:** $O(n \log^2 m)$ for insertions, $O(m \log m)$ for queries
- **Space:** $O(m)$

## Code (C++)

[Solution Code](../code/Line%20Segments%20Trace%20II.cpp)
