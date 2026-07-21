# Throwing Dice - Solution

**ID:** 1096 | **URL:** https://cses.fi/problemset/task/1096

## Approach

### Problem Restatement

Count the number of ways to get sum $n$ by throwing dice, where each throw yields 1–6. Output modulo $10^9+7$. $n$ up to $10^{18}$.

### Core idea

Let $f(n)$ be the number of ways to reach sum $n$. The last throw can be 1 through 6, partitioning all ways into disjoint cases:

$$f(n) = f(n-1) + f(n-2) + f(n-3) + f(n-4) + f(n-5) + f(n-6)$$

Base: $f(0) = 1$, $f(k) = 0$ for $k < 0$.

This is a linear recurrence of order 6. Convert it to matrix form using a state vector $\mathbf{v}_n = (f(n{-}5), f(n{-}4), \ldots, f(n))^T$:

$$\mathbf{v}_{n+1} = A \cdot \mathbf{v}_n, \quad A = \begin{pmatrix} 0 & 1 & 0 & 0 & 0 & 0 \\ 0 & 0 & 1 & 0 & 0 & 0 \\ 0 & 0 & 0 & 1 & 0 & 0 \\ 0 & 0 & 0 & 0 & 1 & 0 \\ 0 & 0 & 0 & 0 & 0 & 1 \\ 1 & 1 & 1 & 1 & 1 & 1 \end{pmatrix}$$

Rows 1–5 shift the window by one position; row 6 computes the recurrence. Then $\mathbf{v}_n = A^n \cdot \mathbf{v}_0$ where $\mathbf{v}_0 = (0, 0, 0, 0, 0, 1)^T$, and $f(n)$ is the last element of $\mathbf{v}_n$.

Compute $A^n$ by **binary exponentiation** in $O(6^3 \log n)$.

### Algorithm

1. Build the $6 \times 6$ transition matrix $A$.
2. Compute $A^n$ via binary exponentiation.
3. Output element $[5][5]$ of $A^n$.

### Example

$n = 8$: $f(1){=}1, f(2){=}2, f(3){=}4, f(4){=}8, f(5){=}16, f(6){=}32, f(7){=}1{+}2{+}4{+}8{+}16{+}32{=}63, f(8){=}2{+}4{+}8{+}16{+}32{+}63{=}125$ $\checkmark$.

## Complexity

- **Time:** $O(\log n)$ (constant $6^3$ per matrix multiply, $\log n$ squarings)
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/Throwing%20Dice.cpp)
