# Exponentiation - Solution

**ID:** 1095 | **URL:** https://cses.fi/problemset/task/1095

## Approach

### Problem Restatement

Compute $a^b \bmod (10^9+7)$ for $n$ queries ($1 \le n \le 2 \cdot 10^5$, $0 \le a, b \le 10^9$), with the convention $0^0 = 1$.

### Core Idea

With $b$ up to $10^9$, naive $O(b)$ multiplication per query is infeasible. Use **binary exponentiation**: decompose $b$ in binary and exploit:

$$a^b = a^{b_0 \cdot 2^0 + b_1 \cdot 2^1 + \cdots + b_k \cdot 2^k} = \prod_{i: b_i = 1} a^{2^i}$$

Equivalently, divide-and-conquer:

$$a^b = \begin{cases} 1 & b = 0 \\ (a^{b/2})^2 & b \text{ even} \\ (a^{(b-1)/2})^2 \cdot a & b \text{ odd} \end{cases}$$

Each step halves $b$, requiring $O(\log b)$ multiplications.

*Correctness (induction on $b$).* Base: $b = 0$ returns $1$. Step: for even $b = 2k$, by IH the subproblem returns $a^k$, and squaring gives $a^{2k} = a^b$. For odd $b = 2k+1$, squaring $a^k$ then multiplying by $a$ gives $a^{2k+1} = a^b$.

**Edge cases.** $0^0 = 1$ by convention (handled since $b = 0$ returns 1). $0^b = 0$ for $b > 0$ (handled naturally). All multiplications take modulo after each step to prevent overflow: with $p < 2^{30}$, the product of two residues fits in 64-bit integers.

### Algorithm

1. For each query $(a, b)$: compute $a^b \bmod p$ via iterative binary exponentiation.
2. Maintain a running result (initially 1) and a base (initially $a$). While $b > 0$: if $b$ is odd, multiply result by base; square base; halve $b$.

### Example

$3^{13}$: binary $13 = 1101_2 = 8 + 4 + 1$.

| Step | $b$ | Base | Result |
|:---:|:---:|:---:|:---:|
| 0 | 13 (odd) | $3^1 = 3$ | $1 \cdot 3 = 3$ |
| 1 | 6 (even) | $3^2 = 9$ | 3 |
| 2 | 3 (odd) | $3^4 = 81$ | $3 \cdot 81 = 243$ |
| 3 | 1 (odd) | $3^8 = 6561$ | $243 \cdot 6561 = 1594323$ |

$3^{13} = 1594323$. $\checkmark$

## Complexity

- **Time:** $O(n \log b_{\max})$ — $O(\log b)$ per query
- **Memory:** $O(1)$ — iterative version
