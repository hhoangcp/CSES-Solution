# Graph Coloring - Solution

**ID:** 3308 | **URL:** https://cses.fi/problemset/task/3308

## Approach

### Problem Restatement

Given a simple graph with $n \leq 16$ nodes and $m$ edges, color the nodes using the minimum number of colors such that no edge connects two nodes of the same color (chromatic number).

### Core idea

A subset of nodes can share one color iff it is an **independent set**. The chromatic number equals the minimum number of independent sets needed to partition all nodes. DP formula: $dp[mask] = \min(dp[mask \oplus submask] + 1)$ over all independent submasks of `mask`. Each `+1` corresponds to using one color for the independent set `submask`, with the remainder already optimized. Since all valid submasks are considered, `dp[full_mask]` is the optimal chromatic number.

### Algorithm

1. **Precompute:** For each mask from $0$ to $2^n-1$, check if it's an independent set. Store `valid[mask]`.
2. **DP:** `dp[0] = 0`, $dp[mask] = \min(dp[mask \oplus submask] + 1)$ for all `submask ⊆ mask` where `valid[submask]`.
3. **Trace:** Use `trace[mask]` to store the optimal submask, assigning colors to each node.

### Example

$n=4$, edges: 1-2, 2-3, 3-4, 4-1 (cycle $C_4$). Maximal independent sets: $\{1,3\}$ and $\{2,4\}$.

`dp[1111] = dp[\{1,3\}] + 1 = dp[\{2,4\}] + 1 = 2`. Chromatic number = 2.

## Complexity

- **Time:** $O(3^n + m \cdot 2^n)$
- **Space:** $O(2^n)$

## Code (C++)

[Solution Code](../code/Graph%20Coloring.cpp)
