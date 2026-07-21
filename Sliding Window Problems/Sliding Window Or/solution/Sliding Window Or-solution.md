# Sliding Window Or - Solution

**ID:** 3405 | **URL:** https://cses.fi/problemset/task/3405

## Approach

### Problem Restatement

Given an array of $n$ integers (generated via $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$), find the bitwise OR of each sliding window of $k$ elements. Output the XOR of all OR results. Note: $n$ can be up to $10^7$, requiring $O(n)$ time.

### Core Idea

Bitwise OR is idempotent ($a \mid a = a$) and commutative/associative, so overlapping ranges can be combined without error. This enables a sparse-table-style block decomposition where each window of size $k$ spans at most 2 blocks, and the OR is computed from precomputed suffix and prefix arrays in $O(1)$.

### Algorithm

**Step 1: Generate the array.** Compute $x_1 = x$, $x_i = (a \cdot x_{i-1} + b) \bmod c$ for $i \ge 2$.

**Step 2: Block decomposition of size $k$.** Divide the array into blocks of size $k$. Precompute:
- `dp[i]`: OR from the start of $i$'s block to position $i$. Reset at block boundaries ($i \bmod k = 0$).
- `dq[i]`: OR from position $i$ to the end of $i$'s block. Reset at block boundaries ($({i+1}) \bmod k = 0$) or array end.

**Step 3: Window OR.** Every window of size $k$ spans at most 2 blocks. The OR of window $[i, i{+}k{-}1]$ is:
$$\text{dq}[i] \mid \text{dp}[i+k-1]$$

This works because `dq[i]` covers the suffix of $i$'s block, and `dp[i+k-1]` covers the prefix of the next block. Since OR is commutative, associative, and idempotent, combining these two non-overlapping parts gives the correct result — even when the window lies entirely within one block (both parts cover the same range, and OR with itself is idempotent).

Result: $\bigoplus_{i=0}^{n-k} (\text{dq}[i] \mid \text{dp}[i+k-1])$.

### Example

With $n=8$, $k=5$, generator $x=3, a=7, b=1, c=11$:

Generated array: $[3, 0, 1, 8, 2, 4, 7, 6]$. Blocks: $B_0=[3,0,1,8,2]$, $B_1=[4,7,6]$.

`dp = [3, 3, 3, 11, 11, 4, 7, 7]`, `dq = [11, 11, 11, 10, 2, 7, 7, 6]`.

- Window 0 ($i{=}0$): `dq[0] | dp[4]` $= 11 \mid 11 = 11$
- Window 1 ($i{=}1$): `dq[1] | dp[5]` $= 11 \mid 4 = 15$
- Window 2 ($i{=}2$): `dq[2] | dp[6]` $= 11 \mid 7 = 15$
- Window 3 ($i{=}3$): `dq[3] | dp[7]` $= 10 \mid 7 = 15$

Answer: $11 \oplus 15 \oplus 15 \oplus 15 = 4$.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Or.cpp)
