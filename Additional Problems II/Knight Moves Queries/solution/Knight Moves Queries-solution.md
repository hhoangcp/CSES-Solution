# Knight Moves Queries - Solution

**ID:** 3218 | **URL:** https://cses.fi/problemset/task/3218

## Problem Statement

A knight starts at $(x, y)$ on an infinite chessboard. Find the minimum number of moves to reach the top-left corner $(1, 1)$.

## Approach

### Physical lower bounds: 3 constraints

Convert to relative coordinates: $x' = x - 1$, $y' = y - 1$, target $(0, 0)$. Each knight move changes $x'$ by at most 2, $y'$ by at most 2, and $x' + y'$ by at most 3. Steps $d$ must satisfy:

1. $d \ge \lceil x'/2 \rceil$ — enough steps to reduce $x'$ to 0.
2. $d \ge \lceil y'/2 \rceil$ — enough steps to reduce $y'$ to 0.
3. $d \ge \lceil (x'+y')/3 \rceil$ — enough steps to reduce the total to 0.

Combined lower bound: $d_0 = \max$ of the three values above.

### Parity constraint: $d$ must have the same parity as $x' + y'$

Each knight move changes $x' + y'$ by exactly $\pm 1$ or $\pm 3$ (all odd). After $d$ steps, the total change has the same parity as $d$. The target $(0, 0)$ has sum 0, so **$d$ and $x' + y'$ must share parity**. If $d_0 + x' + y'$ is odd, increment $d_0$ by 1.

For sufficiently large $x', y'$ (outside the 4 special cases), the lower bound is always achievable after parity adjustment — there's enough "room" to distribute steps between reducing $x'$ and $y'$, and surplus steps (if any) can be wasted (move backwards then forwards).

### 4 special cases: Insufficient maneuvering space

At positions very close to $(0, 0)$, the geometry of knight moves prevents reducing both $x'$ and $y'$ fast enough. Add 2 extra steps:

- $(0, 1)$ and $(1, 0)$: $d_0 = 1$, actual minimum is 3 steps.
- $(1, 1)$: $d_0 = 1$, actual minimum is 4 steps.
- $(2, 2)$: $d_0 = 2$, actual minimum is 4 steps.

## Algorithm

1. Convert to 0-indexed: $x' = x - 1$, $y' = y - 1$.
2. Compute $d = \max\left(\lceil x'/2 \rceil, \lceil y'/2 \rceil, \lceil (x'+y')/3 \rceil\right)$.
3. If $x' + y' + d$ is odd, $d \gets d + 1$.
4. If $(x', y') \in \{(0,1), (1,0), (1,1), (2,2)\}$, $d \gets d + 2$.
5. Output $d$.

## Example

$(42, 1337)$: $x' = 41$, $y' = 1336$.

- $d_0 = \max(\lceil 41/2 \rceil, \lceil 1336/2 \rceil, \lceil 1377/3 \rceil) = \max(21, 668, 459) = 668$.
- $x' + y' + d = 41 + 1336 + 668 = 2045$ (odd). Increment $d$ by 1: $d = 669$.
- Result: **669**.

## Complexity

- **Time:** $O(1)$ per query
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Knight%20Moves%20Queries.cpp)
