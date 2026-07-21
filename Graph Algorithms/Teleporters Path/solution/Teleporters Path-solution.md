# Teleporters Path - Solution

**ID:** 1693 | **URL:** https://cses.fi/problemset/task/1693

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, find an Euler path from vertex 1 to vertex $n$ — a path that traverses every edge exactly once — or report "IMPOSSIBLE".

### Core Idea

This is the **Euler path** problem in a directed graph. An Euler path from vertex 1 to vertex $n$ exists if and only if two conditions hold:

1. **Degree condition:** $\text{out}(1) - \text{in}(1) = 1$, $\text{in}(n) - \text{out}(n) = 1$, and $\text{in}(u) = \text{out}(u)$ for all other vertices $u$.
2. **Connectivity condition:** All edges belong to the same weakly connected component.

The degree condition is necessary because each intermediate vertex must be entered and left equally many times, while vertex 1 starts the path (one extra exit) and vertex $n$ ends it (one extra entry). The condition is also sufficient: adding a virtual edge $n \to 1$ makes all degrees balanced, so an Euler circuit exists in the weakly connected graph; removing the virtual edge yields an Euler path from 1 to $n$.

If the conditions hold, find the Euler path using **Hierholzer's algorithm**: start DFS from vertex 1, at each vertex follow any unused outgoing edge (removing it from the adjacency list), and when no outgoing edges remain, append the vertex to the result. The result is built in postorder, so reversing it gives the path from 1 to $n$.

**Correctness of Hierholzer.** Vertices are appended to the path only after all their outgoing edges have been consumed. Reading the result in reverse, each vertex has exactly one used edge leading to the next vertex in the sequence. The final vertex appended is 1 (the start), and the first is $n$ (the end).

After computing the path, verify its length is $m + 1$ (i.e., all $m$ edges were traversed). If not, some edges are unreachable from vertex 1, meaning the graph is not weakly connected, and the answer is "IMPOSSIBLE".

### Algorithm

1. Read input, compute `in[u]` and `out[u]` for each vertex.
2. Check degree condition: $\text{out}(1) - \text{in}(1) = 1$, $\text{in}(n) - \text{out}(n) = 1$, and $\text{in}(u) = \text{out}(u)$ for all $u \neq 1, n$. If not satisfied, output "IMPOSSIBLE".
3. Run Hierholzer's algorithm from vertex 1, recording vertices in postorder.
4. If the path length is not $m + 1$, output "IMPOSSIBLE". Otherwise, reverse and output the path.

### Example

Input:
```
5 6
1 2
1 3
2 4
2 5
3 1
4 2
```

Degree check: out(1)−in(1) = 2−1 = 1 ✓, in(5)−out(5) = 1−0 = 1 ✓, all others balanced ✓.

DFS from 1:
- From 1, take edge 1→3. From 3, take edge 3→1. From 1, take edge 1→2. From 2, take edge 2→5. No edges from 5 → append 5. Back at 2, take edge 2→4. From 4, take edge 4→2. No edges from 2 → append 2. No edges from 4 → append 4. No edges from 2 → append 2. No edges from 1 → append 1. No edges from 3 → append 3. No edges from 1 → append 1.

Postorder: [5, 2, 4, 2, 1, 3, 1]. Reversed: **1 3 1 2 4 2 5**.

Length 7 = $m + 1$ ✓.

Output:
```
1 3 1 2 4 2 5
```

## Complexity

- **Time:** $O(n + m)$ — each edge is processed exactly once.
- **Space:** $O(n + m)$ — adjacency list and path array.

## Code (C++)

[Solution Code](../code/Teleporters%20Path.cpp)
