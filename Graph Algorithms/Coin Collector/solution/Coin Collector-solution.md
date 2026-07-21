# Coin Collector - Solution

**ID:** 1686 | **URL:** https://cses.fi/problemset/task/1686

## Approach

### Problem Restatement

Given a directed graph with $n$ rooms (each containing some coins) and $m$ one-way tunnels, find the maximum number of coins you can collect. You may start and end at any room, and each room's coins can only be collected once.

### Core Idea

In a directed graph, once you enter a Strongly Connected Component (SCC), you can reach every vertex within it and collect all their coins. So we **condense** the graph: merge each SCC into a single super-vertex with weight equal to the total coins of that SCC. The condensed graph is a DAG (a cycle in the condensed graph would contradict the SCC decomposition).

On this DAG, the maximum coins from super-vertex $u$ is:
$$dp[u] = W[u] + \max_{(u,v) \in E'} dp[v]$$

This is correct because:
- **Condensation preserves reachability:** Within an SCC, all vertices are mutually reachable, so merging them into one weighted vertex is equivalent. Edges between SCCs in the condensed graph preserve the original reachability.
- **DP is correct on DAG:** By induction in reverse topological order: if $u$ has no outgoing edges, $dp[u] = W[u]$ (base case). Otherwise, from $u$ we proceed to some neighbor $v$ and collect $dp[v]$ more coins optimally (by induction), so $dp[u] = W[u] + \max_v dp[v]$. The DAG structure guarantees a valid topological ordering for the induction.

Answer: $\max_u dp[u]$ (since we can start from any room).

### Algorithm

1. **Find SCCs** using Tarjan's algorithm: run DFS maintaining `num[u]`, `low[u]`, and a stack. When `low[u] >= num[u]`, pop all vertices from stack top down to $u$ as one SCC.
2. **Build condensed graph**: for each original edge $(u, v)$, if $\text{lab}[u] \neq \text{lab}[v]$, add edge $\text{lab}[u] \to \text{lab}[v]$. Compute $W[i] = \sum_{v \in \text{SCC}_i} w_v$.
3. **DP on DAG**: run DFS on the condensed graph. For each super-vertex $u$, compute $dp[u] = W[u] + \max_{v} dp[v]$ over all neighbors $v$ (computing $dp[v]$ recursively first).
4. Output $\max_u dp[u]$.

### Example

Input:
```
4 4
4 5 2 7
1 2
2 1
1 3
2 4
```

- SCC 1: $\{1, 2\}$ (mutually reachable via $1 \to 2, 2 \to 1$), $W_1 = 4 + 5 = 9$.
- SCC 2: $\{3\}$, $W_2 = 2$.
- SCC 3: $\{4\}$, $W_3 = 7$.
- Condensed edges: $1 \to 2$ (from edge $1 \to 3$), $1 \to 3$ (from edge $2 \to 4$).

DP: $dp[2] = 2$, $dp[3] = 7$, $dp[1] = 9 + \max(2, 7) = 16$.

Output: `16`

## Complexity

- **Time:** $O(n + m)$ — Tarjan, building condensed graph, and DP on DAG are all linear.
- **Space:** $O(n + m)$ — storing original graph, condensed graph, and auxiliary arrays.

## Code (C++)

[Solution Code](../code/Coin%20Collector.cpp)
