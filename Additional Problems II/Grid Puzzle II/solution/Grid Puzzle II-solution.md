# Grid Puzzle II - Solution

**ID:** 2131 | **URL:** https://cses.fi/problemset/task/2131

## Problem Statement

Given an $n \times n$ grid where each cell contains some coins, you know how many cells to select from each row and column. You receive all coins from each selected cell. What is the maximum number of coins you can collect?

## Approach

### Modeling: Min-cost flow on a bipartite network

Similar to Grid Puzzle I, but each cell $(i,j)$ has value $c_{ij}$ (number of coins). We need to **maximize** the total coins collected. Build a min-cost flow network:

- **Source $S$** $\to$ **row $i$**: capacity $a_i$, cost 0.
- **Row $i$** $\to$ **column $j$**: capacity 1, cost $-c_{ij}$.
- **Column $j$** $\to$ **sink $T$**: capacity $b_j$, cost 0.

**Why negative costs?** Min-cost flow algorithms find the **minimum** total cost. Minimizing $\sum (-c_{ij})$ is equivalent to maximizing $\sum c_{ij}$. Each unit of flow through edge row $i$ $\to$ column $j$ corresponds to selecting cell $(i,j)$, total flow cost $= -\sum c_{ij}$. The flow saturates source $\to$ row edges (exactly $a_i$ units) and column $\to$ sink edges (exactly $b_j$ units), so degree constraints are satisfied.

### Feasibility: Complete bipartite graph always has a flow

The problem guarantees $\sum a_i = \sum b_j$. Since every row connects to every column (complete bipartite graph), max flow always reaches $\sum a_i$ (no bottleneck). Thus a feasible selection always exists.

### Cost optimality: No negative cycles in the residual graph

The algorithm iterates: find a minimum-cost augmenting path (SPFA/D'Esopo-Pape on the residual graph), augment flow, repeat until no augmenting path with negative cost exists from $S$ to $T$. By the **cost optimality condition**, a feasible flow is a min-cost flow if and only if no negative-cost cycle exists in the residual graph. SPFA finds shortest paths, so after each augmentation no new negative cycle is created. When no negative-cost path remains, the optimality condition is satisfied.

## Algorithm

1. Build the flow network with negated costs.
2. Repeat until flow reaches $\sum a_i$:
   - Find the minimum-cost path from $S$ to $T$ using SPFA or D'Esopo-Pape.
   - If no path found, output $-1$.
   - Augment flow along the path, accumulate cost.
3. Maximum coins $= -(\text{total cost})$.

## Example

$n = 5$, $a = [0, 1, 3, 2, 0]$, $b = [1, 2, 2, 0, 1]$, total $= 6$.

Min cost $= -32$, so maximum coins $= 32$.

## Complexity

- **Time:** $O(F \cdot E \cdot V)$ worst case with SPFA, very fast in practice with $n = 50$
- **Memory:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Grid%20Puzzle%20II.cpp)
