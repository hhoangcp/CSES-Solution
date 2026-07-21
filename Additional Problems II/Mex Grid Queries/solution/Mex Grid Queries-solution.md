# Mex Grid Queries - Solution

**ID:** 1157 | **URL:** https://cses.fi/problemset/task/1157

## Problem Statement

Consider a 2D grid with rows and columns numbered from 1. Each cell contains the smallest non-negative integer not appearing to its left in the same row or above in the same column. Compute the value at cell $(y, x)$.

## Approach

### Pattern observation: Nim-sum table

Examine the first cells (0-indexed): $(0,0) = 0$, $(0,1) = 1$, $(1,0) = 1$, $(1,1) = 2$. Result table:

| $y \backslash x$ | 0 | 1 | 2 | 3 | 4 |
|:---:|:---:|:---:|:---:|:---:|:---:|
| **0** | 0 | 1 | 2 | 3 | 4 |
| **1** | 1 | 0 | 3 | 2 | 5 |
| **2** | 2 | 3 | 0 | 1 | 6 |
| **3** | 3 | 2 | 1 | 0 | 7 |
| **4** | 4 | 5 | 6 | 7 | 0 |

Cell $(i, j)$ has value $i \oplus j$ — this is the **Nim-sum table**. Since the problem is 1-indexed, convert to 0-indexed before XOR:

$$\text{Value at } (y, x) = (y - 1) \oplus (x - 1)$$

### Why XOR satisfies the MEX condition

Strong induction on $y + x$. Assume correct for all cells with $y' + x' < y + x$. Forbidden set at $(y, x)$ (0-indexed: $(i, j)$):

- Row: $\{i \oplus k : 0 \le k \le j-1\}$. Column: $\{k \oplus j : 0 \le k \le i-1\}$.

**$i \oplus j$ is not forbidden:** If in the row, we'd need $k = j$ (XOR is invertible), but $k \le j-1$. If in the column, we'd need $k = i$, but $k \le i-1$.

**Every $v < i \oplus j$ is forbidden:** Consider the highest bit where $v$ differs from $i \oplus j$ (at this bit $v$ has 0, $i \oplus j$ has 1). If the bit belongs to the $i$ part, then $i \oplus v$ has that bit as 0 so $i \oplus v < i$, meaning $k = i \oplus v \le i-1$ exists in the column. If it belongs to the $j$ part, similarly $j \oplus v < j$ exists in the row. At least one direction contains $v$.

## Example

$y = 3, x = 5$: $(3-1) \oplus (5-1) = 2 \oplus 4$.

- $2 = 010_2$, $4 = 100_2$, $2 \oplus 4 = 110_2 = 6$.
- Verify: row 3 before: $\{2,3,0,1\}$, column 5 before: $\{4,5\}$. Forbidden: $\{0,1,2,3,4,5\}$. MEX = 6. Correct.

## Complexity

- **Time:** $O(1)$ per query
- **Memory:** $O(1)$

## Code (C++)

[Solution Code](../code/Mex%20Grid%20Queries.cpp)
