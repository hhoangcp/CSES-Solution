# Point Location Test - Solution

**ID:** 2189 | **URL:** https://cses.fi/problemset/task/2189

## Approach

### Problem Restatement

Given a directed line from $p_1$ to $p_2$ and a point $p_3$, determine whether $p_3$ lies to the left, to the right, or on the line when looking from $p_1$ to $p_2$.

### Core idea

Compute the cross product of vectors $\vec{p_1p_2}$ and $\vec{p_1p_3}$:

$$\text{cross}(p_1, p_2, p_3) = (x_2 - x_1)(y_3 - y_1) - (y_2 - y_1)(x_3 - x_1)$$

This equals the signed area of triangle $p_1p_2p_3$ (doubled) and carries orientation information:

- **cross > 0**: $p_3$ is to the **left** (counter-clockwise turn from $p_1$ to $p_2$ to $p_3$).
- **cross < 0**: $p_3$ is to the **right** (clockwise turn).
- **cross = 0**: $p_3$ lies on the line (collinear — the slopes from $p_1$ to $p_2$ and from $p_1$ to $p_3$ are equal, or equivalently the three points have zero area).

The cross product is invariant under translation and rotation, and changes sign under reflection, so the result is consistent regardless of point arrangement.

### Algorithm

1. For each test, read $p_1, p_2, p_3$.
2. Compute $\text{cross}(p_1, p_2, p_3)$.
3. If cross > 0: output LEFT. If cross < 0: output RIGHT. If cross = 0: output TOUCH.

### Example

3 tests from the problem, all sharing $p_1=(1,1), p_2=(5,3)$:

| Test | $p_3$ | cross | Result |
|------|-------|-------|--------|
| 1 | $(2,3)$ | $4 \cdot 2 - 2 \cdot 1 = 6$ | LEFT |
| 2 | $(4,1)$ | $4 \cdot 0 - 2 \cdot 3 = -6$ | RIGHT |
| 3 | $(3,2)$ | $4 \cdot 1 - 2 \cdot 2 = 0$ | TOUCH |

## Complexity

- **Time:** $O(1)$ per test
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Point%20Location%20Test.cpp)
