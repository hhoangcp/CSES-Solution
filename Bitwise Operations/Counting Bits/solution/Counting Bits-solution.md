# Counting Bits - Solution

**ID:** 1146 | **URL:** https://cses.fi/problemset/task/1146

## Approach

### Problem Restatement

Count the total number of 1-bits in the binary representations of all integers from $1$ to $n$.

### Core idea

Let $f(n)$ be the total number of 1-bits from $1$ to $n$, and let $p$ be the MSB position of $n$ ($2^p \le n < 2^{p+1}$). Split $[1, n]$ into the complete range $[1, 2^p - 1]$ and the partial range $[2^p, n]$. The complete range contributes $p \cdot 2^{p-1}$ (each of $p$ bit positions is set in exactly $2^{p-1}$ of the $2^p$ values). The partial range's MSB contributes $n - 2^p + 1$, and its lower bits are counted recursively as $f(n - 2^p)$.

### Algorithm

Define $f(n)$ recursively with $f(0) = 0$:

1. **Base case (complete range):** If $n = 2^{p+1} - 1$, then all $p+1$ bit positions are set in exactly $2^p$ of the $2^{p+1}$ values from $0$ to $n$, giving $f(2^{p+1} - 1) = (p+1) \cdot 2^p$.
2. **Recursive case:** $f(n) = (n - 2^p + 1) + p \cdot 2^{p-1} + f(n - 2^p)$, where:
   - $(n - 2^p + 1)$: MSB contribution from numbers $2^p$ to $n$.
   - $p \cdot 2^{p-1}$: contribution of lower bits in the complete range $[0, 2^p - 1]$.
   - $f(n - 2^p)$: recursive count of lower bits in $[2^p, n]$ (strip MSB).

### Example

**$n = 7$:** $p = 2$, and $7 = 2^3 - 1$ (complete case).

$f(7) = 3 \cdot 2^2 = 12$

Verify: 1 (1), 10 (1), 11 (2), 100 (1), 101 (2), 110 (2), 111 (3) → total = 12.

**$n = 5$:** $p = 2$, $5 \ne 2^3 - 1$ (recursive case).

$f(5) = (5 - 4 + 1) + 2 \cdot 2 + f(1) = 2 + 4 + 1 = 7$

Verify: 1 (1), 10 (1), 11 (2), 100 (1), 101 (2) → total = 7.

## Complexity

- **Time:** $O(\log^2 n)$ — $O(\log n)$ recursive calls, each finding MSB in $O(\log n)$
- **Space:** $O(\log n)$ (recursion depth)

## Code (C++)

[Solution Code](../code/Counting%20Bits.cpp)
