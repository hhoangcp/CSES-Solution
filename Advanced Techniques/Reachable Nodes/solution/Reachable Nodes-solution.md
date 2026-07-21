# Reachable Nodes - Solution

**ID:** 2138 | **URL:** https://cses.fi/problemset/task/2138

## Approach

### Problem Restatement

Given a DAG with $n$ vertices and $m$ edges, compute for each vertex the number of reachable vertices (including itself).

### Core Idea

Since the graph is a DAG, the set of reachable vertices from $u$ satisfies:

$$R(u) = \{u\} \cup \bigcup_{v \in \text{adj}(u)} R(v)$$

Process vertices via DFS (reverse topological order ensures successors are computed first). By structural induction on the DAG: a vertex with no successors reaches only itself (base case); a vertex $u$ with successors $v_1, \ldots, v_k$ reaches itself and everything reachable from its successors (inductive step). The DFS processes all successors before $u$, so each `dp[v_i]` is correct when computing `dp[u]`.

**Bitset optimization:** Represent each $R(u)$ as a bitset of $n$ bits. Union becomes bitwise OR, costing $O(n/64)$ instead of $O(n)$. For $n = 5 \times 10^4$, each bitset is $\approx 786$ 64-bit words — an OR takes only 786 machine operations. Count reachable vertices via `__builtin_popcountll`.

### Algorithm

1. For each unvisited vertex $u$, run DFS:
   - Set bit $u$ in `dp[u]`.
   - For each successor $v$: recurse into $v$, then OR `dp[v]` into `dp[u]`.
2. For each vertex, count bits in `dp[u]` and output.

### Example

5 vertices, 6 edges: $(1,2), (1,3), (1,4), (2,3), (3,5), (4,5)$.

| Vertex | Successors | $R(u)$ | Count |
|--------|------------|--------|-------|
| 5      | —          | {5}    | 1     |
| 4      | {5}        | {4, 5} | 2     |
| 3      | {5}        | {3, 5} | 2     |
| 2      | {3}        | {2, 3, 5} | 3  |
| 1      | {2, 3, 4}  | {1, 2, 3, 4, 5} | 5 |

Output: `5 3 2 2 1`

## Complexity

- **Time:** $O\left(\dfrac{n \cdot (n + m)}{64}\right)$
- **Memory:** $O\left(\dfrac{n^2}{64}\right)$

## Code (C++)

[Solution Code](../code/Reachable%20Nodes.cpp)
