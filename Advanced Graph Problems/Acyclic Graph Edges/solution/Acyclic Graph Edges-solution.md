# Acyclic Graph Edges - Solution

**ID:** 1756 | **URL:** https://cses.fi/problemset/task/1756

## Approach

### Problem Restatement

Given an undirected graph with $n$ nodes and $m$ edges, assign a direction to each edge so that the resulting directed graph is acyclic.

### Core idea

Use the node indices $1, 2, \ldots, n$ as a topological order. Orient every edge from the smaller endpoint to the larger endpoint. Every directed path then visits nodes in strictly increasing order, and a strictly increasing sequence cannot form a cycle: suppose a directed cycle $v_1 \to v_2 \to \cdots \to v_k \to v_1$ exists, then $v_1 < v_2 < \cdots < v_k < v_1$, implying $v_1 < v_1$ — a contradiction. This works for any undirected graph.

### Algorithm

For each undirected edge $\{u, v\}$:
1. If $u > v$, swap $u$ and $v$ so that $u < v$.
2. Output the directed edge $u \to v$.

### Example

Input: undirected cycle $1\text{-}2, 2\text{-}3, 3\text{-}1$.

- Edge $\{1, 2\}$: $1 < 2$, output $1 \to 2$.
- Edge $\{2, 3\}$: $2 < 3$, output $2 \to 3$.
- Edge $\{3, 1\}$: swap to $\{1, 3\}$, output $1 \to 3$.

Result: $1 \to 2, 2 \to 3, 1 \to 3$ — a valid DAG (topological order: $1, 2, 3$).

## Complexity

- **Time:** $O(m)$
- **Space:** $O(1)$ extra beyond input

## Code (C++)

[Solution Code](../code/Acyclic%20Graph%20Edges.cpp)
