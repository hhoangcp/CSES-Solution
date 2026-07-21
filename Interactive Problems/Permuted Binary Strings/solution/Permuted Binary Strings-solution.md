# Permuted Binary Strings - Solution

**ID:** 3228 | **URL:** https://cses.fi/problemset/task/3228

## Approach

### Problem Restatement

There is a hidden permutation $a_1, a_2, \dots, a_n$ of integers $1, 2, \dots, n$. You can choose a binary string $b_1 b_2 \dots b_n$ and receive the string $b_{a_1} b_{a_2} \dots b_{a_n}$. Find the permutation with at most 10 queries.

### Core Idea

Each query permutes the bits of the input string according to the hidden permutation: the response at position $j$ is $b_{a_j}$. By designing the input string so that position $i$ encodes a specific property of integer $i$, the response reveals that property of each $a_j$.

**Bit-by-bit extraction:** Every integer in $[1, n]$ has a unique binary representation using $\lceil \log_2(n+1) \rceil \le 10$ bits. For each bit position $l$, construct the string $s$ where $s_i = \text{bit}_l(i)$. When querying $s$, the response $r_j = s_{a_j} = \text{bit}_l(a_j)$. After all bit positions, each $a_j$ is fully determined by assembling its bits.

**Optimality:** Distinguishing $n$ values requires at least $\lceil \log_2 n \rceil$ queries. Our algorithm uses exactly $\lceil \log_2(n+1) \rceil$ queries, which is optimal.

### Algorithm

For each bit position $l = 0, 1, \dots, \lceil \log_2(n+1) \rceil - 1$:

1. Construct string $s$ of length $n$ where $s_i = \begin{cases} 1 & \text{if } i \wedge 2^l \neq 0 \\ 0 & \text{otherwise} \end{cases}$.
2. Query "? $s$", receive response $r$.
3. For each $j$: if $r_j = 1$, set bit $l$ of $a_j$.

After all queries, output "! $a_1\ a_2\ \dots\ a_n$".

### Example

$n = 3$, hidden permutation $[1, 3, 2]$ (matching the problem statement's example):

| Bit $l$ | String $s$ | Response $r$ | Extracted bits |
|---------|-----------|--------------|----------------|
| 0 | `101` (bit 0 of 1,2,3) | `110` | $a_1$ bit 0 = 1, $a_2$ bit 0 = 1, $a_3$ bit 0 = 0 |
| 1 | `011` (bit 1 of 1,2,3) | `011` | $a_1$ bit 1 = 0, $a_2$ bit 1 = 1, $a_3$ bit 1 = 1 |

Reconstruction: $a_1 = 0 \cdot 2 + 1 = 1$, $a_2 = 1 \cdot 2 + 1 = 3$, $a_3 = 1 \cdot 2 + 0 = 2$. Result: $[1, 3, 2]$. ✓

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Permuted%20Binary%20Strings.cpp)
