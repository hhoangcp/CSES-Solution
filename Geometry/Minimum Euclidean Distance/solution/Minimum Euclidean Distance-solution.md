# Minimum Euclidean Distance - Solution

**ID:** 2194 | **URL:** https://cses.fi/problemset/task/2194

## Approach

### Problem Restatement

Given $n$ points on the plane, find the minimum squared Euclidean distance between two distinct points.

### Core idea

Use divide and conquer. Sort all points by $x$-coordinate, then recursively split at the median. Each call returns the minimum squared distance $d$ in its range, and the points sorted by $y$.

**Divide and conquer:** Split into left and right halves. Recursively compute $d_L$ and $d_R$, then $d = \min(d_L, d_R)$. The closest pair either lies within one half (handled by recursion) or spans both halves (handled by the combine step).

**Combine step:** Any cross-half pair with squared distance $< d$ must have both points within the strip $|x - x_{\text{mid}}|^2 < d$. After recursion, the points are sorted by $y$ (via merge). For each point in the strip, compare with subsequent points by $y$, stopping when the $y$-difference squared exceeds $d$.

**Why only a constant number of comparisons per point:** Divide a $\sqrt{d} \times \sqrt{d}$ square into 6 cells of size $\frac{\sqrt{d}}{2} \times \frac{2\sqrt{d}}{3}$. Each cell's diagonal is $\sqrt{d/4 + 4d/9} < \sqrt{d}$, so each cell contains at most 1 point (two points in the same cell would have distance $< d$, contradicting that both halves already have minimum distance $\ge d$). Thus at most 6 points fit in a $\sqrt{d} \times \sqrt{d}$ square, meaning each point in the strip only needs to be compared with a constant number of nearby points by $y$. No pair is missed: the optimal cross-half pair must lie in the strip, and the $y$-scan checks all points within distance $\sqrt{d}$.

### Algorithm

1. Sort all points by $x$-coordinate.
2. Recursively solve(l, r):
   - Base case: if $r - l \le 3$, compute all pairwise distances directly and sort by $y$.
   - Split at mid. Recursively solve left and right halves, getting $d_L$, $d_R$, and each half sorted by $y$.
   - Merge the two sorted-by-$y$ halves.
   - $d = \min(d_L, d_R)$. Collect points with $|x - x_{\text{mid}}|^2 < d$ from the merged list.
   - For each point in the strip, compare with subsequent points by $y$ until $y$-difference squared $\ge d$, updating $d$.
   - Return $d$ and the merged-by-$y$ list.

### Example

4 points: $(2,1), (4,4), (1,2), (6,3)$.

Sorted by $x$: $(1,2), (2,1), (4,4), (6,3)$.

Split: left $[(1,2), (2,1)]$, right $[(4,4), (6,3)]$.

- Left: $d_L = (1-2)^2 + (2-1)^2 = 2$.
- Right: $d_R = (4-6)^2 + (4-3)^2 = 5$.
- $d = \min(2, 5) = 2$. Strip: points with $|x - 3|^2 < 2$, i.e., $(2,1)$ and $(4,4)$. Their distance: $(2-4)^2 + (1-4)^2 = 13 \ge 2$.

Result: 2.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Minimum%20Euclidean%20Distance.cpp)
