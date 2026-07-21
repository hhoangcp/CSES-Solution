# Mex Grid Construction - Solution

**ID:** 3419 | **URL:** https://cses.fi/problemset/task/3419

## Approach

### Problem Restatement

Construct an $n \times n$ grid ($1 \le n \le 100$) where each cell $(i, j)$ takes the value of the **mex** (smallest non-negative integer not present) of the values already placed to its left in the same row and above it in the same column.

### Core Idea

The answer at each 0-indexed cell $(i, j)$ is simply $i \oplus j$.

**Proof by induction.** Base: cell $(0,0)$ has mex of the empty set = 0 = $0 \oplus 0$. Inductive step: assume all cells $(i', j')$ before $(i,j)$ in row-major order have value $i' \oplus j'$. The set of existing values is:
- Left: $\{i \oplus 0, i \oplus 1, \ldots, i \oplus (j-1)\}$
- Above: $\{0 \oplus j, 1 \oplus j, \ldots, (i-1) \oplus j\}$

We show mex of this set equals $i \oplus j$:

1. **$i \oplus j$ is absent:** If $i \oplus k = i \oplus j$ for $k < j$, then $k = j$, contradiction. Similarly for $k \oplus j = i \oplus j$ with $k < i$.

2. **Every $v < i \oplus j$ is present:** Set $k = i \oplus v$. If $k < j$, then $v = i \oplus k$ is in the left set. If $k \geq j$, let $b$ be the highest bit where $i$ and $j$ differ (highest set bit of $i \oplus j$). Since $v < i \oplus j$, bit $b$ of $v$ is 0. This forces bit $b$ of $i$ to be 1 and bit $b$ of $j$ to be 0 (otherwise $k < j$, contradicting $k \geq j$). Then $l = v \oplus j$ has bit $b$ = 0 while bit $b$ of $i$ = 1, with all higher bits matching, so $l < i$, and $v = l \oplus j$ appears in the above set.

Since all values $0, \ldots, i \oplus j - 1$ are present and $i \oplus j$ is absent, mex = $i \oplus j$.

This is precisely the Sprague-Grundy value for position $(i, j)$ in the impartial game of moving toward $(0,0)$, where each step decreases $i$ or $j$.

### Algorithm

**Direct computation:** For each cell $(i, j)$, output $i \oplus j$.

**Iterative doubling (used in code):** Precompute a $128 \times 128$ grid by starting from a $2 \times 2$ base and repeatedly doubling. From a $k \times k$ grid (where $k$ is a power of 2), build a $2k \times 2k$ grid: top-left unchanged, top-right and bottom-left = top-left $+ k$, bottom-right = clone of top-left (since $(i+k) \oplus (j+k) = i \oplus j$ when $k$ is a power of 2).

### Example

$n = 5$:

```
0 1 2 3 4
1 0 3 2 5
2 3 0 1 6
3 2 1 0 7
4 5 6 7 0
```

Check cell $(1,2)$: left = $\{1,0\}$, above = $\{2\}$, set = $\{0,1,2\}$, mex = 3 = $1 \oplus 2$. $\checkmark$

## Complexity

- **Time:** $O(n^2)$
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Mex%20Grid%20Construction.cpp)
