# And Subset Count - Solution

**ID:** 3141 | **URL:** https://cses.fi/problemset/task/3141

## Approach

### Problem Restatement

Given an array of $n$ integers, for each $k = 0, 1, \ldots, n$, count the number of non-empty subsets whose bitwise AND equals $k$, modulo $10^9 + 7$.

### Core idea

The AND of a subset equals $k$ iff every element contains all 1-bits of $k$ (i.e., each element is a **superset** of $k$) and no 0-bit of $k$ is set in every element simultaneously. Use **SOS DP** to count supersets of each mask, then **Möbius inversion** (reverse SOS) to extract exact-AND counts via inclusion-exclusion on the Boolean lattice.

### Algorithm

1. **Initialize:** For each array element $a_i$, increment $dp[a_i]$. Now $dp[mask]$ counts elements equal to $mask$.
2. **Forward SOS DP — count supersets:** For each bit $i$ from $0$ to $H-1$, if bit $i$ is set in $mask$: $dp[mask \oplus 2^i] \mathrel{+}= dp[mask]$. After this, $dp[mask]$ = number of elements that are supersets of $mask$ (i.e., $a_i \wedge mask = mask$). The key observation: if $a_i$ is a superset of $mask$, it is also a superset of any submask, so counts propagate downward.
3. **Count subsets whose AND contains $mask$:** $ans[mask] = 2^{dp[mask]} - 1$. Every non-empty subset of the $dp[mask]$ superset elements has AND containing $mask$ (since the AND of supersets is still a superset), and these are all such subsets. Hence $ans[mask] = \sum_{mask \subseteq s} f[s]$ where $f[s]$ is the number of subsets whose AND exactly equals $s$.
4. **Möbius inversion — exact AND counts:** By inclusion-exclusion on the Boolean lattice, $f[mask] = g[mask] - \sum_{mask \subset s} f[s]$ where $g[mask]$ is the count before inversion. This is exactly reverse SOS DP: for each bit $i$, if bit $i$ is set in $mask$: $ans[mask \oplus 2^i] \mathrel{-}= ans[mask]$. After this, $ans[mask]$ is the number of subsets whose AND exactly equals $mask$.

### Example

Input: $n = 4$, array $[3, 1, 3, 4]$.

**Step 1:** $dp[1] = 1$, $dp[3] = 2$, $dp[4] = 1$ (all others $0$).

**Step 2 — Forward SOS (showing masks $0$–$7$):**

| $mask$ | 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 |
|---|---|---|---|---|---|---|---|---|
| After bit 0 | 1 | 1 | 0 | 2 | 1 | 0 | 0 | 0 |
| After bit 1 | 3 | 3 | 2 | 2 | 1 | 0 | 0 | 0 |
| After bit 2 | **4** | **3** | **2** | **2** | **1** | 0 | 0 | 0 |

Key values: $dp[0]=4$ (all elements ⊃ 0), $dp[1]=3$ (1,3,3 ⊃ 1), $dp[3]=2$ (3,3 ⊃ 3), $dp[4]=1$ (4 ⊃ 4).

**Step 3:** $ans[mask] = 2^{dp[mask]} - 1$: $ans[0]=15$, $ans[1]=7$, $ans[2]=3$, $ans[3]=3$, $ans[4]=1$.

**Step 4 — Möbius inversion (subtracting superset contributions):**

- Bit 2: $ans[0] -= ans[4] \Rightarrow 14$; $ans[1] -= ans[5] \Rightarrow 7$; $ans[2] -= ans[6] \Rightarrow 3$; $ans[3] -= ans[7] \Rightarrow 3$.
- Bit 1: $ans[0] -= ans[2] \Rightarrow 11$; $ans[1] -= ans[3] \Rightarrow 4$; $ans[4] -= ans[6] \Rightarrow 1$; $ans[5] -= ans[7] \Rightarrow 0$.
- Bit 0: $ans[0] -= ans[1] \Rightarrow 7$; $ans[2] -= ans[3] \Rightarrow 0$; $ans[4] -= ans[5] \Rightarrow 1$; $ans[6] -= ans[7] \Rightarrow 0$.

Final: $ans[0]=7$, $ans[1]=4$, $ans[2]=0$, $ans[3]=3$, $ans[4]=1$.

Output: `7 4 0 3 1`.

## Complexity

- **Time:** $O(n + H \cdot 2^H)$ with $H = 18$
- **Space:** $O(2^H)$

## Code (C++)

[Solution Code](../code/And%20Subset%20Count.cpp)
