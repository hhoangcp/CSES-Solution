# Fixed Length Walk Queries - Solution

**ID:** 3357 | **URL:** https://cses.fi/problemset/task/3357

## Approach

### Problem Restatement

Given a connected undirected graph with $n$ nodes and $m$ edges, answer $q$ queries: can you walk from node $a$ to node $b$ in exactly $x$ steps?

### Core idea

Since the graph is connected and $n \geq 2$, every node has at least one neighbor, allowing any walk to be extended by 2 steps (go to a neighbor and back). Therefore, a walk of length $x$ exists iff the shortest walk of the same parity as $x$ has length $\leq x$.

### Algorithm

1. For each source node $s$, run BFS tracking both the current node and parity:
   - State: $(v, p)$ where $v$ is the current node and $p \in \{0, 1\}$ is the parity of steps taken.
   - From $(v, p)$, traversing an edge leads to $(u, 1-p)$.
2. Store `dist[s][v][0]` = shortest even-length walk from $s$ to $v$, `dist[s][v][1]` = shortest odd-length walk.
3. For each query $(a, b, x)$: let $p = x \bmod 2$. Answer YES if `dist[a][b][p] != -1` and `dist[a][b][p] <= x`.

### Example

Query: $a=1, b=4, x=5$. Parity = 1. If shortest odd walk from 1 to 4 is 3, since $3 \leq 5$, walk $1\to2\to3\to4$ then use remaining 2 steps $4\to3\to4$. Answer: YES.

Query: $a=1, b=4, x=1$. `dist[1][4][1] = 3 > 1`. Answer: NO.

## Complexity

- **Time:** $O(n \cdot (n + m))$ for precomputation, $O(1)$ per query.
- **Space:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Fixed%20Length%20Walk%20Queries.cpp)
