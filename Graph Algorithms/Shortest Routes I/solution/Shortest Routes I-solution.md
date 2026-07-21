# Shortest Routes I - Solution

**ID:** 1671 | **URL:** https://cses.fi/problemset/task/1671

## Approach

### Problem Restatement

Given a directed weighted graph with $n$ vertices and $m$ edges, where all edge weights are non-negative, find the shortest distance from vertex 1 to every other vertex.

### Core Idea

This is the single-source shortest path problem with non-negative weights, solved by **Dijkstra's algorithm**. The algorithm maintains a distance array $d[u]$ and a min-priority queue. It works by greedily extracting the vertex with the smallest tentative distance and relaxing its outgoing edges.

At each step, extract vertex $u$ with minimum $d[u]$ from the priority queue. For each edge $u \to v$ with weight $c$: if $d[v] > d[u] + c$, update $d[v] = d[u] + c$ and push the new distance into the priority queue. Vertices that cannot be reached from vertex 1 retain their initial value of $+\infty$.

**Correctness.** When vertex $u$ is extracted from the priority queue, $d[u]$ is the true shortest distance from vertex 1 to $u$. Suppose not: then there exists a shorter path $1 \leadsto u$ with length $d^* < d[u]$. On this path, let $v_i$ be the first vertex not yet processed. When $v_{i-1}$ was processed, $d[v_i]$ was updated to at most the true shortest distance to $v_i$. Since all weights are non-negative, $d[v_i] \leq d^* < d[u]$, contradicting that $u$ was extracted before $v_i$ (the priority queue should have extracted $v_i$ first).

### Algorithm

1. Initialize: $d[1] = 0$, $d[u] = +\infty$ for all $u \neq 1$. Push $(0, 1)$ into the priority queue.
2. While the priority queue is not empty:
   - Extract $(d_u, u)$ with minimum distance.
   - For each edge $u \to v$ with weight $c$: if $d[v] > d[u] + c$, update $d[v] = d[u] + c$ and push $(d[v], v)$ into the queue.
3. Output $d[1], d[2], \ldots, d[n]$.

### Example

Input:
```
3 4
1 2 6
1 3 2
3 2 3
1 3 4
```

Edges: $1 \to 2$ (6), $1 \to 3$ (2), $3 \to 2$ (3), $1 \to 3$ (4).

- Initialize: $d[1] = 0$, $d[2] = d[3] = \infty$. Queue: $\{(0, 1)\}$.
- Extract 1 ($d = 0$): relax $1 \to 2$: $d[2] = 6$; relax $1 \to 3$ (w=2): $d[3] = 2$; relax $1 \to 3$ (w=4): $d[3] = 2 < 4$, skip. Queue: $\{(2, 3), (6, 2)\}$.
- Extract 3 ($d = 2$): relax $3 \to 2$: $d[2] = \min(6, 2 + 3) = 5$. Queue: $\{(5, 2)\}$.
- Extract 2 ($d = 5$): no outgoing edges. Queue: empty.

Result: $d = [0, 5, 2]$.

Output:
```
0 5 2
```

## Complexity

- **Time:** $O((n + m) \log n)$ — each vertex and edge is processed at most once; priority queue operations take $O(\log n)$.
- **Space:** $O(n + m)$ — adjacency list and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Shortest%20Routes%20I.cpp)
