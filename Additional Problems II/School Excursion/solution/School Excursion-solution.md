# School Excursion - Solution

**ID:** 1706 | **URL:** https://cses.fi/problemset/task/1706

## Problem Statement

A group of $n$ children is visiting Helsinki. There are two attractions: Korkeasaari (zoo) or Linnanmäki (amusement park). There are $m$ pairs of children who want to visit the same attraction. Find all possible values for the number of children visiting Korkeasaari.

## Approach

### Step 1: Build connected components

The "same attraction" constraints create connected components on a graph. If $a$ and $b$ are in the same component, there exists a path $a = v_0, v_1, \ldots, v_k = b$ where each adjacent pair must visit the same place, so by induction the entire component must visit the same attraction.

Use DSU (Union-Find) to find all connected components. Let the component sizes be $s_1, s_2, \ldots, s_c$.

### Step 2: Subset sum via Bitset

The problem reduces to: given sizes $s_1, s_2, \ldots, s_c$, find all achievable sums by selecting a subset of components to visit Korkeasaari.

Solve with **bitset**: start with $B = 1$ (bit 0 set). For each size $s_i$: $B \leftarrow B \mid (B \ll s_i)$. After processing components $1, \ldots, i$, bit $j$ of $B$ is 1 iff there exists a subset of $\{s_1, \ldots, s_i\}$ with sum $j$ (proved by induction: adding $s_{i+1}$ makes both old sum $j$ and $j + s_{i+1}$ achievable). Result: bit $j$ of $B$ is 1 iff $j$ children can visit Korkeasaari.

### Step 3: Binary grouping optimization (Optional)

If many components share the same size $s$, instead of shifting the bitset $k$ times, use **binary grouping**: decompose $k$ into $1 + 2 + 4 + \ldots + 2^{\lfloor \log_2 k \rfloor} + r$. Every integer from 0 to $k$ can be represented as a subset sum of these groups (analogous to binary representation), so the decomposition is correct. This reduces from $k$ shifts to $O(\log k)$ shifts.

For $N = 10^5$, plain bitset is usually fast enough, but binary grouping provides additional optimization when many components share the same size.

### Example

$n = 5, m = 3$. Pairs: (1,2), (2,3), (1,5).

Components: $\{1, 2, 3, 5\}$ size 4, $\{4\}$ size 1.

Initial bitset: `000001`. After size 4: `010001`. After size 1: `110011`.

Bits 1..5: `10011`, meaning 1, 4, or 5 children can visit Korkeasaari.

## Complexity

- **Time:** $O(n^2 / 64)$ with plain bitset, or $O(n^2 / 64 \cdot \log n)$ with binary grouping.
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/School%20Excursion.cpp)
