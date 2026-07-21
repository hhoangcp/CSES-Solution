# Forbidden Cities - Solution

**ID:** 1705 | **URL:** https://cses.fi/problemset/task/1705

## Approach

### Problem Restatement

Given a connected undirected graph with $n$ cities and $m$ roads, answer $q$ queries: is there a route from $a$ to $b$ that does not visit city $c$?

### Core idea

Node $c$ separates $a$ from $b$ iff in the DFS tree, $c$ is an ancestor of both $a$ and $b$, and the subtrees containing $a$ and $b$ have no back edges bypassing $c$. By DFS properties on undirected graphs, removing $c$ disconnects the graph into components corresponding to $c$'s children's subtrees. A node $a$ in the subtree of child $v$ of $c$ can reach outside without going through $c$ iff `low[v] < num[c]`, meaning there's a back edge from the subtree to an ancestor of $c$. If both subtrees containing $a$ and $b$ have such bypass edges, they remain connected after removing $c$.

### Algorithm

1. Root the graph via DFS. Compute `num[u]`, `low[u]`, `out[u]`, and binary lifting table `P[u][i]`.
2. Define `in(u, v)`: $u$ is an ancestor of $v$ iff `num[u] <= num[v] && out[v] <= out[u]`.
3. For each query $(a, b, c)$:
   - If $c = a$ or $c = b$: NO.
   - Use binary lifting to find the child of $c$ that is an ancestor of $a$ (or $b$).
   - Check `low[]` of the relevant subtrees: if `low[child] < num[c]`, a bypass exists.

### Example

$n=5, m=6$, edges: 1-2, 1-3, 2-3, 2-4, 3-4, 4-5.

- Query $(1, 4, 2)$: path 1-3-4 avoids 2. YES.
- Query $(3, 5, 4)$: removing 4 disconnects 5. NO.
- Query $(3, 5, 2)$: path 3-4-5 avoids 2. YES.

## Complexity

- **Time:** $O((n + m) \log n + q \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/Forbidden%20Cities.cpp)
