# Dynamic Connectivity - Solution

**ID:** 2133 | **URL:** https://cses.fi/problemset/task/2133

## Approach

### Problem Restatement

Given an undirected graph with $n$ nodes and $m$ initial edges. Process $k$ events: add an edge or remove an edge. After each event (and initially), report the number of connected components.

### Core Idea

Standard DSU supports adding edges efficiently but cannot remove them. However, each edge exists during a continuous time interval $[l, r]$ (from when it's added to when it's removed, or until the end if never removed). This motivates a **segment tree over time** approach.

Build a segment tree over the time axis $[0, k]$. Each edge with lifetime $[l, r]$ is inserted into the $O(\log k)$ segment tree nodes that cover $[l, r]$. Then traverse the tree DFS-style: when entering a node, union all its edges using **DSU with rollback**; when leaving, rollback those unions. At each leaf $t$, the DSU contains exactly the edges alive at time $t$ — because an edge with lifetime $[l, r]$ is unioned at a node on the root-to-leaf path for leaf $t$ if and only if that node's interval lies within $[l, r]$, i.e., $t \in [l, r]$.

DSU with rollback uses union by size without path compression (which would prevent accurate rollback). Each successful union saves state to a stack for rollback. A counter `cgs` tracks the number of connected components, decremented on union and restored on rollback.

### Algorithm

1. Track each edge's lifetime using a `map`. Initial edges start at time 0. Add events record the start time. Remove events close the interval $[\text{start}, \text{current}-1]$ and insert the edge into the segment tree.
2. After all events, remaining edges have intervals extending to $k$.
3. Traverse the segment tree recursively:
   - Before recursing: union all edges at the current node.
   - Recurse to children.
   - After recursing: rollback all unions at this node.
4. At leaf $i$, record `cgs` into `ans[i]`.

### Example

$n=5$, $m=3$, $k=3$. Initial edges: (1,4), (2,3), (3,5).

| Time | Event | Edge lifetimes | Components |
|------|-------|----------------|------------|
| 0 | — | (1,4)[$0$,$3$], (2,3)[$0$,$3$], (3,5)[$0$,$1$] | 2 |
| 1 | Add (2,5) | +(2,5)[$1$,$3$] | 2 |
| 2 | Remove (3,5) | (3,5) lifetime closed at $1$ | 2 |
| 3 | Add (1,2) | +(1,2)[$3$,$3$] | 1 |

- Time 0: $\{1,4\}$ and $\{2,3,5\}$ → 2
- Time 1: (2,5) added, but 2–5 already connected via $2 \to 3 \to 5$ → 2
- Time 2: (3,5) removed, but 2–5 still connected via $2 \to 5$ → 2
- Time 3: (1,2) added, merges the two components → 1

Result: `2 2 2 1`

## Complexity

- **Time:** $O((m + k) \log k \cdot \log n)$ — each edge in $O(\log k)$ segment tree nodes, union/rollback $O(\log n)$ (no path compression with rollback).
- **Memory:** $O((m + k) \log k)$ — edges stored in segment tree nodes.

## Code (C++)

[Solution Code](../code/Dynamic%20Connectivity.cpp)
