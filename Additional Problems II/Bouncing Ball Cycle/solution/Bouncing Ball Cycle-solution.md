# Bouncing Ball Cycle - Solution

**ID:** 3216 | **URL:** https://cses.fi/problemset/task/3216

## Problem Statement

A ball starts at the top-left corner of an $n \times m$ grid, initially moving diagonally away from the corner. At each step it moves one cell, bouncing off boundaries. After how many steps does it return to its initial position? How many distinct cells does it visit?

## Approach

### Independent coordinates

Row and column evolve independently. The row follows a sawtooth: $1, 2, \ldots, n, n-1, \ldots, 2, 1, \ldots$ with period $2N$ where $N = n - 1$. The column has period $2M$ where $M = m - 1$.

### Steps to return

The ball returns to $(1,1)$ when both coordinates simultaneously return to 1. This is $\text{lcm}(2N, 2M) = 2 \cdot \text{lcm}(N, M)$. Since $\text{lcm}(N, M) = NM / \gcd(N, M)$, with $g = \gcd(N, M)$, $N' = N/g$, $M' = M/g$:

$$\text{steps} = 2 \cdot N' \cdot M$$

### Distinct cells

In a full cycle, each cell is visited exactly $g$ times (at different time steps). After accounting for reflective symmetry (positions $r$ and $2N' - r$ map to the same physical row, similarly for columns), the number of distinct cells is:

$$\text{distinct} = \frac{N' \cdot M' \cdot (2g - 1) + N' + M' + 1}{2}$$

### Example

$n = 3, m = 4$: $N = 2, M = 3, g = 1, N' = 2, M' = 3$.

- Steps = $2 \cdot 2 \cdot 3 = 12$
- Distinct = $(2 \cdot 3 \cdot 1 + 2 + 3 + 1) / 2 = 6$

Result: `12 6`.

## Complexity

- **Time:** $O(\log(\min(n, m)))$ per test for GCD
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Bouncing%20Ball%20Cycle.cpp)
