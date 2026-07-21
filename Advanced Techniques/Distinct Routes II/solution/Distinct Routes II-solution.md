# Distinct Routes II - Solution

**ID:** 2130 | **URL:** https://cses.fi/problemset/task/2130

## Approach

### Problem Restatement

A game has $n$ rooms and $m$ directed teleporters. Play $k$ days, each day you must travel from room 1 to room $n$. Each teleporter can be used at most once, each use costs 1 coin. Find the minimum total coins, or $-1$ if there aren't $k$ edge-disjoint paths.

### Core Idea

This is a **minimum-cost flow** problem. Each teleporter is modeled as a directed edge with capacity 1 and cost 1. Capacity 1 ensures edge-disjointness (each teleporter used at most once), and cost 1 per edge means minimizing total coins equals minimizing total flow cost. We need to send $k$ units of flow from node 1 to node $n$ at minimum cost.

We use the **Successive Shortest Augmenting Path (SSAP)** algorithm: repeatedly find the shortest-cost augmenting path in the residual graph and push 1 unit of flow along it. This produces a minimum-cost flow because augmenting along the shortest-cost path preserves optimality — if a cheaper flow of the same value existed, the difference would form a cheaper augmenting path, contradicting the shortest-path choice. To handle negative-cost reverse edges in the residual graph, we maintain **potentials** $\pi$ with reduced cost $c_\pi(e) = c(e) + \pi(u) - \pi(v)$, keeping all reduced costs non-negative so Dijkstra can be used.

After finding the min-cost flow of value $k$, trace $k$ routes via BFS on saturated edges, marking each used edge to avoid reuse.

### Algorithm

1. Build the flow network: each teleporter is an edge (capacity 1, cost 1) with a reverse edge (capacity 0, cost −1). Add super source → node 1 and node $n$ → super sink (capacity $k$, cost 0).
2. Run $k$ iterations of SSAP:
   - Find shortest augmenting path via Dijkstra with potentials.
   - If no path exists, output $-1$.
   - Otherwise, augment 1 unit of flow, update potentials: $\pi(v) \mathrel{+}= \text{dist}(v)$.
3. Output total cost.
4. Trace $k$ routes using BFS on saturated edges, marking each used edge to avoid reuse.

### Example

$n=8$, $m=10$, $k=2$. Teleporters: 1→2, 1→3, 2→5, 2→4, 3→5, 3→6, 4→8, 5→8, 6→7, 7→8.

- **Augmentation 1:** Shortest path 1→2→4→8 (cost 3). Push 1 unit. Reverse edges added: 8→4, 4→2, 2→1 (cost −1 each).
- **Augmentation 2:** Shortest path 1→3→5→8 (cost 3). Push 1 unit.

Total cost: 6. Two edge-disjoint routes:
```
6
4
1 2 4 8
4
1 3 5 8
```

## Complexity

- **Time:** $O(k \cdot m \log n)$ — $k$ augmentations, each Dijkstra $O(m \log n)$.
- **Memory:** $O(n + m)$ — adjacency lists and edge storage.

## Code (C++)

[Solution Code](../code/Distinct%20Routes%20II.cpp)
