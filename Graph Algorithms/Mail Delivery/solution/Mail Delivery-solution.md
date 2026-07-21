# Mail Delivery - Solution

**ID:** 1691 | **URL:** https://cses.fi/problemset/task/1691

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, find an Euler circuit starting and ending at vertex 1 (traversing every edge exactly once), or report "IMPOSSIBLE".

### Core idea

By Euler's theorem, an undirected connected graph has an Euler circuit if and only if every vertex has even degree. The necessity is clear: in an Euler circuit, each visit to a vertex uses one entering and one leaving edge, so every vertex's degree equals twice its number of visits. For sufficiency, start from any vertex and follow unused edges — even degree guarantees you always have an exit until returning to the start. If some edges remain, splice sub-circuits into the main circuit at vertices with unused edges.

**Hierholzer's algorithm** implements this efficiently using a stack. Starting from vertex 1, greedily follow unused edges, pushing each new vertex onto the stack. When a vertex has no remaining edges, pop it to the result path. The even-degree property ensures the only vertex that can be "stuck" without an exit is vertex 1 at the very end — the result is a valid Euler circuit.

A current-edge optimization (`start[u]`) skips already-deleted edges, ensuring each edge is examined $O(1)$ times total. After the algorithm, if the path contains fewer than $m + 1$ vertices, the graph was not connected (some edges were in a separate component).

### Algorithm

1. If any vertex has odd degree, print "IMPOSSIBLE".
2. Run iterative Hierholzer from vertex 1:
   - Maintain a stack $S = [1]$ and an array `start[u]` for the current-edge optimization.
   - While $S$ is not empty: peek at top vertex $u$. Find the next unused edge $(u, v)$ (skipping deleted edges via `start[u]`). If found, mark the edge deleted and push $v$. Otherwise, pop $u$ to `Path`.
3. If `Path` has fewer than $m + 1$ vertices, print "IMPOSSIBLE" (disconnected graph). Otherwise, print `Path`.

### Example

Input:
```
6 8
1 2
1 3
2 3
2 4
2 6
3 5
3 6
4 5
```

All degrees even (1→2, 2→4, 3→4, 4→2, 5→2, 6→2). Hierholzer produces an Euler circuit, e.g.:

```
1 2 3 5 4 2 6 3 1
```

(Any valid Euler circuit is accepted.)

## Complexity

- **Time:** $O(n + m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Mail%20Delivery.cpp)
