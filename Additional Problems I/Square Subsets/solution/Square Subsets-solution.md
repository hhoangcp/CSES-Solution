# Square Subsets - Solution

**ID:** 3193 | **URL:** https://cses.fi/problemset/task/3193

## Problem Statement

Count the number of subsets of an array whose product of elements is a perfect square (including the empty set with product 1). Result modulo $10^9 + 7$.

## Approach

### Parity bitmask

A number is a perfect square iff every prime in its factorization has an even exponent. For each $x_i$, define a **parity mask**: bit $j = 1$ if prime $p_j$ appears an odd number of times in $x_i$.

The product of a subset is a perfect square iff the XOR of all masks equals 0 (since XOR on bit $j$ corresponds to addition mod 2 of exponent of $p_j$, and XOR = 0 means all exponents are even).

### Linear basis

The problem reduces to: given $n$ bitmasks in $\mathbb{F}_2^P$ (where $P$ is the number of primes $\le 5000$), count subsets whose XOR equals 0.

Build a linear basis via Gaussian elimination: for each mask, iterate over set bits from highest to lowest; if no basis element occupies that bit, insert the mask; otherwise XOR with the existing basis element and continue.

**Why $2^{n-r}$:** The linear map $f: \mathbb{F}_2^n \to \mathbb{F}_2^P$ mapping subsets (characteristic vectors) to XOR of masks has kernel of size $2^{n-r}$ where $r = \dim(\text{im}(f))$ is the basis size. By the first isomorphism theorem, $|\ker(f)| = 2^n / 2^r = 2^{n-r}$.

Intuitively: the $n - r$ dependent elements can be freely included or excluded; for each choice, there is exactly one way to include basis elements to make the total XOR equal 0.

### Example

$a = [2, 2, 3, 6]$, primes: $\{2, 3\}$.

| Element | Factorization | Mask $(p_2, p_3)$ |
|---------|--------------|-------------------|
| 2₁ | $2^1$ | $(1, 0)$ |
| 2₂ | $2^1$ | $(1, 0)$ |
| 3 | $3^1$ | $(0, 1)$ |
| 6 | $2^1 \cdot 3^1$ | $(1, 1)$ |

Basis: $\{(1,0), (0,1)\}$, $r = 2$. Answer: $2^{4-2} = 4$.

| Subset | XOR of masks | Product | Square? |
|--------|-------------|---------|---------|
| $\emptyset$ | $(0,0)$ | 1 | ✓ |
| $\{2_1, 2_2\}$ | $(1,0) \oplus (1,0) = (0,0)$ | 4 | ✓ |
| $\{2_1, 3, 6\}$ | $(1,0) \oplus (0,1) \oplus (1,1) = (0,0)$ | 36 | ✓ |
| $\{2_2, 3, 6\}$ | $(1,0) \oplus (0,1) \oplus (1,1) = (0,0)$ | 36 | ✓ |

## Complexity

- **Time:** $O(n \cdot P / w)$ where $P = 669$ (primes $\le 5000$), $w = 64$ (bitset word size)
- **Memory:** $O(P^2 / w)$ for the basis matrix

## Code (C++)

[Solution Code](../code/Square%20Subsets.cpp)
