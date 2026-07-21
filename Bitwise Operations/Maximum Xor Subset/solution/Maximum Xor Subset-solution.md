# Maximum Xor Subset - Solution

**ID:** 3191 | **URL:** https://cses.fi/problemset/task/3191

## Approach

### Problem Restatement

Given an array of $n$ integers, find the maximum XOR sum of any subset (not necessarily contiguous).

### Core idea

The set of all subset XORs forms a **vector space over GF(2)** (the binary field), where addition is XOR. We need the maximum-numerical-value vector in this space. **Gaussian elimination over GF(2)** reduces the array to a basis in reduced row echelon form (RREF), from which the answer is simply the XOR of all non-zero elements.

### Algorithm

**Gaussian elimination to RREF:** Process bits from highest (bit 30) to lowest (bit 0):

1. **Select pivot:** At bit position $i$, find an element with bit $i$ set (among those not yet used as pivots). If none exists, skip. Swap it to the boundary position $l$ and increment $l$.
2. **Eliminate:** XOR the pivot into **every other** element (both before and after the pivot) that has bit $i$ set. This is RREF elimination — not just forward elimination — ensuring bit $i$ appears in exactly one element.
3. **Repeat** for all bit positions.

After elimination, each non-zero element has a **unique leading bit** (its highest set bit), and no other element shares that bit.

**Compute answer:** XOR all non-zero elements. This gives the maximum subset XOR.

### Why XOR all pivots is optimal

After RREF, let the pivots have leading bits $b_1 > b_2 > \cdots > b_m$. A key property: **bit $b_k$ appears in exactly one pivot** (namely the $k$-th). Therefore, for any subset XOR $v = \bigoplus_{k \in S} P_k$, bit $b_k$ of $v$ is 1 if and only if $k \in S$.

Now suppose we choose a subset $S \neq \{1, \ldots, m\}$, so some pivot is excluded. Let $k^*$ be the largest excluded index. Then bit $b_{k^*}$ of the result is 0. Any integer with bit $b_{k^*} = 0$ is at most $2^{b_{k^*}} - 1$. But the XOR of **all** pivots has bit $b_{k^*} = 1$, so its value is at least $2^{b_{k^*}}$. Since $2^{b_{k^*}} > 2^{b_{k^*}} - 1$, excluding any pivot always produces a strictly smaller result. Hence XORing all pivots is optimal.

### Example

Input: $n = 4$, array $[1, 6, 12, 6]$ (binary: 0001, 0110, 1100, 0110).

**Bit 3:** Pivot = 12 (1100). No other element has bit 3. Array: `[12, 6, 1, 6]`, $l=1$.

**Bit 2:** Pivot = 6 (0110) at position 1. Eliminate bit 2 from all others:
- $12 \oplus 6 = 10$ (1010): had bit 2 → eliminated.
- Second 6: $6 \oplus 6 = 0$: had bit 2 → eliminated.
- 1 (0001): no bit 2 → unchanged.

Array: `[10, 6, 1, 0]`, $l=2$.

**Bit 1:** No element from position 2 onward has bit 1. Skip.

**Bit 0:** Pivot = 1 (0001) at position 2. No other element has bit 0 (10=1010, 6=0110 both have bit 0 = 0). Array unchanged: `[10, 6, 1, 0]`.

**Basis:** $\{10, 6, 1\}$ with unique leading bits:
- $10 = \mathbf{1}010_2$ (leading bit 3)
- $6 = 0\mathbf{1}10_2$ (leading bit 2)
- $1 = 000\mathbf{1}_2$ (leading bit 0)

**Answer:** $10 \oplus 6 \oplus 1 = 1010 \oplus 0110 \oplus 0001 = 1101_2 = 13$.

Note: bit 1 ($2^1$) cannot appear in any subset XOR — including it would require a vector with leading bit 1, which doesn't exist in the basis.

## Complexity

- **Time:** $O(n \cdot 31)$ — 31 bit positions, each scanning and eliminating over $n$ elements
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Maximum%20Xor%20Subset.cpp)
