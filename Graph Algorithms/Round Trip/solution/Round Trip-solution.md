# Round Trip - Solution

**ID:** 1669 | **URL:** https://cses.fi/problemset/task/1669

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, find a simple cycle of length $\geq 3$, or report "IMPOSSIBLE" if none exists.

### Core idea

Run DFS from each unvisited vertex, maintaining a stack $S$ of vertices on the current DFS path and an array `in[u]` marking whether $u$ is on that path. When DFS at vertex $u$ encounters a neighbor $v$ that is visited, on the current path (`in[v] = true`), and is not the direct parent of $u$, a **back edge** is found — the path from $v$ to $u$ along the stack plus edge $(u, v)$ forms a cycle.

The cycle is valid because vertices on the stack are distinct (DFS never revisits), and the parent check ensures $v$ is not the vertex immediately before $u$, so the path has length $\geq 2$ and the cycle has length $\geq 3$. Conversely, if the graph contains a cycle, DFS will encounter a back edge: when DFS first reaches the cycle, it follows tree edges around it and eventually sees an edge back to an ancestor still on the path. If DFS completes without back edges, the graph is a forest with no cycles.

### Algorithm

1. For each unvisited vertex, run DFS with a stack tracking the current path.
2. At vertex $u$, for each neighbor $v$: if $v$ is visited, `in[v]` is true, and $v$ is not the parent of $u$ — cycle found. Collect vertices from stack top down to $v$, add $v$ to close the cycle, output, and exit.
3. If no cycle found after all DFS calls, output "IMPOSSIBLE".

### Example

Input:
```
5 6
1 3
1 2
5 3
1 5
2 4
4 5
```

DFS from 1: $S = [1, 3, 5]$. From 5, neighbor 1 is visited, `in[1] = true`, and 1 is not the parent of 5. Cycle detected. Collect from stack: $1, 5, 3, 1$.

Output:
```
4
3 5 1 3
```

(Any valid cycle is accepted.)

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Round%20Trip.cpp)
