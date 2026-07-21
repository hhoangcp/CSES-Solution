# Course Schedule - Solution

**ID:** 1679 | **URL:** https://cses.fi/problemset/task/1679

## Approach

### Problem Restatement

There are $n$ courses and $m$ prerequisites of the form "$a$ must be completed before $b$". Find an order to complete all courses satisfying all prerequisites, or output "IMPOSSIBLE" if no such order exists.

### Core Idea

Model each course as a vertex and each prerequisite $(a, b)$ as a directed edge $a \to b$. A valid completion order is a **topological order** — a linear ordering where every edge $u \to v$ has $u$ before $v$. A topological order exists if and only if the graph is a **DAG** (no directed cycles). If a cycle $v_1 \to v_2 \to \cdots \to v_k \to v_1$ exists, following the prerequisite chain would require $v_1$ before $v_1$, which is impossible.

Use DFS to compute the topological order:
- When DFS finishes exploring all neighbors of vertex $u$, append $u$ to a postorder list.
- After all vertices are processed, reverse the postorder list to get the topological order.

This works because: when $u$ is added to the postorder list, every vertex $v$ reachable from $u$ (via edge $u \to v$) has already been added earlier. After reversing, $u$ appears before $v$, satisfying the topological condition.

**Cycle detection:** Maintain an `in[u]` flag indicating $u$ is on the current DFS recursion stack. When examining edge $u \to v$: if $v$ is visited and `in[v]` is true, then $v$ is on the path from the DFS root to $u$, and edge $u \to v$ closes a cycle. Conversely, if the graph has a cycle, DFS must encounter a back edge, so the algorithm will detect it.

### Algorithm

1. For each unvisited vertex, run DFS.
2. In DFS from vertex $u$:
   - Set `visited[u] = in[u] = true`.
   - For each neighbor $v$: if unvisited, recurse; if visited and `in[v]`, cycle detected → output "IMPOSSIBLE".
   - After all neighbors processed: set `in[u] = false`, append $u$ to the result list.
3. Reverse the result list and output it.

### Example

Input:
```
5 3
1 2
3 1
4 5
```

Graph edges: $1 \to 2$, $3 \to 1$, $4 \to 5$.

- DFS from 1: visit 1 → neighbor 2 → visit 2 (no neighbors) → postorder: 2. Back to 1 → postorder: 2, 1.
- DFS from 3: visit 3 → neighbor 1 (already visited, not in stack) → postorder: 2, 1, 3.
- DFS from 4: visit 4 → neighbor 5 → visit 5 (no neighbors) → postorder: 2, 1, 3, 5. Back to 4 → postorder: 2, 1, 3, 5, 4.

Reversed: `4 5 3 1 2`. Check: 1→2 (1 before 2 ✓), 3→1 (3 before 1 ✓), 4→5 (4 before 5 ✓).

Output:
```
4 5 3 1 2
```

## Complexity

- **Time:** $O(n + m)$ — each vertex and edge is processed exactly once.
- **Space:** $O(n + m)$ — adjacency list and state arrays.

## Code (C++)

[Solution Code](../code/Course%20Schedule.cpp)
