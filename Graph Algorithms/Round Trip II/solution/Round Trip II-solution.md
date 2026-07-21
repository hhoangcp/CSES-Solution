# Round Trip II - Solution

**ID:** 1678 | **URL:** https://cses.fi/problemset/task/1678

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, find a directed simple cycle, or report "IMPOSSIBLE" if none exists.

### Core Idea

Run DFS on the directed graph using the **three-color** technique to detect a back edge and reconstruct the cycle. Each vertex is assigned a color:

- **Color 0** (unvisited): vertex has not been explored.
- **Color 1** (in progress): vertex is on the current DFS path (in the recursion stack).
- **Color 2** (completed): vertex and all its descendants have been fully explored.

When examining edge $u \to v$ from vertex $u$:

- If $\text{color}[v] = 0$: recursively visit $v$.
- If $\text{color}[v] = 1$: a **back edge** is detected — $v$ is an ancestor of $u$ on the current DFS path, so a cycle exists from $v$ through the DFS tree to $u$ and back via edge $u \to v$.
- If $\text{color}[v] = 2$: skip (cross edge or forward edge — no cycle).

**Why three colors instead of two?** In an undirected graph (e.g., Round Trip I), a visited neighbor that is not the parent must be an ancestor on the current DFS path, so only two states (visited/unvisited) plus a parent array suffice. In a directed graph, a visited neighbor could be either an ancestor still on the current path (color 1 — forming a cycle) or a vertex in a completely separate, already-finished subtree (color 2 — no cycle). Without distinguishing these two cases, we would incorrectly report cycles for cross edges.

**Correctness.** If DFS detects a back edge $u \to v$ with $\text{color}[v] = 1$, then $v$ is on the current DFS path, so there exists a path $v \leadsto u$ in the DFS tree; adding edge $u \to v$ closes a cycle. Conversely, if the graph contains a cycle $v_1 \to v_2 \to \cdots \to v_k \to v_1$, let $v_i$ be the first vertex in the cycle visited by DFS. When DFS reaches $v_i$, all other vertices in the cycle are unvisited, so DFS follows the cycle edges: $v_i \to v_{i+1} \to \cdots \to v_k \to v_1 \to \cdots \to v_{i-1}$. When examining edge $v_{i-1} \to v_i$, vertex $v_i$ still has color 1, so the back edge is detected.

### Algorithm

1. For each unvisited vertex, run DFS with a stack $S$ tracking the current path.
2. When DFS at $u$ examines edge $u \to v$:
   - If $\text{color}[v] = 0$: push $u$ to $S$, recurse on $v$.
   - If $\text{color}[v] = 1$: back edge found. Collect vertices from the top of $S$ down to $v$, add $v$ to close the cycle, reverse the list, and output.
   - If $\text{color}[v] = 2$: skip.
3. After processing all neighbors of $u$, mark $\text{color}[u] = 2$ and pop $u$ from $S$.
4. If no cycle found after all DFS calls, output "IMPOSSIBLE".

### Example

Input:
```
4 5
1 3
2 1
2 4
3 2
3 4
```

Edges: $1 \to 3$, $2 \to 1$, $2 \to 4$, $3 \to 2$, $3 \to 4$.

DFS from vertex 1: $S = [1]$.
- Visit vertex 3 (neighbor of 1): $S = [1, 3]$.
- Visit vertex 2 (neighbor of 3): $S = [1, 3, 2]$.
- Examine edge $2 \to 1$: $\text{color}[1] = 1$ → back edge detected!
- Reconstruct: $v = 1$. Pop from $S$: 2, 3, then reach 1. Cycle (before reverse): $[1, 2, 3, 1]$. After reverse: $[1, 3, 2, 1]$.

Output:
```
4
1 3 2 1
```

(The problem accepts any valid cycle. The sample output `2 1 3 2` is also correct: $2 \to 1 \to 3 \to 2$.)

## Complexity

- **Time:** $O(n + m)$ — each vertex and each edge is processed at most once.
- **Space:** $O(n + m)$ — adjacency list and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Round%20Trip%20II.cpp)
