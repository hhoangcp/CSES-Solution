# Point in Polygon - Solution

**ID:** 2192 | **URL:** https://cses.fi/problemset/task/2192

## Approach

### Problem Restatement

Given a simple polygon and a list of points, determine for each point whether it lies inside, outside, or on the boundary of the polygon.

### Core idea

Use the ray casting algorithm. Cast a horizontal ray from query point $A$ in the positive $x$-direction and count how many polygon edges it crosses. By the Jordan curve theorem, a simple closed curve divides the plane into inside and outside regions — each time the ray crosses an edge, it switches between regions. An odd count means INSIDE; even means OUTSIDE.

For each edge $(P_i, P_{i+1})$, first check if $A$ lies on it using `onSeg`: the cross product of $A$ with the edge endpoints is 0 (collinear) and the dot product $\le 0$ ($A$ is between the endpoints). If so, return BOUNDARY immediately.

For ray crossing, normalize so that the lower endpoint is $x$ and the upper is $y$ (swap if $x.y > y.y$). The ray crosses the edge when: (1) $x.y \le A.y < y.y$ — the half-open upper bound avoids double-counting at shared vertices of consecutive edges (if both edges pass through $y = A.y$ in the same direction, only one is counted); and (2) $\text{cross}(A, x, y) > 0$ — $A$ lies to the left of the directed edge, meaning the rightward ray must cross it. Each crossing flips the result via $ans \gets ans \oplus 1$.

### Algorithm

1. Read the polygon vertices.
2. For each query point $A$:
   - Initialize `ans = 0`.
   - For each edge $(P_i, P_{i+1})$:
     - If `onSeg(A, Line(P_i, P_{i+1}))`: output BOUNDARY and skip to next query.
     - Normalize so lower endpoint is $x$, upper is $y$.
     - If $x.y \le A.y < y.y$ and $\text{cross}(A, x, y) > 0$: $ans \gets ans \oplus 1$.
   - Output INSIDE if `ans` is odd, OUTSIDE if even.

### Example

Polygon: $(1,1), (4,2), (3,5), (1,4)$. Query points: $(2,3), (3,1), (1,3)$.

**Point $(2,3)$:**
- Edge $(1,1)\text{–}(4,2)$: not on seg. $1 \le 3 < 2$? No.
- Edge $(4,2)\text{–}(3,5)$: not on seg. $2 \le 3 < 5$? Yes. $\text{cross}((2,3),(4,2),(3,5)) = 5 > 0$. Crossing. `ans = 1`.
- Edge $(3,5)\text{–}(1,4)$: $4 \le 3$? No.
- Edge $(1,4)\text{–}(1,1)$: not on seg. $1 \le 3 < 4$? Yes. $\text{cross}((2,3),(1,1),(1,4)) = -3 < 0$. No crossing.

Odd → INSIDE.

**Point $(3,1)$:**
- Edge $(1,1)\text{–}(4,2)$: $1 \le 1 < 2$? Yes. $\text{cross}((3,1),(1,1),(4,2)) = -2 < 0$. No crossing.
- Edge $(4,2)\text{–}(3,5)$: $2 \le 1$? No.
- Edge $(3,5)\text{–}(1,4)$: $4 \le 1$? No.
- Edge $(1,4)\text{–}(1,1)$: $1 \le 1 < 4$? Yes. $\text{cross}((3,1),(1,1),(1,4)) = -6 < 0$. No crossing.

Even → OUTSIDE.

**Point $(1,3)$:**
- Edge $(1,4)\text{–}(1,1)$: $\text{cross}((1,3),(1,4),(1,1)) = 0$, $\text{dot}((1,3),(1,4),(1,1)) = -2 \le 0$. On segment.

→ BOUNDARY.

## Complexity

- **Time:** $O(n)$ per query point
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Point%20in%20Polygon.cpp)
