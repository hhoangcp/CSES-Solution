# System of Linear Equations - Solution

**ID:** 3154 | **URL:** https://cses.fi/problemset/task/3154

## Approach

### Problem Restatement

Given $n$ linear equations in $m$ variables with coefficients modulo $p = 10^9+7$: $a_{i,1}x_1 + \cdots + a_{i,m}x_m = b_i \pmod{p}$. Find any solution, or output $-1$ if none exists.

### Core idea

Apply **Gaussian elimination** over the finite field $\mathbb{F}_p$. Since $p = 10^9+7$ is prime, $\mathbb{F}_p$ is a field, so every non-zero element has a modular inverse (computed via Fermat's little theorem: $a^{-1} \equiv a^{p-2} \pmod{p}$). This allows standard row operations:

1. **Find pivot** in column $j$: locate a row with non-zero coefficient. If none, $x_j$ is a free variable.
2. **Normalize:** multiply the pivot row by $a_{i,j}^{-1}$ so the pivot becomes 1.
3. **Eliminate:** subtract $a_{k,j}$ times the pivot row from every other row $k$ to zero out column $j$.

Elementary row operations preserve the solution space (multiplying by a non-zero scalar is invertible; adding a multiple of one equation to another doesn't change solutions). After elimination, the reduced row echelon form yields the solution directly.

**Consistency check:** If a row has all zero coefficients but non-zero right-hand side ($0 = b_i$), the system is inconsistent → output $-1$.

**Free variables:** If $\text{rank}(A) < m$, the system has infinitely many solutions. Set each free variable to 0 for a specific solution.

### Algorithm

1. Form the augmented matrix $[A \mid b]$.
2. For each column $j = 1, \ldots, m$: find a pivot, swap to position, normalize, and eliminate.
3. Check for inconsistent rows. If found, output $-1$.
4. For each variable: if its column has a pivot, $x_j = b_i$ of the pivot row; otherwise $x_j = 0$.

### Example

$n = m = 3$, equations: $2x_1 + x_3 = 7$, $x_1 + 2x_2 = 0$, $x_1 + 3x_2 + x_3 = 2$.

After elimination: $x_1 = 2$, $x_2 = 10^9+6 \equiv -1 \pmod{p}$, $x_3 = 3$.

Verify: $2(2) + 3 = 7$ $\checkmark$, $2 + 2(10^9+6) \equiv 0$ $\checkmark$, $2 + 3(10^9+6) + 3 \equiv 2$ $\checkmark$.

## Complexity

- **Time:** $O(n \cdot m^2)$
- **Space:** $O(n \cdot m)$

## Code (C++)

[Solution Code](../code/System%20of%20Linear%20Equations.cpp)
