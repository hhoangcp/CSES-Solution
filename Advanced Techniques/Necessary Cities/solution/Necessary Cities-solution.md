# Necessary Cities - Solution

**ID:** 2077 | **URL:** https://cses.fi/problemset/task/2077

## Approach

### Problem Restatement

Given an undirected connected graph with $n$ vertices and $m$ edges, find all *necessary cities* (articulation points) — vertices whose removal (along with adjacent edges) disconnects the graph.

### Core Idea

Use Tarjan's DFS-based algorithm with two arrays:
- `num[u]`: discovery order of vertex $u$ during DFS.
- `low[u]`: lowest discovery order reachable from $u$ or its subtree via back edges.

A vertex $u$ is an articulation point iff:
1. **Root of DFS tree:** it has $\geq 2$ children. Since subtrees of different children cannot be connected by an edge (otherwise DFS would traverse between them), removing the root disconnects them.
2. **Non-root vertex $u$ (parent of $v$):** $low[v] \geq num[u]$ for some child $v$. This means no vertex in $v$'s subtree can reach an ancestor of $u$ via a back edge, so removing $u$ disconnects $v$'s subtree. Conversely, if $low[v] < num[u]$, there exists a back edge bypassing $u$, so removing $u$ does not disconnect $v$'s subtree.

### Algorithm

1. Run DFS from each unvisited vertex $u$:
   - Set `lab[u] = -1` to mark the root.
   - Assign `num[u]` = discovery order.
   - For each neighbor $v$:
     - If $v$ is unvisited: recurse into $v$, then update `low[u] = min(low[u], low[v])`.
     - If $v$ is visited (back edge): update `low[u] = min(low[u], num[v])`.
2. Identify articulation points:
   - Root: articulation point if it has $\geq 2$ DFS tree children.
   - Non-root: vertex $u$ (parent of $v$) is an articulation point if $low[v] \geq num[u]$.
3. Output all articulation points in increasing order.

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

- Node 4 is AP: child $v=5$, $low[5]=4 \geq num[4]=3$.
- Node 5 is AP: child $v=3$, $low[3]=5 \geq num[5]=4$.
- Node 1 is not AP (root with only 1 child).

Articulation points: **4, 5**.

## Complexity

- **Time:** $O(n + m)$
- **Memory:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Necessary%20Cities.cpp)
