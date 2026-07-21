# Intersection Points - Solution

**ID:** 1740 | **URL:** https://cses.fi/problemset/task/1740

## Approach

### Problem Restatement

Given $n$ horizontal and vertical line segments, count the number of intersection points. No two parallel segments intersect, and no endpoint is an intersection point.

### Core idea

Each intersection is between exactly one horizontal and one vertical segment. A vertical segment at $x$ spanning $[y_1, y_2]$ intersects a horizontal segment at $y$ spanning $[x_1, x_2]$ when $x_1 \le x \le x_2$ and $y_1 \le y \le y_2$. Since no endpoint is an intersection, this is equivalent to strict inequality, but the non-strict condition can be used without affecting the count.

Sweep along the $x$-axis, maintaining a BIT over $y$-coordinates that tracks active horizontal segments. A horizontal segment at $y$ spanning $[x_1, x_2]$ creates an open event at $x_1$ (add $+1$ at $y$) and a close event at $x_2 + 1$ (add $-1$ at $y$). The close event uses $x_2 + 1$ because the segment is still active at $x_2$. A vertical segment at $x$ spanning $[y_1, y_2]$ creates a query event at $x$: the number of intersections equals the count of active horizontal segments in $[y_1, y_2]$, computed as `Query(y₂) - Query(y₁ - 1)`.

At each $x$-coordinate, all horizontal update events are processed before vertical queries, so the BIT correctly reflects active segments. Each intersection is counted exactly once — when the vertical segment's query is processed. Coordinate compression maps $y$-values to indices in $[1, 2n]$ since there are at most $2n$ distinct values.

### Algorithm

1. For each segment:
   - Horizontal $[x_1, x_2]$ at $y$: add open event $(x_1, y, +1)$ and close event $(x_2 + 1, y, -1)$.
   - Vertical at $x$ spanning $[y_1, y_2]$: add query event $(x, y_1, y_2)$.
2. Coordinate-compress all $y$-values.
3. Sort events by $x$; at the same $x$, process updates before queries.
4. For each event:
   - Update event: `Update(rank(y), val)`.
   - Query event: `ans += Query(rank(y₂)) - Query(rank(y₁) - 1)`.
5. Output `ans`.

### Example

3 segments: horizontal $(2,3)\text{–}(7,3)$, vertical $(3,1)\text{–}(3,5)$, vertical $(6,2)\text{–}(6,6)$.

Events sorted by $x$: open at 2, query at 3, query at 6, close at 8.

- $x=2$: open horizontal at $y=3$. BIT: $y=3 \to 1$.
- $x=3$: query vertical $[1,5]$. BIT sum in $[1,5] = 1$. → 1 intersection.
- $x=6$: query vertical $[2,6]$. BIT sum in $[2,6] = 1$. → 1 intersection.
- $x=8$: close horizontal at $y=3$. BIT: $y=3 \to 0$.

Total: 2.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Intersection%20Points.cpp)
