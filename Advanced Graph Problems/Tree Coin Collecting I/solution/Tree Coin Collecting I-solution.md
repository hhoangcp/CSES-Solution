# Tree Coin Collecting I - Solution

**ID:** 3114 | **URL:** https://cses.fi/problemset/task/3114

## Approach

### Problem Restatement

Given a tree with $n$ nodes where some nodes contain a coin, answer $q$ queries: what is the shortest path from node $a$ to node $b$ that visits at least one coin node?

### Core idea

Any path from $a$ to $b$ visiting a coin can be decomposed as: follow the unique $a$-$b$ path, detour at some node $x$ on this path to the nearest coin (distance $\text{val}[x]$), return to $x$, then continue. This adds $2 \cdot \text{val}[x]$ to $\text{dist}(a, b)$. We can always choose $x$ on the $a$-$b$ path: if the detour visits a coin via node $w$ outside the path, the path from $w$ reconnects to the $a$-$b$ path at some node $y$, and $\text{val}[y] \leq \text{dist}(y, w) + 0$ (since $w$ is or leads to a coin), so detouring at $y$ is no worse. The optimal detour point is the node with minimum $\text{val}$ on the $a$-$b$ path. Answer $= \text{dist}(a, b) + 2 \cdot \min_{x \in \text{path}(a,b)} \text{val}[x]$.

### Algorithm

1. **Multi-source BFS** from all coin nodes to compute $\text{val}[v]$ (distance from $v$ to nearest coin).
2. **Binary lifting preprocessing:** build ancestor table `par[v][i]` and path-min table `mn[v][i]` = minimum `val` on path from $v$ to its $2^i$-th ancestor.
3. **Query $(a, b)$:** compute LCA, then $\text{dist}(a, b) = \text{depth}[a] + \text{depth}[b] - 2 \cdot \text{depth}[\text{LCA}]$. Compute path minimum by lifting $a$ and $b$ to LCA and taking the min (including `val[LCA]`). Answer = dist + 2 × path_min.

### Example

$n=5$, coins at {1, 4}. val: [0, 1, 1, 0, 2]. Query (1, 5): dist=2, path_min = min(0, 1, 2) = 0, answer = 2.

## Complexity

- **Time:** $O(n \log n + q \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/Tree%20Coin%20Collecting%20I.cpp)
