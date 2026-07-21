# Dynamic Range Minimum Queries - Solution

**ID:** 1649 | **URL:** https://cses.fi/problemset/task/1649

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries:
1. Update the value at position $k$ to $u$.
2. Find the minimum value in range $[a, b]$.

### Core idea

We need both point updates and range minimum queries. A **segment tree** supports both in $O(\log n)$. Each leaf stores the array value at that position; each internal node stores $\min$(left child, right child). Since $\min$ is associative — $\min_{i=l}^{r} x_i = \min\bigl(\min_{i=l}^{mid} x_i, \min_{i=mid+1}^{r} x_i\bigr)$ — internal nodes correctly combine their children's results, and this invariant is preserved after each update by propagating from the modified leaf back to the root.

The neutral element for $\min$ is $+\infty$; we use $10^9+7$ since all values are $\le 10^9$.

### Algorithm

1. **Build:** Initialize all nodes to $10^9+7$, then insert each array value via point update.
2. **Point update** ($x_k = u$): Recurse to leaf $k$, set it to $u$, then propagate up: each ancestor is recomputed as $\min$(left child, right child). Only $O(\log n)$ nodes on the root-to-leaf path change.
3. **Range query** ($\min$ on $[a, b]$): Recurse from the root. At a node managing $[l, r]$:
   - If $[l, r]$ is disjoint from $[a, b]$: return $10^9+7$ (neutral).
   - If $[l, r] \subseteq [a, b]$: return the stored value.
   - Otherwise: return $\min$(query left child, query right child).

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 1 4
2 5 6
1 2 3
2 1 4
```

- Query $\min[1,4]$: $\min(3, 2, 4, 5) = 2$.
- Query $\min[5,6]$: $\min(1, 1) = 1$.
- Update position 2 to 3: array becomes $[3, 3, 4, 5, 1, 1, 5, 3]$. Leaf $[2]$ changes from 2 to 3; parent $[1,2]$ from $\min(3,2)=2$ to $\min(3,3)=3$; grandparent $[1,4]$ from 2 to 3.
- Query $\min[1,4]$: $\min(3, 3, 4, 5) = 3$.

Output:
```
2
1
3
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Dynamic%20Range%20Minimum%20Queries.cpp)
