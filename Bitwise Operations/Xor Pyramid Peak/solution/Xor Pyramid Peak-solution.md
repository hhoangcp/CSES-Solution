# Xor Pyramid Peak - Solution

**ID:** 2419 | **URL:** https://cses.fi/problemset/task/2419

## Approach

### Problem Restatement

Given an XOR pyramid with bottom row $a_0, a_1, \ldots, a_{n-1}$ (each element is the XOR of the two below it), find the top element (peak).

### Core idea

The XOR pyramid has a structure analogous to Pascal's triangle. The peak equals $\bigoplus_{i:\ \binom{n-1}{i}\ \text{is odd}} a_i$. Both **Lucas' theorem** and **Kummer's theorem** characterize which binomial coefficients are odd, leading to two implementations.

### Common setup: Binomial coefficients in the XOR pyramid

The $i$-th element of the $k$-th row from the bottom is $b_k[i] = \bigoplus_{j=0}^{k} a_{i+j} \cdot [\binom{k}{j} \bmod 2 = 1]$. The peak (row $n-1$, single element) is:

$$\text{peak} = \bigoplus_{i:\ \binom{n-1}{i}\ \text{is odd}} a_i$$

### Method 1: Lucas' theorem

**Lucas' theorem** on GF(2): $\binom{m}{k} \bmod 2 = 1$ if and only if $k$ is a **submask** of $m$ ($k \subseteq m$, i.e., every 1-bit of $k$ also appears in $m$). Proof: write $m = \sum m_i 2^i$, $k = \sum k_i 2^i$; then $\binom{m}{k} \equiv \prod_i \binom{m_i}{k_i} \pmod{2}$. Each factor is 0 when $k_i = 1, m_i = 0$, so the product is 1 iff $k_i \le m_i$ for all $i$, i.e., $k \subseteq m$.

**Implementation:** For each $i$, check if $(i \wedge (n{-}1)) = i$. If so, XOR $a_i$ into the result. Time $O(n)$, extra space $O(1)$.

### Method 2: Kummer's theorem

**Kummer's theorem:** The highest power of prime $p$ dividing $\binom{n}{k}$ equals the number of carries when adding $k$ and $n{-}k$ in base $p$. For $p = 2$, $\binom{n}{k}$ is odd iff there are **no carries** when adding $k$ and $n{-}k$ in binary.

**Implementation:** Precompute `bit[i]` such that `bit[n-1] - bit[i] - bit[n-1-i]` gives the number of carries when adding $i$ and $(n{-}1){-}i$. If this is 0, $\binom{n-1}{i}$ is odd and we XOR $a_i$ into the result.

The precomputation uses: `power[h] = power[h/2] + 1` for $h$ a power of 2, and `bit[i] = bit[i-1] + power[lowbit(i)]`. Time $O(n)$, space $O(n)$.

### Example

Input: $n = 8$, bottom row $[2, 10, 5, 12, 9, 5, 1, 5]$.

$n - 1 = 7 = 111_2$. Since $7$ has all bits set, every $i \le 7$ is a submask of $7$. Thus all $\binom{7}{i}$ are odd.

$\text{peak} = 2 \oplus 10 \oplus 5 \oplus 12 \oplus 9 \oplus 5 \oplus 1 \oplus 5 = 9$.

For contrast, if $n = 6$ ($n{-}1 = 5 = 101_2$): submasks of 5 are $\{0, 1, 4, 5\}$, so only $a_0, a_1, a_4, a_5$ contribute to the peak.

## Complexity

| Method | Time | Space |
|---|---|---|
| Lucas | $O(n)$ | $O(1)$ |
| Kummer | $O(n)$ | $O(n)$ |

## Code (C++)

- [Lucas Approach](../code/Xor%20Pyramid%20Peak%20-%20Lucas.cpp) — submask check via bitwise AND
- [Kummer Approach](../code/Xor%20Pyramid%20Peak%20-%20Kummer.cpp) — carry check via precomputed `bit[]`
