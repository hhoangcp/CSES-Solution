# Maximum Building II - Solution

**ID:** 1148 | **URL:** https://cses.fi/problemset/task/1148

## Problem Statement

Given an $n \times m$ grid with trees (`*`) and empty cells (`.`), for each house size $a \times b$, count the number of positions where a rectangular house can be placed without covering any tree.

## Approach

### Histogram + Monotone stack: Find maximum rectangles

For each row $i$, compute $h[j]$ = number of consecutive empty cells from row $i$ upward at column $j$ (if cell has a tree, $h[j] = 0$). Use a monotone stack to find left boundary `Left[j]` and right boundary `Right[j]` such that $h[k] \ge h[j]$ for all $k \in [\text{Left}[j], \text{Right}[j]]$. This is the largest rectangle with height **exactly** $h[j]$ passing through column $j$.

### 2D difference array: $O(1)$ update per rectangle

A maximum rectangle of height $H$ and width $W$ contributes $C(H,W,a,b) = (W - b + 1)(H - a + 1)$ positions for house $a \times b$ (if $a \le H, b \le W$). Decompose:

$$C = (H - a + 1)(W - b + 1) = (H - a + 1)(W + 1) - (H - a + 1) \cdot b$$

Use 3 difference arrays to handle each part, with $O(1)$ update per rectangle:

- **`ans[a][b]`**: 2D difference array for the base count. Update 4 corners of range $[1..H][1..W]$.
- **`add[a][b]`**: accumulates constant $(W+1)$ for $a \le H, b \le W$.
- **`sub[a][b]`**: accumulates linear coefficient $b$ for $a \le H, b \le W$.

Each valid placement of house $a \times b$ corresponds to an empty rectangle on the grid, which is guaranteed to be covered by at least one maximum rectangle during histogram traversal. The difference arrays ensure each position is counted exactly once.

## Algorithm

1. For each row $i = 1 \ldots n$, update histogram $h[j]$.
2. For each row, use a monotone stack to find `Left[j]`, `Right[j]`.
3. For each $j$, let $H = h[j]$, $W = \text{Right}[j] - \text{Left}[j] + 1$. Update `ans`, `add`, `sub` in $O(1)$.
4. After processing all rows, compute 2D prefix sums on all 3 arrays.
5. Result at $(a, b)$: `ans[a][b] + add[a][b] - sub[a][b]`.

## Example

The $4 \times 7$ grid from the problem: there are 5 positions for a $2 \times 4$ house.

## Complexity

- **Time:** $O(nm)$ — each row processed in $O(m)$, final prefix sums in $O(nm)$
- **Memory:** $O(nm)$

## Code (C++)

[Solution Code](../code/Maximum%20Building%20II.cpp)
