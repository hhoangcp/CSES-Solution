# Road Reparation - Solution

**ID:** 1675 | **URL:** https://cses.fi/problemset/task/1675

## Approach

### Problem Restatement

Given an undirected weighted graph with $n$ vertices and $m$ edges, find the minimum total weight of a subset of edges that connects all vertices, or report "IMPOSSIBLE" if the graph is disconnected.

### Core idea

This is the **Minimum Spanning Tree (MST)** problem. Kruskal's algorithm solves it greedily: sort edges by weight, then iterate and select each edge if it connects two different components (no cycle). Use DSU with path compression and union by rank to efficiently check and merge components.

Kruskal is correct because if it selects edge $e = (u,v)$ with $w(e) > w(e')$ for some alternative edge $e'$ that could connect the same components, then $e'$ would have been processed earlier (sorted first) and already selected — contradiction. More formally, given any MST $T^*$, we can exchange each edge of $T \setminus T^*$ with one of $T^* \setminus T$ of equal or greater weight without breaking the spanning tree property, proving $w(T) \leq w(T^*)$.

If fewer than $n - 1$ edges are selected after processing all edges, the graph is disconnected.

### Algorithm

1. Sort all edges by weight in increasing order.
2. Initialize DSU: each vertex is its own component.
3. For each edge $(u, v, c)$ in sorted order:
   - If $\text{Find}(u) \neq \text{Find}(v)$: select the edge, $\text{Union}(u, v)$, add $c$ to the answer.
   - Otherwise: skip (would create a cycle).
4. If fewer than $n - 1$ edges selected: output "IMPOSSIBLE". Otherwise: output the total cost.

### Example

Input:
```
5 6
1 2 3
2 3 5
2 4 2
3 4 8
5 1 7
5 4 4
```

Sorted: $(2,4,2), (1,2,3), (5,4,4), (2,3,5), (5,1,7), (3,4,8)$.

| Edge   | Find(u)≠Find(v)? | Cost |
|--------|-------------------|------|
| (2,4,2)| Yes               | 2    |
| (1,2,3)| Yes               | 5    |
| (5,4,4)| Yes               | 9    |
| (2,3,5)| Yes               | 14   |

4 edges selected = $n - 1$. Stop.

Output:
```
14
```

## Complexity

- **Time:** $O(m \log m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Road%20Reparation.cpp)
