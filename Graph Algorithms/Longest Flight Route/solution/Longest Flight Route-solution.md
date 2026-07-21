# Longest Flight Route - Solution

**ID:** 1680 | **URL:** https://cses.fi/problemset/task/1680

## Approach

### Problem Restatement

Given a DAG with $n$ vertices and $m$ directed edges, find the longest path (in terms of vertex count) from vertex 1 to vertex $n$, or report "IMPOSSIBLE" if no such path exists.

### Core idea

Since the graph is a DAG, the longest path problem — which is NP-hard in general graphs — becomes tractable via dynamic programming. Define $dp[u]$ as the maximum number of vertices on a path from $u$ to $n$:

$$dp[u] = \max_{(u,v) \in E}(dp[v] + 1), \quad dp[n] = 1$$

If $u$ cannot reach $n$, $dp[u] = -\infty$. The formula is correct because every path from $u$ to $n$ starts with some edge $(u, v)$ then continues optimally from $v$; taking the maximum over all choices of $v$ yields the longest path. Since the graph is a DAG, no cycles exist so memoization via DFS is safe — each state depends only on states closer to $n$ in topological order.

### Algorithm

1. DFS from vertex 1 with memoization. At each vertex $u$:
   - If $u = n$: set $dp[u] = 1$.
   - Otherwise: initialize $dp[u] = -\infty$, then for each neighbor $v$, update $dp[u] = \max(dp[u], dp[v] + 1)$ and record $\text{trace}[u] = v$ on update.
2. If $dp[1] \le 0$: no path exists, print "IMPOSSIBLE".
3. Otherwise: print $dp[1]$, then follow `trace` from 1 to $n$ to reconstruct the path.

### Example

Input:
```
5 5
1 2
2 5
1 3
3 4
4 5
```

DFS computes bottom-up:
- $dp[5] = 1$
- $dp[2] = dp[5] + 1 = 2$, trace[2] = 5
- $dp[4] = dp[5] + 1 = 2$, trace[4] = 5
- $dp[3] = dp[4] + 1 = 3$, trace[3] = 4
- $dp[1] = \max(dp[2]+1, dp[3]+1) = \max(3, 4) = 4$, trace[1] = 3

Path: $1 \to 3 \to 4 \to 5$ (4 cities).

Output:
```
4
1 3 4 5
```

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Longest%20Flight%20Route.cpp)
