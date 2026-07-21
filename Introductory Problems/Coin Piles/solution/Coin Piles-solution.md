# Coin Piles - Solution

**ID:** 1754 | **URL:** https://cses.fi/problemset/task/1754

## Approach

### Problem Restatement

Given $t$ test cases ($1 \le t \le 10^5$), each with two coin piles $a$ and $b$ ($0 \le a, b \le 10^9$). In each move, take exactly 1 coin from one pile and 2 from the other. Determine whether both piles can be emptied.

### Core Idea

Model each move as a choice between two types:
- **Type X:** take 1 from $a$ and 2 from $b$. Let $x$ = count.
- **Type Y:** take 2 from $a$ and 1 from $b$. Let $y$ = count.

Both piles empty iff: $\begin{cases} x + 2y = a \\ 2x + y = b \end{cases}$

Adding both equations: $3(x+y) = a+b$, so $(a+b)$ must be divisible by 3. Solving: $x = \frac{2b-a}{3}$, $y = \frac{2a-b}{3}$.

For a valid solution, $x$ and $y$ must be non-negative integers. This gives the necessary and sufficient conditions:

1. $(a+b) \bmod 3 = 0$
2. $a \leq 2b$ (ensures $x \geq 0$)
3. $b \leq 2a$ (ensures $y \geq 0$)

Or equivalently: $\max(a,b) \leq 2 \cdot \min(a,b)$.

**Correctness:** If all three conditions hold, $x$ and $y$ are non-negative integers satisfying the system, providing a concrete sequence of moves to empty both piles. Conversely, if any condition fails, no valid $(x,y)$ exists — either the total coins can't be partitioned into groups of 3, or one pile is too large relative to the other for the 1:2 ratio constraint.

### Algorithm

For each test case, check:
1. $(a+b) \bmod 3 = 0$
2. $\max(a,b) \leq 2 \cdot \min(a,b)$

If both hold, output "YES"; otherwise "NO".

### Example

From the sample:
- $(a,b) = (2,1)$: sum = 3 (div by 3), $\max(2,1) = 2 \leq 2 \cdot 1 = 2$. **YES** ($x=0, y=1$).
- $(a,b) = (2,2)$: sum = 4 (not div by 3). **NO**.
- $(a,b) = (3,3)$: sum = 6 (div by 3), $\max(3,3) = 3 \leq 2 \cdot 3 = 6$. **YES** ($x=1, y=1$).

## Complexity

- **Time:** $O(1)$ per test case
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Coin%20Piles.cpp)
