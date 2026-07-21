# Triangle Number Sums - Solution

**ID:** 3406 | **URL:** https://cses.fi/problemset/task/3406

## Approach

### Problem Restatement

Given a positive integer $n$ (up to $10^{12}$), find the minimum number of triangle numbers (numbers of the form $T_k = \frac{k(k+1)}{2}$) whose sum equals $n$. There are up to $t = 100$ test cases.

### Core idea

**Gauss's Eureka Theorem (1796):** Every positive integer can be represented as the sum of at most 3 triangle numbers. Gauss recorded this discovery as *"EYPHKA! num = $\Delta$ + $\Delta$ + $\Delta$"*.

This immediately bounds the answer to 1, 2, or 3. We check sequentially from smallest to largest.

**Key fact:** $n$ is a triangle number if and only if $8n + 1$ is a perfect square. This follows from solving $n = \frac{k(k+1)}{2} \Leftrightarrow k^2 + k - 2n = 0$, giving $k = \frac{-1 + \sqrt{1 + 8n}}{2}$; for $k$ to be a positive integer, $1 + 8n$ must be a perfect square.

### Algorithm

1. **Answer 1:** Compute $m = \lfloor\sqrt{8n+1}\rfloor$. If $m^2 = 8n+1$, then $n$ is a triangle number → return 1.
2. **Answer 2:** For each $i$ from 0 while $T_i \le n/2$, compute $rem = n - T_i$. If $8 \cdot rem + 1$ is a perfect square, then $n = T_i + T_j$ for some $j$ → return 2. (By symmetry of the pair, we only need $i$ up to $\sqrt{n}$, since $T_i \approx i^2/2$.)
3. **Answer 3:** If neither condition holds, by Gauss's theorem the answer must be 3 → return 3.

**Correctness:** Step 1 is optimal since $n > 0$ cannot be expressed with 0 numbers. Step 2 is only reached after Step 1 fails, so the answer cannot be 1. Step 3 is guaranteed by Gauss's theorem, which ensures the answer never exceeds 3.

### Example

| $n$ | $8n+1$ | Square? | Check | Answer |
|-----|--------|---------|-------|--------|
| 1 | 9 | $3^2$ ✓ | — | 1 |
| 2 | 17 | ✗ | $2 - 1 = 1$, $8 \cdot 1 + 1 = 9 = 3^2$ ✓ | 2 |
| 3 | 25 | $5^2$ ✓ | — | 1 |
| 42 | 337 | ✗ | $42 - 21 = 21$, $8 \cdot 21 + 1 = 169 = 13^2$ ✓ | 2 |
| 1337 | 10697 | ✗ | No pair found | 3 |

## Complexity

- **Time:** $O(\sqrt{n})$ per test case
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Triangle%20Number%20Sums.cpp)
