# Even Outdegree Edges - Solution

**ID:** 2179 | **URL:** https://cses.fi/problemset/task/2179

## Approach

### Problem Restatement

Given an undirected graph, direct each edge so that every node has even outdegree. If impossible, output "IMPOSSIBLE".

### Feasibility condition

The sum of all outdegrees equals the number of edges $m$. If all outdegrees are even then $m$ is even, so each connected component must have an even number of edges. Conversely, if each component has an even number of edges, the DFS algorithm will produce all even outdegrees.

### Core idea

Use DFS processed bottom-up on the DFS tree. For each child $v$ of parent $u$: if $v$ has odd outdegree, orient the tree edge $v \to u$ (fixing $v$ to even, pushing responsibility to $u$); if $v$ has even outdegree, orient $u \to v$ (only toggling $u$). For back edges, orient from the deeper node to the shallower node. Bottom-up processing ensures every child is fixed to even before pushing adjustments to the parent. The only node without a parent to push to is the root; if the component has an even number of edges, the root automatically ends up even.

### Algorithm

1. Run DFS, identifying tree edges and back edges.
2. Process back edges: orient from deeper node to shallower node.
3. Process tree edges bottom-up: when returning from child $v$ to parent $u$:
   - If $v$ has odd outdegree: add edge $v \to u$.
   - If $v$ has even outdegree: add edge $u \to v$.
4. If any node still has odd outdegree, output "IMPOSSIBLE".

### Example

4 nodes, 4 edges: 1-2, 2-3, 3-4, 1-4.

DFS from 1: tree edges 1-2, 2-3, 3-4. Back edge: 4-1.

- Back edge $4\to1$: odd[4] = odd.
- Tree edge 3-4: odd[4] odd $\to$ $4\to3$, odd[4] even.
- Tree edge 2-3: odd[3] even $\to$ $2\to3$, toggle odd[2].
- Tree edge 1-2: odd[2] odd $\to$ $2\to1$, odd[2] even.

All nodes even. Valid result.

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Even%20Outdegree%20Edges.cpp)
