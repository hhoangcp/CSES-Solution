# MST Edge Check - Solution

**ID:** 3407 | **URL:** https://cses.fi/problemset/task/3407

## Approach

### Problem Restatement

Given a connected undirected weighted graph, determine for each edge whether it can appear in some minimum spanning tree (MST).

### Core idea

An edge $e = (u, v, w)$ belongs to some MST iff the maximum-weight edge on the $u$-$v$ path in any fixed MST has weight $\geq w$.

- If `mx_query(u,v) >= w`: the heaviest edge $e'$ on the path has weight $w' \geq w$. Swapping: $T' = T \setminus \{e'\} \cup \{e\}$ is still a spanning tree (removing $e'$ splits the tree, $e$ reconnects it), and $w(T') = w(T) - w' + w \leq w(T)$, so $T'$ is an MST containing $e$.
- If `mx_query(u,v) < w`: $e$ is the heaviest edge on the cycle formed by the $u$-$v$ path plus $e$. By the cycle property, the heaviest edge on any cycle cannot be in any MST.

MST edges always get YES since the edge itself is on the path, so `mx_query >= w`.

### Algorithm

1. Sort edges by weight and build MST using Kruskal's algorithm.
2. Root the MST and precompute binary lifting with max-edge-weight on path to ancestor.
3. For each edge $(u, v, w)$: compute `mx_query(u, v)`. If `>= w`, output YES; else NO.

### Example

$n=5$, MST: (3,4,1), (1,3,2), (2,4,2), (3,5,3).

Edge (1,2,4): path 1-3-4-2, max = 2 < 4 → NO.

MST edges: always YES.

## Complexity

- **Time:** $O(m \log m + n \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/MST%20Edge%20Check.cpp)
