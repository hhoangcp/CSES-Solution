# Planets and Kingdoms - Solution

**ID:** 1683 | **URL:** https://cses.fi/problemset/task/1683

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, find all strongly connected components (SCCs) — maximal sets of vertices where each vertex can reach every other vertex in the set. Output the number of SCCs and each vertex's component label.

### Core idea

A "kingdom" is exactly an SCC. Tarjan's algorithm finds all SCCs in a single DFS using two values per vertex:

- $\text{num}[u]$: discovery order of $u$.
- $\text{low}[u]$: smallest $\text{num}$ reachable from $u$ via tree edges and at most one back edge to an ancestor still on the stack.

When $\text{low}[u] \geq \text{num}[u]$, vertex $u$ is the root of an SCC: no descendant of $u$ reaches an ancestor of $u$ (otherwise $\text{low}[u]$ would be smaller), so the vertices from the top of the stack down to $u$ form a maximal strongly connected set. Every vertex is pushed onto the stack when discovered and popped exactly once when its SCC root is found, so all SCCs are detected. The condition $\text{low}[u] < \text{num}[u]$ means $u$ can reach an ancestor — it belongs to the same SCC as that ancestor and will be collected when the ancestor's SCC root is found.

### Algorithm

1. DFS from each unvisited vertex $u$: set $\text{num}[u] = ++$time, $\text{low}[u] = \infty$, push $u$ onto stack.
2. For each edge $(u, v)$:
   - If $v$ is unvisited: recurse, then $\text{low}[u] = \min(\text{low}[u], \text{low}[v])$.
   - If $v$ is visited but still on stack: $\text{low}[u] = \min(\text{low}[u], \text{num}[v])$.
3. After exploring all edges from $u$: if $\text{low}[u] \geq \text{num}[u]$, pop vertices from stack to $u$ and assign them the next SCC label.
4. Output the number of SCCs and each vertex's label.

### Example

Input:
```
5 6
1 2
2 3
3 1
3 4
4 5
5 4
```

SCCs: $\{1, 2, 3\}$ and $\{4, 5\}$.

Output:
```
2
1 1 1 2 2
```

(Any valid labeling is accepted.)

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Planets%20and%20Kingdoms.cpp)
