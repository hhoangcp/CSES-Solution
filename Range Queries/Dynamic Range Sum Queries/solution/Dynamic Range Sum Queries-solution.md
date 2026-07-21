# Dynamic Range Sum Queries - Solution

**ID:** 1648 | **URL:** https://cses.fi/problemset/task/1648

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries:
1. Update the value at position $k$ to $u$.
2. Compute the sum of values in range $[a, b]$.

### Core idea

We need both point updates and range sum queries. A **segment tree** supports both in $O(\log n)$. Each leaf stores the array value at that position; each internal node stores the sum of its two children. Since addition is associative — $\sum_{i=l}^{r} x_i = \bigl(\sum_{i=l}^{mid} x_i\bigr) + \bigl(\sum_{i=mid+1}^{r} x_i\bigr)$ — internal nodes correctly combine their children's results, and this invariant is preserved after each update by propagating from the modified leaf back to the root.

The neutral element for addition is 0. Since values can reach $10^9$ and a range can have up to $2 \cdot 10^5$ elements, the sum can reach $2 \cdot 10^{14}$, requiring `long long` for segment tree nodes.

### Algorithm

1. **Build:** Insert each array value via point update (initializing all nodes to 0 first).
2. **Point update** ($x_k = u$): Recurse to leaf $k$, set it to $u$, then propagate up: each ancestor is recomputed as left child + right child. Only $O(\log n)$ nodes on the root-to-leaf path change.
3. **Range query** (sum on $[a, b]$): Recurse from the root. At a node managing $[l, r]$:
   - If $[l, r]$ is disjoint from $[a, b]$: return 0 (neutral).
   - If $[l, r] \subseteq [a, b]$: return the stored value.
   - Otherwise: return query(left child) + query(right child).

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 3 1
2 1 4
```

- Query sum $[1,4]$: $3 + 2 + 4 + 5 = 14$.
- Query sum $[5,6]$: $1 + 1 = 2$.
- Update position 3 to 1: array becomes $[3, 2, 1, 5, 1, 1, 5, 3]$.
- Query sum $[1,4]$: $3 + 2 + 1 + 5 = 11$.

Output:
```
14
2
11
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Dynamic%20Range%20Sum%20Queries.cpp)
