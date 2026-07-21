# Bouncing Ball Steps - Solution

**ID:** 3215 | **URL:** https://cses.fi/problemset/task/3215

## Problem Statement

A ball starts at the top-left corner of an $n \times m$ grid, initially moving diagonally away from the corner. At each step it moves one cell, bouncing off boundaries. What is the ball's position after $k$ steps, and how many times has it changed direction?

## Approach

### Position after $k$ steps

Row and column evolve independently (the diagonal motion changes both by $\pm 1$ per step, and each direction component reverses independently when it hits its respective boundary).

For a dimension of length $L$ (row: $L = n$, column: $L = m$), the coordinate follows a sawtooth with period $2(L-1)$. Compute $r = k \bmod 2(L-1)$:

- If $r \leq L - 1$: position $= 1 + r$ (moving toward boundary).
- If $r > L - 1$: position $= 2L - 1 - r$ (bouncing back).

### Direction changes (bounces)

The ball bounces when it hits a row boundary (every $n-1$ steps) or a column boundary (every $m-1$ steps). Corner hits count as 1 bounce (not 2), so use inclusion-exclusion:

$$\text{bounces} = \left\lfloor \frac{k}{n-1} \right\rfloor + \left\lfloor \frac{k}{m-1} \right\rfloor - \left\lfloor \frac{k}{\text{lcm}(n-1, m-1)} \right\rfloor$$

### Example

$n = 3, m = 4, k = 3$:

- Row: $r = 3 \bmod 4 = 3$. $3 > 2$, position $= 2 \cdot 3 - 1 - 3 = 2$.
- Column: $r = 3 \bmod 6 = 3$. $3 \leq 3$, position $= 1 + 3 = 4$.
- Bounces: $\lfloor 3/2 \rfloor + \lfloor 3/3 \rfloor - \lfloor 3/6 \rfloor = 1 + 1 - 0 = 2$.

Result: `2 4 2`.

## Complexity

- **Time:** $O(\log(\min(n, m)))$ per query for GCD
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Bouncing%20Ball%20Steps.cpp)
