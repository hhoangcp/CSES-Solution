# Game Routes - Solution

**ID:** 1681 | **URL:** https://cses.fi/problemset/task/1681

## Approach

### Problem Restatement

Given a DAG with $n$ vertices and $m$ edges, count the number of distinct paths from vertex 1 to vertex $n$. Output the result modulo $10^9 + 7$.

### Core Idea

Define $dp[u]$ as the number of paths from vertex $u$ to vertex $n$. The recurrence is:

$$dp[u] = \sum_{(u,v) \in E} dp[v] \pmod{10^9+7}$$

This is correct because every path from $u$ to $n$ must start with some edge $(u, v)$ then continue from $v$ to $n$. Since the graph has no cycles, partitioning paths by their first edge is disjoint and complete — each path is counted exactly once in exactly one summand $dp[v]$.

Base case: $dp[n] = 1$ (the empty path at the destination).

Compute using DFS with memoization: since the DAG has no cycles, DFS won't loop. When visiting vertex $u$, recursively compute $dp[v]$ for each unvisited neighbor $v$ first, then sum them. Mark `visited[u] = true` after computation so each vertex is processed exactly once. The DAG structure guarantees $dp[v]$ is always computed before being used by its predecessors (because edge $u \to v$ means $v$ is explored first by DFS).

### Algorithm

1. Initialize `visited[] = false`, `dp[] = 0`.
2. DFS from vertex 1:
   - If $u = n$: set $dp[u] = 1$ and return.
   - For each neighbor $v$: if not visited, recurse; then add $dp[v]$ to $dp[u]$ modulo $10^9+7$.
   - Mark `visited[u] = true`.
3. Output $dp[1]$.

### Example

Input:
```
4 5
1 2
2 4
1 3
3 4
1 4
```

DFS from 1:
- Recurse to 2 → recurse to 4: $dp[4] = 1$. Back: $dp[2] = 1$.
- Recurse to 3 → 4 already visited: $dp[3] = dp[4] = 1$.
- 4 already visited: $dp[1] = dp[2] + dp[3] + dp[4] = 1 + 1 + 1 = 3$.

3 paths: $1 \to 2 \to 4$, $1 \to 3 \to 4$, $1 \to 4$.

Output: `3`

## Complexity

- **Time:** $O(n + m)$ — each vertex and edge is processed exactly once.
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Game%20Routes.cpp)
