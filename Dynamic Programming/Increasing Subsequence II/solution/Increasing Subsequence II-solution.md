# Increasing Subsequence II - Solution

**ID:** 1748 | **URL:** https://cses.fi/problemset/task/1748

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of increasing subsequences. Subsequences with the same values but at different positions are counted separately. Output modulo $10^9 + 7$.

### Core Idea

Let $f(i)$ be the number of increasing subsequences ending at position $i$. Then:

$$f(i) = 1 + \sum_{\substack{j < i \\ x_j < x_i}} f(j)$$

The $1$ accounts for the subsequence consisting of $x_i$ alone; the sum extends every increasing subsequence ending at some $j < i$ with $x_j < x_i$ by appending $x_i$. The total answer is $\sum_{i=1}^{n} f(i)$.

**Why BIT with coordinate compression works:** We need a data structure that, for each $x_i$, quickly computes the sum of $f(j)$ over all previously processed $j$ with $x_j < x_i$. A Binary Indexed Tree (BIT) supports prefix-sum queries and point updates in $O(\log n)$, but requires indices in $[1, n]$. Coordinate compression maps distinct values to ranks 1 through $N$ ($N \le n$), preserving order so that $\text{rank}(x_j) < \text{rank}(x_i) \iff x_j < x_i$.

**Why `Query(rank(x_i) - 1)` instead of `Query(rank(x_i))`:** We need strictly increasing subsequences ($x_j < x_i$, not $\le$). Using `rank(x_i) - 1` excludes elements equal to $x_i$, ensuring we only sum over values less than $x_i$.

**Correctness (invariant):** After processing element $i$, `BIT[p]` stores the sum of $f(j)$ for all $j \le i$ with $\text{rank}(x_j) \le p$. This holds by induction: initially BIT is all zeros; when processing $i$, `Query(rank(x_i) - 1)` correctly returns $\sum_{j<i, x_j < x_i} f(j)$ (compression preserves order), and `Update(rank(x_i), f(i))` adds $f(i)$ at the right position, maintaining the invariant.

### Algorithm

1. Coordinate-compress distinct values of the array to ranks $1 \ldots N$.
2. For each $i$ from 1 to $n$:
   - $f(i) = (\text{Query}(\text{rank}(x_i) - 1) + 1) \bmod (10^9 + 7)$
   - $\text{Update}(\text{rank}(x_i),\ f(i))$
   - $\text{ans} = (\text{ans} + f(i)) \bmod (10^9 + 7)$

### Example

Input: $n = 3$, $x = [2, 1, 3]$. Coordinate compression: $\{1, 2, 3\} \to \text{ranks}\ \{1, 2, 3\}$.

| $i$ | $x_i$ | rank | Query(rank−1) | $f(i)$ | ans |
|-----|-------|------|---------------|--------|-----|
| 1 | 2 | 2 | Query(1) = 0 | 1 | 1 |
| 2 | 1 | 1 | Query(0) = 0 | 1 | 2 |
| 3 | 3 | 3 | Query(2) = 1 + 1 = 2 | 3 | 5 |

The 5 increasing subsequences: $[2]$, $[1]$, $[3]$, $[2,3]$, $[1,3]$.

## Complexity

- **Time:** $O(n \log n)$ — coordinate compression $O(n \log n)$ + $n$ BIT operations each $O(\log n)$
- **Space:** $O(n)$ — for BIT and coordinate compression array

## Code (C++)

[Solution Code](../code/Increasing%20Subsequence%20II.cpp)
