# Polygon Lattice Points - Solution

**ID:** 2193 | **URL:** https://cses.fi/problemset/task/2193

## Approach

### Problem Restatement

Given a simple polygon with integer vertices, count the lattice points lying strictly inside ($I$) and on the boundary ($B$) of the polygon.

### Core idea

Use Pick's theorem, which relates area $A$, interior lattice points $I$, and boundary lattice points $B$:

$$A = I + \frac{B}{2} - 1 \quad\Longrightarrow\quad I = \frac{2A - B + 2}{2}$$

So we need two quantities: $2A$ (computed via the Shoelace formula) and $B$ (computed by summing lattice points on each edge).

**Boundary points $B$:** The number of lattice points on a segment from $(x_1, y_1)$ to $(x_2, y_2)$ with integer endpoints (including both) is $\gcd(|x_2 - x_1|, |y_2 - y_1|) + 1$. A point $(x, y)$ lies on the segment from $(0, 0)$ to $(a, b)$ iff $x = ta, y = tb$ for some $t \in (0, 1]$. For $x, y$ to be integers, $t$ must be a fraction $k/d$ where $d$ divides both $a$ and $b$, giving exactly $\gcd(|a|, |b|)$ valid values of $t$. To avoid double-counting shared vertices, count each edge's contribution as $\gcd(|\Delta x|, |\Delta y|)$ (total points minus one endpoint), then $B = \sum_{\text{edges}} \gcd(|\Delta x|, |\Delta y|)$.

**Twice area $S_2$:** Shoelace formula: $S_2 = \left|\sum_{i=1}^{n} (x_i - x_{i-1})(y_i + y_{i-1})\right|$ (with indices wrapping).

**Interior points $I$:** $I = (S_2 + 2 - B) / 2$.

### Algorithm

1. Initialize $S_2 = 0$, $B = 0$.
2. For each $i$ from 1 to $n$ (with $x_0 = x_n$, $y_0 = y_n$):
   - $S_2 \mathrel{+}= (x_i - x_{i-1})(y_i + y_{i-1})$.
   - $B \mathrel{+}= \gcd(|x_i - x_{i-1}|, |y_i - y_{i-1}|)$.
3. $S_2 = |S_2|$, $I = (S_2 + 2 - B) / 2$.
4. Output $I$ and $B$.

### Example

Polygon: $(1,1), (5,3), (3,5), (1,4)$.

| $i$ | $(x_i - x_{i-1})(y_i + y_{i-1})$ | $\gcd(|\Delta x|, |\Delta y|)$ |
|-----|-------------------------------------|----------------------------------|
| 1 | $(1-1)(1+4) = 0$ | $\gcd(0, 3) = 3$ |
| 2 | $(5-1)(3+1) = 16$ | $\gcd(4, 2) = 2$ |
| 3 | $(3-5)(5+3) = -16$ | $\gcd(2, 2) = 2$ |
| 4 | $(1-3)(4+5) = -18$ | $\gcd(2, 1) = 1$ |

$S_2 = |0 + 16 - 16 - 18| = 18$. $B = 3 + 2 + 2 + 1 = 8$. $I = (18 + 2 - 8) / 2 = 6$.

Result: `6 8`.

## Complexity

- **Time:** $O(n \log(\max |x_i|))$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Polygon%20Lattice%20Points.cpp)
