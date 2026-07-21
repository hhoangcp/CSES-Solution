# Distinct Routes - Solution

**ID:** 1711 | **URL:** https://cses.fi/problemset/task/1711

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, find the maximum number of edge-disjoint paths from vertex 1 to vertex $n$, and output each path.

### Core Idea

Model the problem as **maximum flow** with unit capacities: each edge has capacity 1, and add a reverse edge with capacity 0 (for residual flow). By Menger's theorem, the maximum number of edge-disjoint paths equals the maximum flow value. This is correct because:

- **Integral flow decomposition:** With unit capacities, the Integral Flow Theorem guarantees a maximum flow where each edge carries 0 or 1 units. This flow decomposes into edge-disjoint paths (each carrying 1 unit from source to sink).
- **Optimality:** If $k > f^*$ edge-disjoint paths existed, they would form a valid flow of value $k$, contradicting the maximality of $f^*$.
- **Edge-disjointness of extraction:** Each edge has capacity 1, so flow on any edge is at most 1. The `Tracing` function marks each used edge, preventing reuse across paths.

Use **Dinic's algorithm** to compute maximum flow on this unit-capacity network, then extract each path by following saturated edges ($c = f = 1$).

### Algorithm

1. **Build flow network:** For each edge $u \to v$, create a forward edge with $c = 1$ and a reverse edge with $c = 0$.
2. **Dinic's algorithm:**
   - **BFS leveling:** Build level graph from vertex 1, following edges with residual capacity $\geq 1$.
   - **DFS augmenting:** Find augmenting paths on the level graph, push 1 unit of flow. Update forward edge $f$ by $+1$ and reverse edge $f$ by $-1$.
   - Repeat until no augmenting path exists.
3. **Extract paths:** Repeat $f^*$ times:
   - BFS from vertex 1 following saturated edges ($c = 1, f = 1$) not yet marked `used`.
   - Trace back from $n$ to $1$ using the `trace` array.
   - Mark each edge on the path as `used`.

### Example

Input:
```
6 7
1 2
1 3
2 6
3 4
3 5
4 6
5 6
```

Dinic: Push 1 unit through $1 \to 2 \to 6$, push 1 unit through $1 \to 3 \to 4 \to 6$. Maximum flow = 2.

Tracing:
- Round 1: BFS along saturated edges → path $1 \to 2 \to 6$. Mark edges `used`.
- Round 2: BFS → path $1 \to 3 \to 4 \to 6$. Mark edges `used`.

Output:
```
2
3
1 2 6
4
1 3 4 6
```

## Complexity

- **Time:** $O(m\sqrt{n})$ for Dinic on unit-capacity network, $O(f^* \cdot m)$ for path extraction.
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Distinct%20Routes.cpp)
