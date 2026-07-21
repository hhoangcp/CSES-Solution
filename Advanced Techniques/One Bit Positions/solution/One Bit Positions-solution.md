# One Bit Positions - Solution

**ID:** 2112 | **URL:** https://cses.fi/problemset/task/2112

## Approach

### Problem Restatement

Given a binary string of length $n$, for each distance $k$ from 1 to $n-1$, count the number of position pairs $(i, j)$ with $i - j = k$ where both positions have bit 1.

### Core Idea

Let $A[i] = 1$ if $S[i] = \text{'1'}$, otherwise 0. We need $\text{ans}[k] = \sum_j A[j] \cdot A[j+k]$, which is a correlation — not directly a convolution. To convert it, define $B[i] = A[n-1-i]$ (the reverse of $A$). The convolution $C = A * B$ has:

$$C[m] = \sum_i A[i] \cdot B[m-i] = \sum_i A[i] \cdot A[n-1-m+i]$$

Setting $m = n-1+k$:

$$C[n-1+k] = \sum_i A[i] \cdot A[i-k]$$

This is exactly the number of pairs of 1-bits at distance $k$. The **reversal trick** is the key insight: it transforms correlation into convolution, enabling FFT computation in $O(n \log n)$.

### Algorithm

1. Create array $A$ with $A[i] = 1$ if $S[i] = \text{'1'}$, otherwise 0.
2. Create array $B$ with $B[i] = A[n-1-i]$.
3. Compute convolution $C = A * B$ via FFT (forward transform both, multiply point-wise, inverse transform).
4. For each $k$ from 1 to $n-1$, output $\text{round}(C[n-1+k])$.

### Example

String: `1001011010` ($n=10$). Positions of '1': 0, 3, 5, 6, 8.

| $k$ | Pairs $(j, j{+}k)$ with both '1' | Count |
|-----|----------------------------------|-------|
| 1   | (5,6)                            | 1     |
| 2   | (3,5), (6,8)                     | 2     |
| 3   | (0,3), (3,6), (5,8)              | 3     |
| 4   | —                                | 0     |
| 5   | (0,5), (3,8)                     | 2     |
| 6   | (0,6)                            | 1     |
| 7   | —                                | 0     |
| 8   | (0,8)                            | 1     |
| 9   | —                                | 0     |

Output: `1 2 3 0 2 1 0 1 0`

## Complexity

- **Time:** $O(n \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/One%20Bit%20Positions.cpp)
