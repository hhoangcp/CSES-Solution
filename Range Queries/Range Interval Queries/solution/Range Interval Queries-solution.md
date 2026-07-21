# Range Interval Queries - Solution

**ID:** 3163 | **URL:** https://cses.fi/problemset/task/3163

## Approach

### Problem Restatement

Given an array $x$ of $n$ integers, process $q$ queries: how many integers $i$ satisfy $a \le i \le b$ and $c \le x_i \le d$?

### Core idea

Each element at position $i$ with value $x_i$ can be viewed as a point $(i, x_i)$ on a 2D plane. The query asks to count points in rectangle $[a, b] \times [c, d]$ — a classic **2D range counting** problem.

Build a segment tree on the value domain $[1, 10^9]$. **Version $k$** of the tree stores the count of values in each range, considering only elements from position 1 to $k$. By construction, version $k$ = version $k-1$ plus 1 at value $x_k$, so by induction version $k$ correctly stores counts for positions $[1, k]$.

The number of elements in $[a, b]$ with values in $[c, d]$ is then:

$$\text{query}(\text{root}[b], c, d) - \text{query}(\text{root}[a-1], c, d)$$

This subtracts the counts from positions $[1, a-1]$, leaving exactly those in $[a, b]$.

When inserting $x_i$ into version $i$, use **path copying**: create new nodes only on the path from root to the leaf for $x_i$ ($O(\log V)$ nodes), and share all unchanged subtrees with version $i-1$. Since old versions are never modified, shared nodes remain correct.

### Algorithm

1. **Build** persistent segment tree: for each position $i$ from 1 to $n$, create version $i$ by inserting $x_i$ into version $i-1$.
2. **Query** $(a, b, c, d)$: traverse `root[b]` and `root[a-1]` simultaneously on value range $[1, V]$:
   - If segment $[l, r]$ is fully within $[c, d]$: return $\text{seg}[\text{now}] - \text{seg}[\text{old}]$.
   - If completely outside: return 0.
   - Otherwise: recurse into both children and sum.

### Example

Input:
```
8 4
3 2 4 5 1 1 5 3
2 4 2 4
5 6 2 9
1 8 1 5
3 3 4 4
```

Array: $[3, 2, 4, 5, 1, 1, 5, 3]$.

- Query $(2, 4, 2, 4)$: elements $\{2, 4, 5\}$, values in $[2,4]$: $\{2, 4\}$. Answer $= 2$.
- Query $(5, 6, 2, 9)$: elements $\{1, 1\}$, values in $[2,9]$: none. Answer $= 0$.
- Query $(1, 8, 1, 5)$: all 8 elements $\in [1,5]$. Answer $= 8$.
- Query $(3, 3, 4, 4)$: element $\{4\}$, $4 \in [4,4]$. Answer $= 1$.

Output:
```
2
0
8
1
```

## Complexity

- **Time:** $O((n + q) \log V)$ where $V = 10^9$
- **Space:** $O(n \log V)$

## Code (C++)

[Solution Code](../code/Range%20Interval%20Queries.cpp)
