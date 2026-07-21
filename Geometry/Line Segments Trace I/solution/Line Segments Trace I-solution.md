# Line Segments Trace I - Solution

**ID:** 3427 | **URL:** https://cses.fi/problemset/task/3427

## Approach

### Problem Restatement

Given $n$ line segments from $(0, y_1)$ to $(m, y_2)$ with integer slopes, find the maximum value at each coordinate $x \in \{0, 1, \ldots, m\}$.

### Core idea

Each segment from $(0, y_1)$ to $(m, y_2)$ is a linear function $f(x) = ax + b$ where $a = (y_2 - y_1)/m$ and $b = y_1$. The problem becomes: given $n$ lines, find $\max_i f_i(x)$ at each $x \in \{0, \ldots, m\}$.

The **Li Chao tree** solves this efficiently. Built on domain $[0, m]$, each node covers interval $[l, r]$ and stores one dominant line. When inserting a new line $f$ into a node with existing line $g$:

1. Compare $f$ and $g$ at $x = \text{mid} = \lfloor(l+r)/2\rfloor$. If $f(\text{mid}) > g(\text{mid})$, swap them — $g$ becomes the worse line at mid but may still be better in one half.
2. Two lines intersect at most once, so the worse line at mid can only be better on one side. If $g$ has a smaller slope than $f$ (the new dominant), $g$ is only better for $x < x^*$ where $x^*$ is the intersection. Since $g(\text{mid}) < f(\text{mid})$, the intersection $x^*$ must be left of mid, so recurse into the left half. Symmetrically, if $g$ has a larger slope, recurse right.
3. This ensures the optimal line at any $x$ is stored at some node on the root-to-leaf path. To query, compute the value of the stored line at each node on this path and return the maximum.

### Algorithm

1. Build a Li Chao tree on domain $[0, m]$.
2. For each segment, compute $a = (y_2 - y_1)/m$ and $b = y_1$, then insert line $f(x) = ax + b$.
3. For each $x$ from 0 to $m$, query the maximum and output it.

### Example

$n = 4$, $m = 5$. Segments: $(0,1)\text{–}(5,6)$, $(0,7)\text{–}(5,2)$, $(0,5)\text{–}(5,5)$, $(0,10)\text{–}(5,0)$.

Lines: $f_1 = x + 1$, $f_2 = -x + 7$, $f_3 = 5$, $f_4 = -2x + 10$.

| $x$ | $f_1$ | $f_2$ | $f_3$ | $f_4$ | max |
|-----|-------|-------|-------|-------|-----|
| 0   | 1     | 7     | 5     | 10    | 10  |
| 1   | 2     | 6     | 5     | 8     | 8   |
| 2   | 3     | 5     | 5     | 6     | 6   |
| 3   | 4     | 4     | 5     | 4     | 5   |
| 4   | 5     | 3     | 5     | 2     | 5   |
| 5   | 6     | 2     | 5     | 0     | 6   |

Result: `10 8 6 5 5 6`.

## Complexity

- **Time:** $O(n \log m)$ for insertions, $O(m \log m)$ for queries
- **Space:** $O(m)$

## Code (C++)

[Solution Code](../code/Line%20Segments%20Trace%20I.cpp)
