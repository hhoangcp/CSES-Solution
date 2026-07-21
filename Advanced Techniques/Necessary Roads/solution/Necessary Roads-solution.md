# Necessary Roads - Solution

**ID:** 2076 | **URL:** https://cses.fi/problemset/task/2076

## Approach

### Problem Restatement

Given an undirected connected graph with $n$ vertices and $m$ edges, find all *necessary roads* (bridges) — edges whose removal disconnects the graph.

### Core Idea

Use Tarjan's DFS-based algorithm with two arrays:
- `num[u]`: discovery order of vertex $u$ during DFS.
- `low[u]`: lowest discovery order reachable from $u$ or its subtree via back edges (initialized to `num[u]`).

In an undirected DFS, every non-tree edge is a back edge (to an ancestor). Therefore, if a vertex $v$'s subtree has a back edge to some ancestor, that ancestor must also be an ancestor of $v$'s parent $u$. This means:

**Tree edge $(u, v)$ is a bridge iff $low[v] \geq num[v]$:**
- If $low[v] \geq num[v]$: no vertex in $v$'s subtree has a back edge to any ancestor of $v$, so removing $(u, v)$ disconnects $v$'s subtree.
- If $low[v] < num[v]$: some vertex in $v$'s subtree has a back edge to an ancestor of $v$ (which is also an ancestor of $u$), providing an alternative path that bypasses $(u, v)$.

**Back edges are never bridges:** the tree path between the two endpoints provides an alternative route.

### Algorithm

1. Run DFS from each unvisited vertex $u$:
   - Assign `num[u]` = discovery order, `low[u] = num[u]`.
   - For each neighbor $v$:
     - If $v$ is unvisited: recurse into $v$, then update `low[u] = min(low[u], low[v])`.
     - If $v$ is visited and $v$ is not the parent: update `low[u] = min(low[u], num[v])`.
2. For each tree edge $(u, v)$: if $low[v] \geq num[v]$, then $(u, v)$ is a bridge.
3. Output all bridges.

### Example

$n=5$, $m=5$, edges: $(1,2), (1,4), (2,4), (3,5), (4,5)$.

DFS from node 1 (root):

| Vertex | `num` | `low` | Parent |
|--------|-------|-------|--------|
| 1      | 1     | 1     | -1     |
| 2      | 2     | 1     | 1      |
| 4      | 3     | 1     | 2      |
| 5      | 4     | 4     | 4      |
| 3      | 5     | 5     | 5      |

- Edge $(4,5)$: $low[5]=4 \geq num[5]=4$. Bridge. ✓ (only path from $\{3,5\}$ to $\{1,2,4\}$)
- Edge $(5,3)$: $low[3]=5 \geq num[3]=5$. Bridge. ✓ (only connection to node 3)
- Edge $(2,4)$: $low[4]=1 < num[4]=3$. Not bridge (cycle $1\text{-}2\text{-}4\text{-}1$).

Bridges: **(4, 5)** and **(3, 5)**.

## Complexity

- **Time:** $O(n + m)$
- **Memory:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Necessary%20Roads.cpp)
