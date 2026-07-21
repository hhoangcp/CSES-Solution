# Permutation Order - Solution

**ID:** 3397 | **URL:** https://cses.fi/problemset/task/3397

## Approach

### Problem Restatement

Process two types of queries:
1. Given $n$ and $k$, find the $k$-th permutation (lexicographic order) of $\{1, 2, \ldots, n\}$.
2. Given $n$ and a permutation, find its rank $k$.

### Core idea

Every permutation of $n$ elements can be uniquely encoded as a sequence $(d_0, d_1, \ldots, d_{n-1})$ called the **factoradic**, where $0 \le d_i \le n - 1 - i$ and $d_i$ counts how many unused elements are smaller than the element at position $i$. The rank $k$ (0-indexed) decomposes as:

$$k = d_0 \cdot (n-1)! + d_1 \cdot (n-2)! + \cdots + d_{n-1} \cdot 0!$$

This works because fixing a prefix of $i+1$ elements leaves $(n-1-i)!$ arrangements of the remaining elements. So if there are $c_i$ unused elements smaller than the one placed at position $i$, exactly $c_i \cdot (n-1-i)!$ permutations are skipped.

**Type 1 (rank → permutation):** Decrement $k$ by 1 (convert to 0-indexed). For each position $i$: compute $d_i = \lfloor k / (n-1-i)! \rfloor$, update $k \leftarrow k \bmod (n-1-i)!$, then select the $d_i$-th unused element (0-indexed).

**Type 2 (permutation → rank):** For each position $i$: count $c_i$ unused elements smaller than $a[i]$, add $c_i \cdot (n-1-i)!$ to the answer, mark $a[i]$ as used. Finally add 1 (convert to 1-indexed).

### Algorithm

1. Precompute factorials up to $20!$.
2. For Type 1 queries: apply the factoradic decomposition and select unused elements.
3. For Type 2 queries: accumulate $c_i \cdot (n-1-i)!$ for each position.

### Example

$n = 4$, factorials: $3! = 6, 2! = 2, 1! = 1, 0! = 1$.

**Type 1: $k = 2$** (0-indexed: $k = 1$). Unused: $\{1,2,3,4\}$.

| $i$ | $d_i = \lfloor k / (n{-}1{-}i)! \rfloor$ | $k$ after mod | Element |
|-----|------------------------------------------|---------------|---------|
| 0 | $\lfloor 1/6 \rfloor = 0$ | 1 | 1st unused = **1** |
| 1 | $\lfloor 1/2 \rfloor = 0$ | 1 | 1st unused = **2** |
| 2 | $\lfloor 1/1 \rfloor = 1$ | 0 | 2nd unused = **4** |
| 3 | 0 | 0 | last = **3** |

Result: `1 2 4 3` $\checkmark$

**Type 2: permutation `1 2 4 3`**. $ans = 0$.

| $i$ | $a[i]$ | $c_i$ (unused < $a[i]$) | Contribution | $ans$ |
|-----|--------|--------------------------|-------------|-------|
| 0 | 1 | 0 | $0 \cdot 6$ | 0 |
| 1 | 2 | 0 | $0 \cdot 2$ | 0 |
| 2 | 4 | 1 (element 3) | $1 \cdot 1$ | 1 |
| 3 | 3 | 0 | $0 \cdot 1$ | 1 |

Rank = $1 + 1 = 2$ $\checkmark$

## Complexity

- **Time:** $O(n^2)$ per query (linear scan for unused elements)
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Permutation%20Order.cpp)
