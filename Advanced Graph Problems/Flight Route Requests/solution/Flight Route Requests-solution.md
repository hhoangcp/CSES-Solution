# Flight Route Requests - Solution

**ID:** 1699 | **URL:** https://cses.fi/problemset/task/1699

## Approach

### Problem Restatement

Given $n$ cities and $m$ requests of the form "there must be a route from $a$ to $b$", determine the minimum number of one-way flight connections needed to satisfy all requests.

### Core idea

Partition the request graph into undirected connected components. For each component with $k$ nodes:
- If the subgraph (using only forward edges) is a **DAG**: needs $k-1$ edges (a Hamiltonian path suffices since every later vertex is reachable from earlier ones; optimal since at least $k-1$ edges are needed to connect $k$ nodes).
- If it **contains a cycle**: needs $k$ edges. Build a Hamiltonian cycle through all vertices: within each SCC, an internal cycle uses exactly $|SCC|$ edges (every vertex needs outdegree $\geq 1$, so at least $k$ edges total); connect SCCs in topological order, then connect the last SCC back to the first (possible since the component is weakly connected). Total edges: exactly $k$.

Result: start with $n$, subtract 1 for each DAG component.

### Algorithm

1. DFS traversing both forward and reverse edges to find undirected connected components.
2. For each component, check if the subgraph (forward edges only) is a DAG via Kahn's algorithm (topological sort).
3. If DAG, contribute $k-1$ edges; otherwise, contribute $k$ edges.

### Example

$n=4, m=5$, requests: $1\to2, 2\to3, 2\to4, 3\to1, 3\to4$.

Component: $\{1,2,3,4\}$. Contains cycle $1\to2\to3\to1$, not a DAG. Needs 4 edges.

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Flight%20Route%20Requests.cpp)
