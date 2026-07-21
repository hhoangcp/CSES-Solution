# MST Edge Cost - Solution

**ID:** 3409 | **URL:** https://cses.fi/problemset/task/3409

## Approach

### Problem Restatement

Given a connected undirected weighted graph, for each edge $e$, compute the MST cost when $e$ is **forced** to be included in the spanning tree.

### Core idea

Adding edge $e = (u, v, w)$ to the MST creates exactly one cycle: the $u$-$v$ path in the MST plus edge $e$. To get a spanning tree containing $e$, we must remove one edge from this cycle. To minimize cost, remove the heaviest edge on the $u$-$v$ path, saving `max_w`, and add $e$ at cost $w$. Cost = `mst_cost - max_w + w`. If $e$ is already in the MST, then $e$ is on the path so `max_w >= w`, and since the MST is optimal, the result must equal exactly `mst_cost`.

### Algorithm

1. Build MST using Kruskal. Compute `mst_cost`.
2. Build tree from MST edges. Precompute binary lifting with max-edge queries.
3. For each edge $(u, v, w)$: answer = `mst_cost - mx_query(u, v) + w`.

### Example

MST: (3,4,1), (1,3,2), (2,4,2), (4,5,3). MST cost = 8.

Edge (1,2,4): path 1-3-4-2, max = 2. Answer = 8 - 2 + 4 = 10.
Edge (3,5,4): path 3-4-5, max = 3. Answer = 8 - 3 + 4 = 9.
MST edges: answer = 8.

## Complexity

- **Time:** $O(m \log m + n \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/MST%20Edge%20Cost.cpp)
