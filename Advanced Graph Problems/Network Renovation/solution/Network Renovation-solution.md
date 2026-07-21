# Network Renovation - Solution

**ID:** 1704 | **URL:** https://cses.fi/problemset/task/1704

## Approach

### Problem Restatement

Given a tree of $n$ nodes, add the minimum number of edges so that the graph remains connected after removing any single edge (make it 2-edge-connected).

### Core idea

In a tree, every edge is a bridge. To eliminate all bridges, we add edges that create cycles covering every bridge. The key insight: collecting leaves in DFS order and pairing leaf $i$ with leaf $i + \lceil L/2 \rceil$ guarantees the two leaves in each pair belong to different subtrees of the root (since DFS visits leaves of each subtree consecutively, and the offset $L/2$ always crosses a subtree boundary). Each such pair creates a cycle through the root, protecting all bridges on both root-to-leaf paths. Each new edge protects at most 2 leaf-bridges, so $\lceil L/2 \rceil$ edges are both necessary (lower bound) and sufficient (upper bound).

### Algorithm

1. DFS from any root, collect all leaves (degree-1 nodes, except root) in visit order into list `Leaf`.
2. If $L$ is odd, append `Leaf[0]` to the end.
3. Output $L/2$ edges: pair `Leaf[i]` with `Leaf[i + L/2]` for $0 \le i < L/2$.

### Example

Tree: 1-2, 1-3, 3-4, 3-5. Leaves in DFS order: [2, 4, 5]. $L=3$ (odd) → [2, 4, 5, 2]. Pairs: (2, 5), (4, 2). Output: 2 edges.

## Complexity

- **Time:** $O(n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Network%20Renovation.cpp)
