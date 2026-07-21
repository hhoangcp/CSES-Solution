# Subarray Sum Queries II - Solution

**ID:** 3226 | **URL:** https://cses.fi/problemset/task/3226

## Approach

### Problem Restatement

Given a static array of $n$ integers, process $q$ queries: compute the maximum subarray sum in range $[a, b]$. Empty subarray (sum 0) is allowed.

### Core idea

This extends *Subarray Sum Queries* from the entire array to arbitrary ranges. Use the same segment tree with 4 values per node (Sum, Left, Right, Max) and the same merge formulas:

$$\text{Sum} = L.\text{Sum} + R.\text{Sum}$$
$$\text{Left} = \max(L.\text{Left}, L.\text{Sum} + R.\text{Left})$$
$$\text{Right} = \max(R.\text{Right}, R.\text{Sum} + L.\text{Right})$$
$$\text{Max} = \max(L.\text{Max}, R.\text{Max}, L.\text{Right} + R.\text{Left})$$

The key difference is that the `query` function must return a struct Data (not a single number), so that results from different segments can be merged. This is necessary because the optimal subarray may cross the boundary between two segments — we cannot just take $\max$ of both halves independently.

Merge is **non-commutative** ($\text{merge}(L, R) \neq \text{merge}(R, L)$), so results must be combined left-to-right. The `query` function partitions $[a, b]$ into $O(\log n)$ disjoint segments in order, then sequentially merges them. This is correct because merge is associative: merging segments $D_1, D_2, \ldots, D_k$ left-to-right produces the same result as computing over the entire flat range $[a, b]$.

Output: $\max(0, \text{result.Max})$ to handle empty subarrays.

### Algorithm

1. **Build** segment tree with 4 values per node. Leaves: Sum = Max = Left = Right = $x_i$.
2. **Query** $[a, b]$: recurse from root, collecting Data structs from fully-covered nodes, merging them left-to-right. Return $\max(0, \text{result.Max})$.

### Example

Input:
```
8 4
2 5 1 -2 3 -1 -7 1
2 4
2 5
6 7
4 8
```

Array: $[2, 5, 1, -2, 3, -1, -7, 1]$.

- Query $[2, 4]$: elements $\{5, 1, -2\}$. Max subarray $= [5, 1] = 6$. Answer $= 6$.
- Query $[2, 5]$: elements $\{5, 1, -2, 3\}$. Max subarray $= [5, 1, -2, 3] = 7$. Answer $= 7$.
- Query $[6, 7]$: elements $\{-1, -7\}$. Max $= -1$, but empty subarray allowed. Answer $= 0$.
- Query $[4, 8]$: elements $\{-2, 3, -1, -7, 1\}$. Max subarray $= [3] = 3$. Answer $= 3$.

Output:
```
6
7
0
3
```

## Complexity

- **Time:** $O(n + q \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Subarray%20Sum%20Queries%20II.cpp)
