# Xor Pyramid Diagonal - Solution

**ID:** 3194 | **URL:** https://cses.fi/problemset/task/3194

## Approach

### Problem Restatement

Given an XOR pyramid with bottom row $a_0, a_1, \ldots, a_{n-1}$, find the leftmost element of each row (from bottom to top).

### Core idea

In an XOR pyramid, the leftmost element of row $r$ (0-indexed from the bottom) equals $\bigoplus_{j=0}^{r} a_j \cdot [\binom{r}{j} \text{ is odd}]$. By **Lucas' theorem** on GF(2), $\binom{r}{j}$ is odd iff every 1-bit of $j$ also appears in $r$, i.e., $j$ is a **submask** of $r$ ($j \subseteq r$). Thus the problem reduces to computing $\text{left}[r] = \bigoplus_{j \subseteq r} a_j$ for all $r$, which is exactly the **subset Zeta transform** over GF(2) — computed efficiently via SOS DP.

### Algorithm

1. **Initialize:** Set $dp[i] = a_i$ for all $i$.
2. **SOS DP (subset Zeta transform):** For each bit position $i$ from 0 to $h-1$ (where $h = \lceil \log_2 n \rceil$), and for each index $j$: if bit $i$ is set in $j$, update $dp[j] \mathrel{\oplus}= dp[j \oplus 2^i]$.
3. **Result:** $dp[r] = \text{left}[r]$ for each row $r$.

**Why this works:** By induction on bit $i$. After processing bit $i$, $dp[mask]$ contains the XOR of all $a_j$ where $j$ is a submask of $mask$ considering only bits $0$ through $i$. When bit $i$ is set in $mask$, XORing in $dp[mask \oplus 2^i]$ adds contributions from submasks with bit $i = 0$; submasks with bit $i = 1$ were already present. After all $h$ bits, $dp[mask]$ accumulates XOR of all submasks.

### Example

Input: $n = 8$, bottom row $[2, 10, 5, 12, 9, 5, 1, 5]$.

| $r$ | Binary | Submasks of $r$ | $\text{left}[r]$ |
|---|---|---|---|
| 0 | 000 | $\{0\}$ | $a_0 = 2$ |
| 1 | 001 | $\{0, 1\}$ | $2 \oplus 10 = 8$ |
| 2 | 010 | $\{0, 2\}$ | $2 \oplus 5 = 7$ |
| 3 | 011 | $\{0, 1, 2, 3\}$ | $2 \oplus 10 \oplus 5 \oplus 12 = 1$ |
| 4 | 100 | $\{0, 4\}$ | $2 \oplus 9 = 11$ |
| 5 | 101 | $\{0, 1, 4, 5\}$ | $2 \oplus 10 \oplus 9 \oplus 5 = 4$ |
| 6 | 110 | $\{0, 2, 4, 6\}$ | $2 \oplus 5 \oplus 9 \oplus 1 = 15$ |
| 7 | 111 | $\{0, 1, 2, 3, 4, 5, 6, 7\}$ | $2 \oplus 10 \oplus 5 \oplus 12 \oplus 9 \oplus 5 \oplus 1 \oplus 5 = 9$ |

Result: `2 8 7 1 11 4 15 9`.

## Complexity

- **Time:** $O(n \cdot h)$ where $h = \lceil \log_2 n \rceil$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Xor%20Pyramid%20Diagonal.cpp)
