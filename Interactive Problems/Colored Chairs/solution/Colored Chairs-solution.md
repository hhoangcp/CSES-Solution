# Colored Chairs - Solution

**ID:** 3273 | **URL:** https://cses.fi/problemset/task/3273

## Approach

### Problem Restatement

There are $n$ chairs ($n$ is odd) arranged in a circle, each colored red (R) or blue (B). Find two adjacent chairs of the same color by querying individual chairs, using at most 20 queries.

### Core Idea

Since $n$ is odd, the colors cannot perfectly alternate around the circle — alternation requires an even number of chairs. Therefore, at least one pair of adjacent chairs must share the same color.

To find such a pair, query chairs 1 and $n$. If they have the same color, they are adjacent on the circle and we are done. Otherwise, chairs 1 and $n$ have different colors, and the same-color boundary must lie somewhere in the segment $1, 2, \ldots, n$.

**Binary search on the boundary:** Before any boundary, chairs alternate perfectly starting from chair 1. So the "expected" color at position $i$ is:
- Same as chair 1 if $(i-1)$ is even.
- Different from chair 1 if $(i-1)$ is odd.

After passing a same-color boundary, the parity flips. So if the color at position $mid$ does not match the expected color, we have crossed the boundary; otherwise, we have not. This gives a monotonic condition for binary search.

### Algorithm

1. Query chairs 1 and $n$. If same color, output $n$ and terminate.
2. Otherwise, binary search on $[l, r] = [2, n]$:
   - Let $mid = \lfloor(l + r) / 2\rfloor$. Query chair $mid$.
   - If the color at $mid$ matches the expected color (based on parity of $mid - 1$), the boundary is to the right: $l = mid + 1$.
   - Otherwise, the boundary is at or to the left of $mid$: $r = mid$.
3. When $l = r$, chairs $l-1$ and $l$ have the same color. Output $l - 1$.

**Invariant:** The same-color boundary lies in $[l-1, r-1]$. Initially $l = 2, r = n$, so the boundary is in $[1, n-1]$. Each step halves the interval. When $l = r$, the boundary is at position $l - 1$.

**Query count:** 2 initial queries + $\lceil\log_2(n-1)\rceil$ binary search queries. For $n \le 2 \times 10^5$: $2 + 18 = 20$.

### Example

$n = 5$, chairs $= [R, B, B, R, B]$ (chairs 2 and 3 are the same-color adjacent pair, matching the problem statement's example):

- Query chair 1: **R**. Query chair 5: **B**. Different colors → binary search.
- $l = 2, r = 5, mid = 3$. Query chair 3: **B**. Distance $= 2$ (even), expected $=$ same as R $= $ R. Actual B $\neq$ R → mismatch → $r = 3$.
- $l = 2, r = 3, mid = 2$. Query chair 2: **B**. Distance $= 1$ (odd), expected $=$ different from R $=$ B. Actual B $=$ B → match → $l = 3$.
- $l = r = 3$. Result: chairs $l - 1 = 2$ and $l = 3$ have the same color. Output **2**.

## Complexity

- **Time:** $O(\log n)$ queries
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Colored%20Chairs.cpp)
