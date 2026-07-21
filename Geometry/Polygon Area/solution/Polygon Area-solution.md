# Polygon Area - Solution

**ID:** 2191 | **URL:** https://cses.fi/problemset/task/2191

## Approach

### Problem Restatement

Compute the area of a simple polygon given its vertices. Output $2a$ where $a$ is the area (guaranteed to be an integer).

### Core idea

Use the Shoelace formula. For a polygon with vertices $(x_1, y_1), \ldots, (x_n, y_n)$ in order:

$$2A = \left|\sum_{i=1}^{n} (x_i y_{i+1} - x_{i+1} y_i)\right|$$

where $x_{n+1} = x_1$ and $y_{n+1} = y_1$. Each term $x_i y_{i+1} - x_{i+1} y_i$ is twice the signed area of triangle $O p_i p_{i+1}$ (with $O$ at the origin). For a convex polygon with counter-clockwise vertices, the sum of these signed areas equals the polygon area — the triangles cover the polygon without overlap. For clockwise order, the sum is negative. For non-convex simple polygons, the formula still holds because "excess" areas from triangles extending outside the polygon are canceled by triangles with negative signed area. The absolute value gives the actual area.

An equivalent form that is easier to implement:

$$2A = \left|\sum_{i=1}^{n} (x_i - x_{i-1})(y_i + y_{i-1})\right|$$

where $x_0 = x_n$, $y_0 = y_n$. Expanding shows the $x_i y_i$ terms cancel telescopically, leaving $\sum(x_i y_{i-1} - x_{i-1} y_i)$ which equals the original form with shifted indices (modulo $n$).

### Algorithm

1. Read the $n$ vertices.
2. Initialize `sum = 0`.
3. For each $i$ from 1 to $n$: `sum += (x_i - x_{i-1}) * (y_i + y_{i-1})`, where indices wrap ($x_0 = x_n$, $y_0 = y_n$).
4. Output `|sum|`.

### Example

Polygon: $(1,1), (4,2), (3,5), (1,4)$.

| $i$ | $(x_i - x_{i-1})(y_i + y_{i-1})$ | Value |
|-----|-------------------------------------|-------|
| 1 | $(1-1)(1+4)$ | 0 |
| 2 | $(4-1)(2+1)$ | 9 |
| 3 | $(3-4)(5+2)$ | $-7$ |
| 4 | $(1-3)(4+5)$ | $-18$ |

$2A = |0 + 9 - 7 - 18| = |{-16}| = 16$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Polygon%20Area.cpp)
