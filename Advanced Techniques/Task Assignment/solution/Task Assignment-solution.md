# Task Assignment - Solution

**ID:** 2129 | **URL:** https://cses.fi/problemset/task/2129

## Approach

### Problem Restatement

Given $n$ workers and $n$ tasks, where worker $i$ performs task $j$ with cost $c_{ij}$, assign each worker exactly one task (bijection) to minimize total cost. Output the optimal assignment.

### Core Idea

This is the **assignment problem** — a minimum-weight perfect bipartite matching. Model it as **min-cost flow** on a bipartite network:

- **Super source $S$** (node 1) → each worker (capacity 1, cost 0).
- Worker $i$ → task $j$ (capacity 1, cost $c_{ij}$).
- Each task → **super sink $T$** (capacity 1, cost 0).

Sending $n$ units of flow from $S$ to $T$ with minimum cost gives the optimal assignment: capacity-1 edges force each worker to send exactly 1 unit to exactly one task, and each task receives at most 1 unit, forming a valid bijection. Since every assignment corresponds to a flow of value $n$ and vice versa, minimizing flow cost is equivalent to minimizing assignment cost.

Use **Successive Shortest Augmenting Path (SSAP)** with Dijkstra + potentials: each iteration finds the cheapest augmenting path and sends 1 unit. Potentials `delta[u]` ensure reduced costs are non-negative, enabling Dijkstra even with reverse edges of negative cost.

### Algorithm

1. Build the bipartite flow network.
2. Run min-cost flow (SSAP with Dijkstra + potentials) to send $n$ units.
3. Extract assignment: for each worker node, find the saturated edge (flow = cap = 1) to a task node.
4. Output total cost and assignment pairs.

### Example

$n=4$, cost matrix:

|  | Task 1 | Task 2 | Task 3 | Task 4 |
|--|--------|--------|--------|--------|
| Worker 1 | 17 | 8 | 16 | 9 |
| Worker 2 | 7 | 15 | 12 | 19 |
| Worker 3 | 6 | 9 | 10 | 11 |
| Worker 4 | 14 | 7 | 13 | 10 |

Optimal assignment:

| Worker | Task | Cost |
|--------|------|------|
| 1 | 4 | 9 |
| 2 | 1 | 7 |
| 3 | 3 | 10 |
| 4 | 2 | 7 |

Total: $9 + 7 + 10 + 7 = \mathbf{33}$.

## Complexity

- **Time:** $O(n^3)$
- **Memory:** $O(n^2)$

## Code (C++)

[Solution Code](../code/Task%20Assignment.cpp)
