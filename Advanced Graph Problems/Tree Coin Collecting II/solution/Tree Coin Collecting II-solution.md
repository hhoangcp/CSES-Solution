# Tree Coin Collecting II - Solution

**ID:** 3149 | **URL:** https://cses.fi/problemset/task/3149

## Approach

### Problem Restatement

Given a tree with $n$ nodes where some nodes contain a coin, answer $q$ queries: what is the shortest path from node $a$ to node $b$ that visits **all** coin nodes?

### Core idea

To visit all coins, we must traverse the entire **Steiner tree** — the minimal subtree connecting all coin nodes. A full Euler tour of this tree traverses each edge twice, costing $\text{base} = 2 \cdot (S - 1)$ where $S$ = number of Steiner nodes. When going from $a$ to $b$ (instead of returning to start), the $a$-$b$ path contains $k$ Steiner nodes (equivalently $k-1$ Steiner edges), each saving one return traversal (2 per edge). Define $\text{mask}[v] = 1$ if $v$'s subtree contains a coin, and $\text{pre}[v]$ = number of Steiner nodes on the root-to-$v$ path. For LCA $l$ of $(a, b)$: if $l$ is in the Steiner tree, the overlap $k = \text{pre}[a] + \text{pre}[b] - 2 \cdot \text{pre}[\text{par}[l]] - 1$ (Steiner nodes on the $a$-$b$ path), and answer $= \text{base} - 2(k-1) + \text{dist}(a, b)$; if $l$ is outside, we pay extra $\text{add} = \text{depth}[l] + 1 - \text{pre}[l]$ to detour into and out of the Steiner tree, and answer $= \text{base} + \text{dist}(a, b) + 2 \cdot \text{add}$.

### Algorithm

1. **Root at a coin node.** DFS to compute `mask[v]`, `depth[v]`, `pre[v]`, and binary lifting table `par[v][i]`.
2. Compute `base = 2 * (sum(mask) - 1)`.
3. For each query $(a, b)$:
   - Find $l = \text{LCA}(a, b)$ and $\text{dist}(a, b)$.
   - If $l$ is in the Steiner tree (`pre[l] == depth[l] + 1`): compute overlap $k = \text{pre}[a] + \text{pre}[b] - 2 \cdot \text{pre}[\text{par}[l]] - 1$. Answer $= \text{base} - 2(k-1) + \text{dist}(a, b)$.
   - Otherwise: compute $\text{add} = \text{depth}[l] + 1 - \text{pre}[l]$. Answer $= \text{base} + \text{dist}(a, b) + 2 \cdot \text{add}$.

### Example

$n=5$, coins at {1, 4}. Steiner nodes: {1, 2, 3, 4}, base = 6.

- Query $(1, 5)$: node 5 outside Steiner tree. Answer = 6.
- Query $(4, 4)$: dist = 0, must traverse entire Steiner tree. Answer = 6.

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n \log n)$

## Code (C++)

[Solution Code](../code/Tree%20Coin%20Collecting%20II.cpp)
