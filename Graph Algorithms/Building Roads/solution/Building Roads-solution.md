# Building Roads - Solution

**ID:** 1666 | **URL:** https://cses.fi/problemset/task/1666

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, find the minimum number of edges to add so that the graph becomes connected, and list those edges.

### Core Idea

The graph consists of $k$ connected components. To merge $k$ components into one, we need exactly $k - 1$ new edges:

- **Lower bound:** Each new edge can reduce the number of components by at most 1 (by connecting two different components). Starting from $k$ components, at least $k - 1$ edges are required to reach 1.
- **Upper bound (construction):** Choose a representative vertex $r_i$ from each component $C_i$. Adding edges $(r_1, r_2), (r_2, r_3), \ldots, (r_{k-1}, r_k)$ merges all $k$ components into one: after edge $(r_i, r_{i+1})$, components $C_1, \ldots, C_{i+1}$ are connected (by induction), so after $k-1$ edges the entire graph is connected.

This construction is not unique — any set of $k - 1$ edges that connects all $k$ components (i.e., forms a spanning tree over the components) is valid.

### Algorithm

1. Run DFS/BFS from each unvisited vertex to identify all connected components. For each component, record a representative vertex (any vertex in the component).
2. Let $r_1, r_2, \ldots, r_k$ be the representatives. Output the $k - 1$ edges $(r_1, r_2), (r_2, r_3), \ldots, (r_{k-1}, r_k)$.

### Example

Input:
```
4 2
1 2
3 4
```

The graph has two connected components:
- Component {1, 2}: representative $r_1 = 2$
- Component {3, 4}: representative $r_2 = 3$

$k = 2$ components, need $k - 1 = 1$ edge: add edge $(2, 3)$.

Output:
```
1
2 3
```

## Complexity

- **Time:** $O(n + m)$ — each vertex and edge is visited exactly once.
- **Space:** $O(n + m)$ — adjacency list and `visited` array.

## Code (C++)

[Solution Code](../code/Building%20Roads.cpp)
