# Graph Girth - Solution

**ID:** 1707 | **URL:** https://cses.fi/problemset/task/1707

## Approach

### Problem Restatement

Given an undirected graph, determine its girth -- the length of the shortest cycle. If there are no cycles, output $-1$.

### Core idea

Run BFS from every node. When BFS from source $s$ encounters edge $\{u,v\}$ where both endpoints are already visited and it's not a tree edge (i.e., $v \neq \text{lab}[u]$ and $u \neq \text{lab}[v]$), a cycle is found with length $\text{dist}[u] + \text{dist}[v] + 1$. The shortest cycle is always detected because BFS from a node on that cycle finds shortest paths to all other cycle nodes, and the connecting edge closes the cycle at the correct length. The `lab` check excludes tree edges (which don't form cycles in a simple graph).

### Algorithm

1. For each source node $s$ from 1 to $n$:
   - Run BFS from $s$, computing `dist[v]` and `lab[v]`.
   - When processing node $u$ and finding neighbor $v$ already visited:
     - If $v \neq \text{lab}[u]$ and $u \neq \text{lab}[v]$ (not a tree edge), update `ans = min(ans, dist[u] + dist[v] + 1)`.
2. If `ans` is still $\infty$, output $-1$; otherwise output `ans`.

### Example

$n=5$, edges: 1-2, 1-3, 2-4, 2-5, 3-4, 4-5.

BFS from 2: dist = [1, 0, 2, 1, 1]. Edge 4-5: $\text{dist}[4]=1$, $\text{dist}[5]=1$, cycle = 3.

Result: 3.

## Complexity

- **Time:** $O(n(n + m))$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Graph%20Girth.cpp)
