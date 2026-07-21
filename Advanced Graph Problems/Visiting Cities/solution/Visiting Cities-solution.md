# Visiting Cities - Solution

**ID:** 1203 | **URL:** https://cses.fi/problemset/task/1203

## Approach

### Problem Restatement

Find all cities that lie on every shortest path from city 1 to city $n$.

### Core idea

Run Dijkstra from 1, then keep only edges $(u, v, c)$ where $\text{dist}[v] = \text{dist}[u] + c$ — these form the shortest-path DAG containing all optimal routes. A city is certainly visited iff it **dominates** $n$ in this DAG (every path from 1 to $n$ passes through it). Build the **dominator tree** via Lengauer-Tarjan: $u$ dominates $v$ iff $u$ is an ancestor of $v$ in the tree, so the answer is exactly the vertices on the path from 1 to $n$ in the dominator tree.

### Algorithm

1. **Dijkstra** from 1 to compute $\text{dist}[u]$.
2. **Build shortest-path DAG:** keep edge $(u, v, c)$ iff $\text{dist}[v] = \text{dist}[u] + c$.
3. **Lengauer-Tarjan** on the DAG:
   - DFS from 1, assign DFS order numbers.
   - Process vertices in reverse DFS order, compute semi-dominators ($sdom$) using DSU with path compression.
   - For each vertex $w$: if $sdom[w] = sdom[\text{Find}(w)]$ then $\text{dom}[w] = sdom[w]$, else $\text{dom}[w] = \text{Find}(w)$.
   - Final pass: if $sdom[w] \ne \text{dom}[w]$, set $\text{dom}[w] = \text{dom}[\text{dom}[w]]$.
4. **Build dominator tree** from edges $(\text{dom}[w], w)$.
5. **Trace** path from $n$ back to 1 in the dominator tree — these are the certainly-visited cities.

### Example

5 cities, flights: 1→2 (3), 1→3 (4), 2→3 (1), 2→4 (5), 3→4 (1), 4→5 (8).

Dijkstra: dist = [0, 3, 4, 5, 13]. Edge 2→4 removed (dist[2]+5=8≠5). DAG: 1→2, 1→3, 2→3, 3→4, 4→5.

Dominator tree: 1→2, 1→3, 3→4, 4→5. Path 1→5: {1, 3, 4, 5}. City 2 is not certainly visited (can bypass via 1→3).

## Complexity

- **Time:** $O((n + m) \log n)$ — Dijkstra $O(m \log n)$, Lengauer-Tarjan $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Visiting%20Cities.cpp)
