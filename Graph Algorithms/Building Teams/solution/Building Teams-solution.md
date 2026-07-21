# Building Teams - Solution

**ID:** 1668 | **URL:** https://cses.fi/problemset/task/1668

## Approach

### Problem Restatement

Given $n$ pupils and $m$ friendships, divide all pupils into two teams so that no two friends are on the same team. If impossible, print "IMPOSSIBLE".

### Core Idea

Model the problem as a graph where vertices are pupils and edges are friendships. The task is to 2-color the graph so that adjacent vertices always have different colors — this is exactly checking whether the graph is bipartite.

**Key fact:** A graph is bipartite if and only if it contains no odd cycle.

BFS assigns each vertex a color based on the parity of its distance from the source: color 1 for even distance, color 2 for odd distance. This is consistent within each connected component because:
- If the graph is bipartite, there exists a partition $(A, B)$ where all edges go between $A$ and $B$. BFS colors vertices in $A$ as 1 and vertices in $B$ as 2, so no conflict arises.
- If the graph contains an odd cycle, two adjacent vertices on that cycle end up at the same parity of distance from the source, receiving the same color. When the edge between them is examined, the algorithm detects $c[u] = c[v]$ and reports "IMPOSSIBLE".

### Algorithm

1. Initialize all colors as 0 (uncolored).
2. For each uncolored vertex $s$:
   - Set $c[s] = 1$, push $s$ into a queue.
   - While the queue is not empty, dequeue vertex $u$. For each neighbor $v$:
     - If $c[v] = 0$: set $c[v] = 3 - c[u]$, push $v$.
     - If $c[v] = c[u]$: output "IMPOSSIBLE" and stop.
3. If no conflict is found, output all colors.

The formula $3 - c[u]$ alternates between 1 and 2: $3 - 1 = 2$, $3 - 2 = 1$.

### Example

Input:
```
5 3
1 2
1 3
4 5
```

The graph has two connected components:
- Component {1, 2, 3}: BFS from 1 → $c[1] = 1$, neighbors 2 and 3 → $c[2] = 2$, $c[3] = 2$.
- Component {4, 5}: BFS from 4 → $c[4] = 1$, neighbor 5 → $c[5] = 2$.

No conflicts detected. Output:
```
1 2 2 1 2
```

## Complexity

- **Time:** $O(n + m)$ — each vertex and edge is processed exactly once.
- **Space:** $O(n + m)$ — adjacency list and color array.

## Code (C++)

[Solution Code](../code/Building%20Teams.cpp)
