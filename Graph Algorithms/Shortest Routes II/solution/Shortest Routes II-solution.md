# Shortest Routes II - Solution

**ID:** 1672 | **URL:** https://cses.fi/problemset/task/1672

## Approach

### Problem Restatement

Given an undirected weighted graph with $n$ vertices ($n \le 500$) and $m$ edges with non-negative weights, process $q$ queries each asking for the shortest distance between two vertices. If no path exists, output $-1$.

### Core Idea

With $n \le 500$, use the **Floyd-Warshall** algorithm to compute all-pairs shortest distances in $O(n^3)$ preprocessing, then answer each query in $O(1)$.

Initialize a distance matrix `floyd[i][j]`: `floyd[i][i] = 0`, `floyd[i][j] =` direct edge weight (minimum if multiple edges), and `floyd[i][j] = +\infty` if no direct edge. Then iterate over each intermediate vertex $k$ from $1$ to $n$, updating all pairs:

$$\text{floyd}[i][j] = \min(\text{floyd}[i][j],  \text{floyd}[i][k] + \text{floyd}[k][j])$$

The intermediate vertex loop $k$ must be outermost. After processing all $k$, `floyd[i][j]` holds the shortest distance between every pair.

**Correctness.** After step $k$, `floyd[i][j]` equals the shortest distance from $i$ to $j$ using only intermediate vertices in $\{1, 2, \ldots, k\}$. This holds by induction: at step $k$, any shortest path either does not use vertex $k$ (value preserved) or uses $k$, splitting into $i \leadsto k$ and $k \leadsto j$ where each sub-path uses only intermediates in $\{1, \ldots, k-1\}$ — their lengths are already computed. After step $n$, all vertices are allowed as intermediates, giving the true shortest distances.

### Algorithm

1. Initialize: `floyd[i][i] = 0`, `floyd[i][j] = +\infty` for $i \neq j$. For each edge $(u, v, c)$: `floyd[u][v] = floyd[v][u] = min(floyd[u][v], c)`.
2. For $k = 1$ to $n$: for $i = 1$ to $n$: for $j = 1$ to $n$: `floyd[i][j] = min(floyd[i][j], floyd[i][k] + floyd[k][j])`.
3. For each query $(a, b)$: if `floyd[a][b] = +\infty`, output $-1$; otherwise output `floyd[a][b]`.

### Example

Input:
```
4 3 5
1 2 5
1 3 9
2 3 3
1 2
2 1
1 3
1 4
3 2
```

Initial matrix (non-$\infty$ entries): $f[1][2] = f[2][1] = 5$, $f[1][3] = f[3][1] = 9$, $f[2][3] = f[3][2] = 3$.

- $k = 1$: no updates (vertex 1 has no shortcut paths).
- $k = 2$: $f[1][3] = \min(9, 5 + 3) = 8$, $f[3][1] = \min(9, 3 + 5) = 8$.
- $k = 3$: no improvements (e.g., $f[1][2] = \min(5, 8 + 3) = 5$).
- $k = 4$: vertex 4 is isolated, no updates.

Queries:
- $1 \to 2$: $5$
- $2 \to 1$: $5$
- $1 \to 3$: $8$
- $1 \to 4$: $\infty$ → $-1$
- $3 \to 2$: $3$

Output:
```
5
5
8
-1
3
```

## Complexity

- **Time:** $O(n^3 + q)$ — Floyd-Warshall preprocessing plus $O(1)$ per query.
- **Space:** $O(n^2)$ — distance matrix.

## Code (C++)

[Solution Code](../code/Shortest%20Routes%20II.cpp)
