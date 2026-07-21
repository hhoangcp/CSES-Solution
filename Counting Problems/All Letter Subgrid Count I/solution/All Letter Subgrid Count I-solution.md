# All Letter Subgrid Count I - Solution

**ID:** 3415 | **URL:** https://cses.fi/problemset/task/3415

## Approach

### Problem Restatement

Given an $n \times n$ grid where each cell contains one of the first $k$ uppercase letters, count the number of square subgrids that contain all $k$ letters.

### Monotonicity and reduction to minimum size

If a square of size $s$ at position $(i, j)$ (bottom-right corner) contains all $k$ letters, then every larger square with the same bottom-right corner also contains all letters — adding cells only introduces more letters via set union. This monotonicity means for each position $(i, j)$, we only need to find the **minimum** size $s_{\min}$ such that the $s_{\min} \times s_{\min}$ square contains all $k$ letters. The number of valid squares at $(i, j)$ is then:

$$\max\big(0,\ \min(i+1, j+1) - s_{\min} + 1\big)$$

### Doubling with bitmask

Since $k \le 26$, encode the set of letters in a square as a 32-bit bitmask (letter $c$ maps to bit $c - \text{A}$). The bitmask of a union of regions is the bitwise OR of their masks. A square contains all $k$ letters iff its mask $= (1 \ll k) - 1$.

Maintain `mask[i][j]` = bitmask of the $l \times l$ square with bottom-right corner at $(i, j)$, where $l$ doubles each iteration.

For each $l = 1, 2, 4, 8, \ldots$:

1. **Check $2l \times 2l$ square:** Combine four $l \times l$ masks:

$$\text{Mask}_{2l}(i,j) = \text{mask}[i][j] \mid \text{mask}[i{-}l][j] \mid \text{mask}[i][j{-}l] \mid \text{mask}[i{-}l][j{-}l]$$

   The four $l \times l$ squares tile the $2l \times 2l$ square exactly, so their OR gives the correct bitmask. If $\text{Mask}_{2l}(i,j) = \text{full}$, proceed to binary search.

2. **Binary search in $[l, 2l]$:** Find the smallest $s \in [l, 2l]$ whose combined mask equals `full`. Binary search on the offset $d \in [0, l]$ where size $s = l + d$ uses:

$$\text{Mask}_s(i,j) = \text{mask}[i][j] \mid \text{mask}[i{-}d][j] \mid \text{mask}[i][j{-}d] \mid \text{mask}[i{-}d][j{-}d]$$

   The four overlapping $l \times l$ squares at offset $d$ cover exactly the $(l+d) \times (l+d)$ square with bottom-right at $(i, j)$, and their OR captures exactly the letters in that region. Since adding cells only adds letters (bitmask OR is monotonic), binary search is valid.

3. **Record answer:** Set $\text{hasAns}[i][j] = \text{true}$ and add $\max(0, \min(i+1, j+1) - s_{\min} + 1)$ to the total. The `hasAns` array prevents double counting across iterations.

4. **Update mask to represent $2l \times 2l$:** Merge vertically ($\text{mask}[i][j] \mathrel{|}= \text{mask}[i{-}l][j]$) then horizontally ($\text{mask}[i][j] \mathrel{|}= \text{mask}[i][j{-}l]$). Vertical merging stacks two $l \times l$ regions into an $l \times 2l$ strip; horizontal merging joins two such strips into the full $2l \times 2l$ square.

### Examples

**Problem example:** $n = 5$, $k = 3$, grid:

```
A B B B C
B B B B C
B C A A A
A A A A A
A A A A A
```

**Tracing position (2, 2) (0-indexed), bottom-right = 'A':**

- $l = 1$: Combine four $1 \times 1$ cells: $\text{mask}[2][2] \cup \text{mask}[1][2] \cup \text{mask}[2][1] \cup \text{mask}[1][1] = \{A\} \cup \{B\} \cup \{C\} \cup \{B\} = \{A,B,C\} = \text{full}$.
  - Binary search in $[1, 2]$: size 1 gives $\{A\} \ne$ full; size 2 gives $\{A,B,C\}$ = full → $s_{\min} = 2$.
  - Count: $\min(3, 3) - 2 + 1 = 2$ (the $2 \times 2$ and $3 \times 3$ squares).

**Tracing position (4, 4), bottom-right = 'A':**

- $l = 1$: Four $1 \times 1$ cells are all $A$ → $\{A\} \ne$ full. Skip.
  - After update, $\text{mask}[4][4]$ represents the $2 \times 2$ square = $\{A\}$.
- $l = 2$: Combine four $2 \times 2$ masks:
  - $\text{mask}[4][4] = \{A\}$, $\text{mask}[2][4] = \{A,B,C\}$ (cells B,C,A,A), $\text{mask}[4][2] = \{A\}$, $\text{mask}[2][2] = \{A,B,C\}$ (cells B,B,C,A).
  - Combined = $\{A,B,C\}$ = full.
  - Binary search in $[2, 4]$: size 3 gives $\{A\} \ne$ full (four overlapping $2 \times 2$ masks in the bottom-right corner are all $\{A\}$); size 4 gives full → $s_{\min} = 4$.
  - Count: $\min(5, 5) - 4 + 1 = 2$ (the $4 \times 4$ and $5 \times 5$ squares).

**Full result:** Summing over all 25 positions gives **15**. ✓

## Complexity

- **Time:** $O(n^2 \log n)$ — each of the $O(\log n)$ doubling steps processes $O(n^2)$ positions, with binary search adding $O(\log n)$ per position.
- **Space:** $O(n^2)$ — for the mask and hasAns arrays.

## Code (C++)

[Solution Code](../code/All%20Letter%20Subgrid%20Count%20I.cpp)
