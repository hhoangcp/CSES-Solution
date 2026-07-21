# Maximum Manhattan Distances - Solution

**ID:** 3410 | **URL:** https://cses.fi/problemset/task/3410

## Approach

### Problem Restatement

Starting with an empty set, $n$ points are added sequentially. After each addition, compute the maximum Manhattan distance between any two points.

### Core idea

The Manhattan distance between $(x_1, y_1)$ and $(x_2, y_2)$ can be rewritten by eliminating absolute values:

$$|x_1 - x_2| + |y_1 - y_2| = \max\left(|u_1 - u_2|,\ |v_1 - v_2|\right)$$

where $u = x + y$ and $v = x - y$. This identity holds because considering the four sign cases of $(x_1 - x_2)$ and $(y_1 - y_2)$: when both have the same sign, $|x_1 - x_2| + |y_1 - y_2| = |u_1 - u_2|$; when they have opposite signs, $|x_1 - x_2| + |y_1 - y_2| = |v_1 - v_2|$. The maximum of the two covers all cases.

This transformation reduces the 2D Manhattan distance to the maximum of two 1D absolute differences. The maximum over all pairs is then:

$$\max\left(\max(u) - \min(u),\ \max(v) - \min(v)\right)$$

since $|u_i - u_j|$ is maximized by the pair with extreme $u$-values (similarly for $v$). Maintain four values — $\max(u)$, $\min(u)$, $\max(v)$, $\min(v)$ — updating each in $O(1)$ when a new point arrives. The result after each addition is $\max(\max_u - \min_u,\ \max_v - \min_v)$.

### Algorithm

1. Initialize $\max_u = -\infty$, $\min_u = +\infty$, $\max_v = -\infty$, $\min_v = +\infty$.
2. For each point $(x, y)$:
   - Compute $u = x + y$ and $v = x - y$.
   - Update $\max_u = \max(\max_u, u)$, $\min_u = \min(\min_u, u)$, and similarly for $v$.
   - Output $\max(\max_u - \min_u,\ \max_v - \min_v)$.

### Example

5 points: $(1,1), (3,2), (2,4), (2,1), (4,5)$.

| Point | $u$ | $v$ | $[\min_u, \max_u]$ | $[\min_v, \max_v]$ | Result |
|-------|-----|-----|---------------------|---------------------|--------|
| $(1,1)$ | 2 | 0 | $[2, 2]$ | $[0, 0]$ | 0 |
| $(3,2)$ | 5 | 1 | $[2, 5]$ | $[0, 1]$ | $\max(3, 1) = 3$ |
| $(2,4)$ | 6 | $-2$ | $[2, 6]$ | $[-2, 1]$ | $\max(4, 3) = 4$ |
| $(2,1)$ | 3 | 1 | $[2, 6]$ | $[-2, 1]$ | $\max(4, 3) = 4$ |
| $(4,5)$ | 9 | $-1$ | $[2, 9]$ | $[-2, 1]$ | $\max(7, 3) = 7$ |

## Complexity

- **Time:** $O(n)$
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Maximum%20Manhattan%20Distances.cpp)
