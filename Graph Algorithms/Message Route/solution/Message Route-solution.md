# Message Route - Solution

**ID:** 1667 | **URL:** https://cses.fi/problemset/task/1667

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, find the shortest path from vertex 1 to vertex $n$ (fewest edges), or report "IMPOSSIBLE" if no path exists.

### Core idea

BFS on an unweighted graph finds the shortest path. When exploring layer by layer ($L_0 = \{\text{source}\}$, $L_k$ = unvisited neighbors of $L_{k-1}$), each vertex is first discovered at its minimum distance from the source — no shorter path can exist because any such path would have placed the vertex in an earlier layer. If vertex 1 is unreachable from vertex $n$, no path exists.

BFS starts from vertex $n$ (destination) toward vertex 1 (source). This makes tracing convenient: following `trace` pointers from vertex 1 to vertex $n$ produces the path in the correct source-to-destination order without reversal.

### Algorithm

1. Run BFS from vertex $n$. For each discovered vertex $v$, store its parent (`trace[v]`) and distance from $n$ (`dist[v]`).
2. If vertex 1 was never visited, print "IMPOSSIBLE".
3. Otherwise, print `dist[1]` and trace the path from 1 to $n$ via `trace`.

### Example

Input:
```
5 5
1 2
1 3
1 4
2 3
5 4
```

BFS from vertex 5:
- $L_0 = \{5\}$, dist[5] = 1
- $L_1 = \{4\}$, dist[4] = 2, trace[4] = 5
- $L_2 = \{1\}$, dist[1] = 3, trace[1] = 4
- $L_3 = \{2, 3\}$, dist[2] = 4, trace[2] = 1; dist[3] = 4, trace[3] = 1

Trace from vertex 1: $1 \to 4 \to 5$.

Output:
```
3
1 4 5
```

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Message%20Route.cpp)
