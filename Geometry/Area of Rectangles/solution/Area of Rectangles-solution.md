# Area of Rectangles - Solution

**ID:** 1741 | **URL:** https://cses.fi/problemset/task/1741

## Approach

### Problem Restatement

Given $n$ axis-aligned rectangles, compute the total area of their union.

### Core idea

Use a vertical line sweep from left to right. For each rectangle $(x_1, y_1, x_2, y_2)$, create two events:
- Left edge at $x_1$ with type $+1$ (start covering interval $[y_1, y_2]$)
- Right edge at $x_2$ with type $-1$ (stop covering interval $[y_1, y_2]$)

Sort all events by $x$-coordinate. Between consecutive events at $x_i$ and $x_{i+1}$, the covered length on the $y$-axis is constant, so the area contribution is:

$$\Delta A = \text{covered\_len} \times (x_{i+1} - x_i)$$

To maintain $\text{covered\_len}$ efficiently, use a segment tree over compressed $y$-coordinates (at most $2n$ distinct values). Each node stores:
- `cnt`: number of active rectangles covering this segment
- `len`: total covered length (in original coordinates)

**Update logic:** When `cnt > 0`, the segment is fully covered so `len` equals the segment's actual length. When `cnt == 0` at a leaf, `len = 0`; at an internal node, `len` equals the sum of children's `len`. This is correct because `cnt > 0` means at least one rectangle fully covers the segment, and `cnt == 0` means coverage is determined entirely by the children. The root's `len` always equals the total covered length on the $y$-axis.

### Algorithm

1. Collect all $2n$ events: for rectangle $(x_1, y_1, x_2, y_2)$, add $(x_1, +1, y_1, y_2)$ and $(x_2, -1, y_1, y_2)$.
2. Collect all distinct $y$-coordinates, sort, and compress to indices. Build segment tree over the $2n-1$ elementary $y$-intervals.
3. Sort events by $x$.
4. For each event $(x, \mathit{type}, y_1, y_2)$:
   - If this is not the first event, add $\text{root.len} \times (x - x_{\text{prev}})$ to the answer.
   - Update the segment tree: add $\mathit{type}$ to the range corresponding to $[y_1, y_2)$.
   - Set $x_{\text{prev}} = x$.
5. Output the answer.

### Example

$n=3$, rectangles: $(1,3,4,5)$, $(3,1,7,4)$, $(5,3,8,6)$.

Events sorted by $x$: $(1,+1,[3,5))$, $(3,+1,[1,4))$, $(4,-1,[3,5))$, $(5,+1,[3,6))$, $(7,-1,[1,4))$, $(8,-1,[3,6))$.

- $x=1$: add $[3,5)$. Covered $= [3,5)$, len $= 2$.
- $x=3$: $\Delta A = 2 \times (3-1) = 4$. Add $[1,4)$. Covered $= [1,5)$, len $= 4$.
- $x=4$: $\Delta A = 4 \times (4-3) = 4$. Remove $[3,5)$. Covered $= [1,4)$, len $= 3$.
- $x=5$: $\Delta A = 3 \times (5-4) = 3$. Add $[3,6)$. Covered $= [1,6)$, len $= 5$.
- $x=7$: $\Delta A = 5 \times (7-5) = 10$. Remove $[1,4)$. Covered $= [3,6)$, len $= 3$.
- $x=8$: $\Delta A = 3 \times (8-7) = 3$. Remove $[3,6)$. Covered $= \emptyset$, len $= 0$.

Total: $4 + 4 + 3 + 10 + 3 = 24$.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Area%20of%20Rectangles.cpp)
