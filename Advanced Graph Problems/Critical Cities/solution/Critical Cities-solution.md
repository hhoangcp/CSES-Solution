# Critical Cities - Solution

**ID:** 1703 | **URL:** https://cses.fi/problemset/task/1703

## Approach

### Problem Restatement

Given a directed graph with $n$ nodes and $m$ edges, find all nodes that appear on **every** path from node 1 to node $n$.

### Core idea

A node $v$ that lies on every path from 1 to $n$ is a **dominator** of $n$ with respect to source 1. The set of dominators is represented by a **dominator tree** rooted at 1, where $v$ dominates $u$ iff $v$ is an ancestor of $u$. The critical cities are exactly the nodes on the path from 1 to $n$ in the dominator tree.

**Equivalence:** If $v$ is on the dominator tree path from 1 to $n$, then $v$ dominates $n$ (by transitivity: $v$ dominates $u$ and $u$ dominates $w$ implies $v$ dominates $w$), so every path from 1 to $n$ must pass through $v$. Conversely, if $v$ is not on this path, then $v$ is not an ancestor of $n$ in the dominator tree, so $v$ does not dominate $n$, meaning there exists a path from 1 to $n$ avoiding $v$.

### Algorithm

1. Run DFS from node 1 to assign DFS numbers and build the DFS tree.
2. Apply the **Lengauer-Tarjan** algorithm: compute semidominators using union-find with path compression, process nodes in reverse DFS order, compute immediate dominators (`idom`).
3. Trace back from $n$ to 1 via `idom` — the nodes on this path are the critical cities.
4. Output the count and the list in increasing order.

### Example

$n=5$, edges: $1\to2, 2\to3, 2\to4, 3\to5, 4\to5$.

Dominator tree: 1 dominates everything, 2 dominates 3,4,5. Path from 1 to 5: $1 \to 2 \to 5$.

Critical cities: **1, 2, 5**.

## Complexity

- **Time:** $O((n + m) \cdot \alpha(n, m))$
- **Space:** $O(n + m)$

## Code (C++)

[Solution Code](../code/Critical%20Cities.cpp)
