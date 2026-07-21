# Investigation - Solution

**ID:** 1202 | **URL:** https://cses.fi/problemset/task/1202

## Approach

### Problem Restatement

Given a directed graph with positive edge weights, find from vertex 1 to vertex $n$: (1) shortest distance, (2) number of shortest paths mod $10^9+7$, (3) minimum edges in a shortest path, (4) maximum edges in a shortest path.

### Core Idea

Extend Dijkstra to track four values per vertex $u$:
- $d[u]$: shortest distance from 1 to $u$
- $\text{num}[u]$: number of shortest paths from 1 to $u$ (mod $10^9+7$)
- $\text{Min}[u]$: minimum edges in a shortest path to $u$
- $\text{Max}[u]$: maximum edges in a shortest path to $u$

When relaxing edge $u \to v$ with weight $c$, compute $\text{tmp} = d[u] + c$:
- **If $d[v] > \text{tmp}$** (shorter path found): reset $d[v] = \text{tmp}$, $\text{num}[v] = \text{num}[u]$, $\text{Min}[v] = \text{Min}[u] + 1$, $\text{Max}[v] = \text{Max}[u] + 1$.
- **If $d[v] = \text{tmp}$** (another shortest path found): $\text{num}[v] \mathrel{+}= \text{num}[u]$, $\text{Min}[v] = \min(\text{Min}[v], \text{Min}[u] + 1)$, $\text{Max}[v] = \max(\text{Max}[v], \text{Max}[u] + 1)$.

This is correct because Dijkstra processes vertices in non-decreasing distance order with positive weights. When $u$ is processed, $d[u]$ is final — no shorter path to $u$ can exist. Every shortest path to $v$ must pass through some predecessor $u$ with $d[u] + c = d[v]$, so the additivity principle ensures $\text{num}$, $\text{Min}$, and $\text{Max}$ are correctly accumulated from all such predecessors.

### Algorithm

1. Initialize: $d[1] = 0$, $\text{num}[1] = 1$, $\text{Min}[1] = 0$, $\text{Max}[1] = 0$; other vertices: $d = \infty$, $\text{num} = 0$, $\text{Min} = \infty$, $\text{Max} = 0$.
2. Run Dijkstra with a priority queue. When processing vertex $u$, relax each edge $u \to v$ using the rules above.
3. Output $d[n]$, $\text{num}[n]$, $\text{Min}[n]$, $\text{Max}[n]$.

### Example

Input:
```
4 5
1 4 5
1 2 4
2 4 5
1 3 2
3 4 3
```

Dijkstra from vertex 1:
- Process 1 ($d=0$): $d[4]=5$ (1 edge), $d[2]=4$ (1 edge), $d[3]=2$ (1 edge).
- Process 3 ($d=2$): $3\to4$ gives $\text{tmp}=5 = d[4]$. Second shortest path: $\text{num}[4] = 1+1=2$, $\text{Min}[4] = \min(1, 2) = 1$, $\text{Max}[4] = \max(1, 2) = 2$.
- Process 2 ($d=4$): $2\to4$ gives $\text{tmp}=9 > d[4]$, skip.
- Process 4 ($d=5$): no outgoing edges.

Two shortest paths: $1 \to 4$ (1 edge, price 5) and $1 \to 3 \to 4$ (2 edges, price 5).

Output: `5 2 1 2`

## Complexity

- **Time:** $O((n + m) \log n)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Investigation.cpp)
