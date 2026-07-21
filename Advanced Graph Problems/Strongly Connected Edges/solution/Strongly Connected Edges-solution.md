# Strongly Connected Edges - Solution

**ID:** 2177 | **URL:** https://cses.fi/problemset/task/2177

## Approach

### Problem Restatement

Given an undirected graph, direct each edge so that the resulting directed graph is strongly connected. If impossible, output "IMPOSSIBLE".

### Core idea

An undirected graph can be oriented into a strongly connected directed graph iff it is connected and has no bridges (2-edge-connected). If there's a bridge, any orientation creates a one-way cut between its two sides. Conversely, if no bridges exist, a DFS-based orientation works: tree edges go parent→child, back edges go descendant→ancestor. Since no bridge exists, every tree edge $(u,v)$ has `low[v] <= num[u]`, meaning $v$'s subtree has a back edge reaching $u$ or above — this back edge plus tree edges forms a directed cycle through $(u,v)$. Every edge lies on such a cycle, so the result is strongly connected.

### Algorithm

1. Run DFS from node 1, computing `num[u]` (discovery time) and `low[u]` (lowest reachable `num` via back edges). Record edge orientations:
   - Tree edge (parent $u$, child $v$): orient $u \to v$. If `low[v] > num[u]` (bridge), output IMPOSSIBLE and exit.
   - Back edge (from $v$ to ancestor $u$): orient $v \to u$.
2. After DFS, if not all $n$ nodes visited (disconnected), output IMPOSSIBLE.
3. Otherwise, output all oriented edges.

### Example

$n=3$, $m=3$, edges: 1-2, 1-3, 2-3. DFS from 1: tree edges 1→2, 2→3; back edge 3→1. No bridge. Output: 1→2, 2→3, 3→1.

### Implementation Notes

- Use `tick[]` to avoid processing/outputting the same edge twice.
- Check `low[v] > num[u]` for bridge detection; exit immediately if found.
- After DFS, verify all nodes visited.

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Strongly%20Connected%20Edges.cpp)
