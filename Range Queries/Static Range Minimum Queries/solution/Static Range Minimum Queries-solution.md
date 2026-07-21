# Static Range Minimum Queries - Solution

**ID:** 1647 | **URL:** https://cses.fi/problemset/task/1647

## Approach

### Problem Restatement

Given a static array of $n$ integers, process $q$ queries: what is the minimum value in range $[a, b]$?

### Core idea

Use a **segment tree** for range minimum queries. Each internal node manages a segment $[l, r]$ and stores $\min_{i \in [l,r]} x_i$. Since $[l, r] = [l, mid] \cup [mid+1, r]$ (disjoint union), the minimum decomposes:

$$\min_{i \in [l,r]} x_i = \min\left(\min_{i \in [l,mid]} x_i,\min_{i \in [mid+1,r]} x_i\right)$$

So each node's value equals $\min$(left child, right child). This invariant holds by construction: leaves store individual elements, and internal nodes aggregate from children.

To query $\min$ on $[a, b]$, recurse from root: if the node's segment is fully inside $[a, b]$, return its stored value; if completely outside, return $+\infty$ (neutral element for min); otherwise, recurse into both children and take $\min$. The query partitions $[a, b]$ into $O(\log n)$ disjoint segments, each with a correct stored minimum.

### Algorithm

1. **Build** segment tree: leaves store $x_i$, internal nodes store $\min$(left, right).
2. **Query** $[a, b]$: recurse from root, taking $\min$ of relevant sub-segments.

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 4
5 6
1 8
3 3
```

Array: $[3, 2, 4, 5, 1, 1, 5, 3]$. Segment tree: root $[1,8] = 1$, $[1,4] = 2$, $[5,8] = 1$, $[1,2] = 2$, $[3,4] = 4$, $[5,6] = 1$, $[7,8] = 3$.

- Query $[2, 4]$: $\min(2, 4, 5) = 2$.
- Query $[5, 6]$: $\min(1, 1) = 1$.
- Query $[1, 8]$: $\min = 1$.
- Query $[3, 3]$: $x_3 = 4$.

Output:
```
2
1
1
4
```

## Complexity

- **Time:** $O(n + q \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Static%20Range%20Minimum%20Queries.cpp)
