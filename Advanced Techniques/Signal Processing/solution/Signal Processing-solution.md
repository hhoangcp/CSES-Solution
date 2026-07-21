# Signal Processing - Solution

**ID:** 2113 | **URL:** https://cses.fi/problemset/task/2113

## Approach

### Problem Restatement

Given a signal of length $n$ and a mask of length $m$, compute the sum of products of aligned values at each position as the mask slides across the signal. Output $n + m - 1$ values.

### Core Idea

At each position, the result is $\sum_i A[i+k] \cdot B[i]$ over valid indices — a **cross-correlation**. To compute this efficiently via FFT, reverse the mask: $B'[i] = B[m{-}1{-}i]$. The convolution $C = A * B'$ yields:

$$C[k] = \sum_j A[j] \cdot B'[k-j] = \sum_j A[j] \cdot B[m{-}1{-}k{+}j]$$

Substituting $i = j - k + m - 1$, this becomes $\sum_i A[i + k - m + 1] \cdot B[i]$, which is exactly the sum of aligned products when the mask is at position $k - m + 1$. As $k$ ranges from 0 to $n + m - 2$, all valid sliding positions are covered.

### Algorithm

1. Read signal $A$ and mask $B$. Reverse the mask: $B'[i] = B[m{-}1{-}i]$.
2. Compute convolution $C = A * B'$ using FFT (forward both, point-wise multiply, inverse).
3. Output $\text{round}(C[k])$ for $k = 0, \ldots, n+m-2$.

### Example

Signal: $A = [1, 3, 2, 1, 4]$, Mask: $B = [1, 2, 3]$. Reversed mask: $B' = [3, 2, 1]$.

| $k$ | Aligned pairs | Computation | $C[k]$ |
|-----|---------------|-------------|--------|
| 0 | $A[0] \cdot B[2]$ | $1 \cdot 3$ | 3 |
| 1 | $A[0] \cdot B[1] + A[1] \cdot B[2]$ | $1 \cdot 2 + 3 \cdot 3$ | 11 |
| 2 | $A[0] \cdot B[0] + A[1] \cdot B[1] + A[2] \cdot B[2]$ | $1 \cdot 1 + 3 \cdot 2 + 2 \cdot 3$ | 13 |
| 3 | $A[1] \cdot B[0] + A[2] \cdot B[1] + A[3] \cdot B[2]$ | $3 \cdot 1 + 2 \cdot 2 + 1 \cdot 3$ | 10 |
| 4 | $A[2] \cdot B[0] + A[3] \cdot B[1] + A[4] \cdot B[2]$ | $2 \cdot 1 + 1 \cdot 2 + 4 \cdot 3$ | 16 |
| 5 | $A[3] \cdot B[0] + A[4] \cdot B[1]$ | $1 \cdot 1 + 4 \cdot 2$ | 9 |
| 6 | $A[4] \cdot B[0]$ | $4 \cdot 1$ | 4 |

Output: `3 11 13 10 16 9 4`

## Complexity

- **Time:** $O((n + m) \log(n + m))$
- **Memory:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Signal%20Processing.cpp)
