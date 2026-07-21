# Reachability Queries - Solution

**ID:** 2143 | **URL:** https://cses.fi/problemset/task/2143

## Approach

### Problem Restatement

Given a directed graph with $n$ vertices and $m$ edges, answer $q$ queries of the form "can vertex $b$ be reached from vertex $a$?"

### Core Idea

With $n \leq 5 \times 10^4$ and $q \leq 10^5$, per-query BFS/DFS is too slow. Instead:

1. **Condense to SCCs:** Vertices within the same SCC can all reach each other, so condense the graph into a DAG of SCCs. Vertex $a$ reaches $b$ iff SCC($a$) reaches SCC($b$) in the DAG — any path from $a$ to $b$ passes through a chain of SCCs corresponding to a DAG path, and conversely a DAG path can be expanded using intra-SCC connectivity.

2. **Bitset reachability on the DAG:** For each SCC $u$, maintain a bitset $dp[u]$ where bit $j$ is set iff $u$ can reach SCC $j$. Process SCCs in reverse topological order via DFS:

$$dp[u] = \{u\} \cup \bigcup_{v \in \text{adj}(u)} dp[v]$$

The union is computed via bitset OR in $O(S/64)$ per edge, where $S$ is the number of SCCs.

3. **Answer queries** in $O(1)$ by checking if bit SCC($b$) is set in $dp[\text{SCC}(a)]$.

### Algorithm

1. Find all SCCs using Tarjan's algorithm ($O(n + m)$).
2. Build the condensation DAG: for each edge $(u, v)$ with SCC($u$) $\neq$ SCC($v$), add edge SCC($u$) $\to$ SCC($v$). Remove duplicates.
3. Run DFS on the DAG to compute bitsets: set self-bit, then OR each successor's bitset.
4. For each query $(a, b)$: if bit SCC($b$) is set in $dp[\text{SCC}(a)]$, output "YES"; otherwise "NO".

### Example

4 vertices, 4 edges: $(1,2), (2,3), (3,1), (4,3)$.

**SCCs:** $\{1,2,3\}$ (SCC 0), $\{4\}$ (SCC 1). DAG: $1 \to 0$ (edge from SCC 1 to SCC 0).

**Bitset computation:**
- DFS(0): no successors. $dp[0] = \{\text{bit } 0\}$.
- DFS(1): successor is SCC 0. $dp[1] = \{\text{bit } 1\} \cup dp[0] = \{\text{bit } 0, \text{bit } 1\}$.

**Queries:**

| Query | SCC($a$) | SCC($b$) | Check | Result |
|-------|----------|----------|-------|--------|
| $1 \to 3$ | 0 | 0 | bit 0 in $dp[0]$ | YES |
| $1 \to 4$ | 0 | 1 | bit 1 in $dp[0]$ | NO |
| $4 \to 1$ | 1 | 0 | bit 0 in $dp[1]$ | YES |

## Complexity

- **Time:** $O(n + m + q + \frac{m \cdot S}{64})$, where $S$ is the number of SCCs
- **Memory:** $O(\frac{S^2}{64})$

## Code (C++)

[Solution Code](../code/Reachability%20Queries.cpp)
