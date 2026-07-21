# K Subset Xors - Solution

**ID:** 3192 | **URL:** https://cses.fi/problemset/task/3192

## Approach

### Problem Restatement

Given an array of $n$ integers, find the $k$ smallest subset XOR values (including the empty set with XOR 0), in non-decreasing order.

### Core idea

Build a **linear basis** from the array elements. The basis has rank $sz$, generating $2^{sz}$ distinct XOR values. Since each distinct value appears $2^{n-sz}$ times among all $2^n$ subsets, we can map the $i$-th output value to the $\lceil i / 2^{n-sz} \rceil$-th smallest distinct XOR, retrieved via binary-search-style traversal of the reduced basis.

### Algorithm

1. **Build XOR basis (high-to-low):** Maintain `basis[i]` storing the basis vector with leading bit $i$. For each input element, eliminate higher bits by XORing with existing basis vectors (processing bits 29 down to 0). If the element is not zeroed, it becomes a new basis vector. The high-to-low order ensures each `basis[i]` has bit $i$ as its highest set bit, which is sufficient for the query — when we later toggle bit $i$ via `basis[i]`, any lower-bit side effects are corrected in subsequent iterations.
2. **Handle repetitions:** Each distinct XOR value appears $len = 2^{n-sz}$ times. If $n - sz \ge 20$, then $len > k$ and all outputs are 0. Otherwise, the $i$-th output value is `query(⌈i/len⌉)`.
3. **Query $k$-th smallest distinct XOR:** Set $tot = 2^{sz}$. Iterate basis from high bit to low. At each `basis[i]`:
   - $mid = tot / 2$: the lower half has bit $i$ = 0, the upper half has bit $i$ = 1.
   - If $k > mid$ (upper half) and bit $i$ of `mask` is 0: XOR `mask` with `basis[i]`.
   - If $k \le mid$ (lower half) and bit $i$ of `mask` is 1: XOR `mask` with `basis[i]`.
   - If $k > mid$: $k \mathrel{-}= mid$.
   - $tot \mathrel{>>}= 1$.
   
   This works because the leading-bit property ensures bit $i$ is the deciding factor at each level, partitioning the sorted XOR space into two halves.

### Example

Input: $n = 4$, array $[3, 5, 14, 8]$, $k = 9$.

**Basis construction:**
- Insert 3: `basis[1] = 3` (011), $sz = 1$.
- Insert 5: bit 2 not in any basis → `basis[2] = 5` (101), $sz = 2$.
- Insert 14: bit 3 not in any basis → `basis[3] = 14` (1110), $sz = 3$.
- Insert 8: $8 \oplus 14 = 6$, $6 \oplus 5 = 3$, $3 \oplus 3 = 0$ → linearly dependent, not inserted.

$sz = 3$, $len = 2^{4-3} = 2$.

**Distinct XOR values** (via `query(1)` through `query(8)`): 0, 3, 5, 6, 8, 11, 13, 14.

**Output** ($k = 9$, each value repeats 2 times): `0 0 3 3 5 5 6 6 8`.

## Complexity

- **Time:** $O(n \cdot 30 + k \cdot 30)$
- **Space:** $O(30)$

## Code (C++)

[Solution Code](../code/K%20Subset%20Xors.cpp)
