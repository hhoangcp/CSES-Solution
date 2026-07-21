# Cycle Finding - Solution

**ID:** 1197 | **URL:** https://cses.fi/problemset/task/1197

## Approach

### Problem Restatement

Given a directed weighted graph (weights may be negative) with $n$ vertices and $m$ edges, determine whether it contains a negative cycle. If yes, print "YES" and output any negative cycle. If no, print "NO".

### Core Idea

Use **SPFA** (Shortest Path Faster Algorithm) — a queue-based variant of Bellman-Ford — to detect and reconstruct a negative cycle. Apply the **virtual source** technique: instead of running SPFA from each vertex separately, initialize `dist[i] = 0` for all vertices and push all of them into the queue at the start. This is equivalent to adding a virtual source connected to every vertex with weight 0, so SPFA runs just once and covers all connected components.

During SPFA, maintain `cnt[v]` counting how many times vertex $v$ is relaxed. By the Bellman-Ford theorem, in a graph without negative cycles, the shortest path between any two vertices uses at most $n - 1$ edges, so no vertex is relaxed more than $n - 1$ times. If `cnt[v] >= n`, a negative cycle exists.

When `cnt[v] >= n`, vertex $v$ may be inside the negative cycle or merely reachable from one. To find the cycle itself, walk back $n$ steps along `trace` from $v$ — this guarantees landing inside the cycle (since any path of $n$ edges must revisit a vertex on the cycle). Then trace out the cycle from that point.

**Correctness.** In a graph without negative cycles, the shortest path to any vertex uses at most $n - 1$ edges, so after $n - 1$ rounds of relaxation all distances are optimal and no further relaxations occur. Conversely, if a negative cycle exists, traversing it always decreases the distance, so some vertex on or reachable from the cycle is relaxed indefinitely. SPFA detects this when `cnt[v] >= n`.

### Algorithm

1. **Self-loop check:** If any edge $u \to u$ has negative weight, output this 1-vertex cycle and stop.
2. **Initialize SPFA:** Set `dist[i] = 0` for all vertices, push all into the queue.
3. **Cycle detection:** When relaxing edge $u \to v$ with weight $c$: if `dist[v] > dist[u] + c`, update `dist[v]`, set `trace[v] = u`, increment `cnt[v]`. If `cnt[v] >= n`:
   - Walk back $n$ steps along `trace` from $v$ to reach a vertex inside the cycle.
   - Trace out the cycle and output.
4. If SPFA finishes without detecting a cycle, output "NO".

### Example

Input:
```
4 5
1 2 1
2 4 1
3 1 1
4 1 -3
4 3 -2
```

Edges: $1 \to 2$ (1), $2 \to 4$ (1), $3 \to 1$ (1), $4 \to 1$ ($-3$), $4 \to 3$ ($-2$).

All vertices start with `dist = 0` in the queue.
- Process vertex 4: relax $4 \to 1$ → `dist[1] = -3`, `trace[1] = 4`; relax $4 \to 3$ → `dist[3] = -2`, `trace[3] = 4`.
- Process vertex 1: relax $1 \to 2$ → `dist[2] = -2`, `trace[2] = 1`.
- Process vertex 2: relax $2 \to 4$ → `dist[4] = -1`, `trace[4] = 2`.
- Process vertex 4 again: relax $4 \to 1$ → `dist[1] = -4`, `cnt[1] = 2`; relax $4 \to 3$ → `dist[3] = -3`, `cnt[3] = 2`.

Each round through the cycle $1 \to 2 \to 4 \to 1$ decreases all distances by 1. After 4 rounds, `cnt[1] = 4 >= n`. Walk back 4 steps from vertex 1: $1 \to 4 \to 2 \to 1 \to 4$ → now at vertex 4, which is inside the cycle. Trace: $4 \to 2 \to 1 \to 4$. Reversed: $1 \to 2 \to 4 \to 1$.

Output:
```
YES
1 2 4 1
```

## Complexity

- **Time:** $O(n \cdot m)$ in the worst case — SPFA is faster in practice on average.
- **Space:** $O(n + m)$ — adjacency list, distance/trace arrays, and queue.

## Code (C++)

[Solution Code](../code/Cycle%20Finding.cpp)
