# Flight Discount - Solution

**ID:** 1195 | **URL:** https://cses.fi/problemset/task/1195

## Approach

### Problem Restatement

Given a directed weighted graph with non-negative edge weights, find the minimum cost to travel from vertex 1 to vertex $n$, with the ability to halve (integer division) the price of exactly one edge on the path.

### Core Idea

Extend Dijkstra by adding a state dimension to track coupon usage. Define $d[u][k]$ as the minimum cost to reach vertex $u$ where $k = 0$ means the coupon has not been used, and $k = 1$ means it has been used.

This creates a state graph with $2n$ vertices — each original vertex $u$ splits into $(u, 0)$ and $(u, 1)$. Since all edge weights are non-negative and $\lfloor c/2 \rfloor \geq 0$, the state graph also has non-negative weights, so Dijkstra's correctness is preserved. Every path in the original graph (with or without the coupon) corresponds 1-1 to a path from $(1, 0)$ to $(n, 0)$ or $(n, 1)$ in the state graph: using the coupon on edge $u \to v$ is modeled by transitioning from $(u, 0)$ to $(v, 1)$ with weight $\lfloor c/2 \rfloor$, and all subsequent edges only have $k = 1 \to k = 1$ transitions, ensuring exactly one use.

### Algorithm

1. Initialize $d[1][0] = 0$, all other $d[u][k] = \infty$.
2. Run Dijkstra on the state graph. When processing state $(u, k)$ with edge $u \to v$ (weight $c$):
   - **Without coupon:** $d[v][k] = \min(d[v][k],  d[u][k] + c)$
   - **With coupon** (only if $k = 0$): $d[v][1] = \min(d[v][1],  d[u][0] + \lfloor c/2 \rfloor)$
3. Answer: $\min(d[n][0], d[n][1])$.

### Example

Input:
```
3 4
1 2 3
2 3 1
1 3 7
2 1 5
```

Dijkstra from $(1, 0)$, $d[1][0] = 0$:
- Process $(1, 0)$: edge $1 \to 2$ (3): $d[2][0] = 3$, $d[2][1] = \lfloor 3/2 \rfloor = 1$. Edge $1 \to 3$ (7): $d[3][0] = 7$, $d[3][1] = \lfloor 7/2 \rfloor = 3$.
- Process $(2, 1)$, $d = 1$: edge $2 \to 3$ (1): $d[3][1] = \min(3, 1 + 1) = 2$.
- Process $(2, 0)$, $d = 3$: edge $2 \to 3$ (1): $d[3][0] = \min(7, 3 + 1) = 4$.

Answer: $\min(d[3][0], d[3][1]) = \min(4, 2) = 2$ (use coupon on edge $1 \to 2$, then $2 \to 3$ normally).

Output: `2`

## Complexity

- **Time:** $O((n + m) \log n)$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Flight%20Discount.cpp)
