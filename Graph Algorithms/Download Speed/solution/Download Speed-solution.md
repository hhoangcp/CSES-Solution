# Download Speed - Solution

**ID:** 1694 | **URL:** https://cses.fi/problemset/task/1694

## Approach

### Problem Restatement

Given a directed network with $n$ vertices and $m$ edges, each with capacity $c$. Find the maximum flow from vertex 1 (source) to vertex $n$ (sink).

### Core Idea

This is the classic **maximum flow** problem. Use **Dinic's algorithm** with capacity scaling:

- **Residual edges:** For each forward edge $u \to v$ with capacity $c$, add a backward edge $v \to u$ with capacity 0. When pushing flow $f$ forward, the backward edge's residual capacity increases by $f$, allowing the algorithm to "cancel" previously sent flow — this is essential for correctness and optimality.
- **BFS leveling:** Build a level graph where each vertex gets a distance label from the source, only following edges with residual capacity $\geq \text{limit}$. This ensures DFS always follows shortest augmenting paths.
- **DFS blocking flow:** Find augmenting paths on the level graph, pushing flow along each. The `ptr[u]` array (current edge optimization) skips already-saturated edges, avoiding redundant work within a phase.
- **Capacity scaling:** Start with `limit = 2^30` and halve when BFS fails. This prioritizes pushing large flows first, yielding $O(\log C)$ phases where $C$ is the maximum capacity.

The algorithm terminates when `limit = 0` and no augmenting path exists. By the max-flow min-cut theorem, the resulting flow is maximum: if an augmenting path existed, flow could be increased, contradicting termination.

### Algorithm

1. **Build network:** For each edge $(u, v, c)$, add forward edge (capacity $c$) and backward edge (capacity 0). Store them adjacently so edge $i$'s reverse is $i \oplus 1$.
2. **Capacity scaling loop:** For `limit` from $2^{30}$ down to 1:
   - **BFS:** Build level graph using edges with residual capacity $\geq \text{limit}$. If sink unreachable, halve `limit`.
   - **DFS:** Find blocking flow on level graph. For each augmenting path found, push `limit` units: update forward edge flow $+\text{limit}$, backward edge flow $-\text{limit}$.
3. Output the total flow.

### Example

Input:
```
4 5
1 2 3
2 4 2
1 3 4
3 4 5
4 1 3
```

- Phase limit = 4: BFS levels $d = [0, -1, 1, 2]$ (only edges with residual $\geq 4$). DFS pushes 4 units through $1 \to 3 \to 4$. Flow = 4.
- Phase limit = 2: BFS levels $d = [0, 1, -1, 2]$. DFS pushes 2 units through $1 \to 2 \to 4$. Flow = 6.
- Phase limit = 1: BFS fails (no augmenting path with residual $\geq 1$ from 1 to $n$). Halve to 0, terminate.

Output: `6`

## Complexity

- **Time:** $O(n^2 \cdot m \cdot \log C)$ — each Dinic phase costs $O(n^2 \cdot m)$ with $O(\log C)$ scaling phases.
- **Space:** $O(n + m)$ — adjacency list and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Download%20Speed.cpp)
