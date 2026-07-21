# Police Chase - Solution

**ID:** 1695 | **URL:** https://cses.fi/problemset/task/1695

## Approach

### Problem Restatement

Given an undirected graph with $n$ vertices and $m$ edges, find the minimum number of edges to remove so that vertices 1 and $n$ become disconnected, and list those edges.

### Core idea

By the **Max-Flow Min-Cut Theorem**, the minimum cut value equals the maximum flow. Model each undirected edge as two directed edges of capacity 1, then compute the maximum flow from 1 to $n$ using Dinic's algorithm. The flow value is the answer.

To find the actual edges: after max flow, run BFS on the residual graph (only following edges with residual capacity > 0) from vertex 1. Let $S$ be the set of reachable vertices and $T$ the rest. By the theorem, the saturated original edges crossing from $S$ to $T$ form a minimum cut — they must be saturated (otherwise BFS would expand into $T$), and their total count equals the max flow. Removing these edges disconnects $S$ from $T$, hence vertex 1 from vertex $n$.

### Algorithm

1. For each undirected edge $(u, v)$, add 4 directed edges: $u \to v$ (cap 1), $v \to u$ (cap 0), $v \to u$ (cap 1), $u \to v$ (cap 0). This correctly models undirected flow.
2. Run Dinic's algorithm from source 1 to sink $n$.
3. Run a final BFS on the residual graph to partition vertices into $S$ (reachable from 1) and $T$ (unreachable).
4. Output every original edge $(u, v)$ where $u \in S$, $v \in T$, and the edge is saturated ($c = f$).

### Example

Input:
```
4 5
1 2
1 3
2 3
3 4
1 4
```

Max flow = 2 (e.g., 1 unit along $1 \to 4$, 1 unit along $1 \to 3 \to 4$). BFS on residual graph: $S = \{1, 2, 3\}$, $T = \{4\}$. Saturated edges from $S$ to $T$: $(3, 4)$ and $(1, 4)$.

Output:
```
2
3 4
1 4
```

(Any valid minimum cut is accepted.)

## Complexity

- **Time:** $O(n^2 \cdot m)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Police%20Chase.cpp)
