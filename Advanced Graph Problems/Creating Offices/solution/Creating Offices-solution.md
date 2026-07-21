# Creating Offices - Solution

**ID:** 1752 | **URL:** https://cses.fi/problemset/task/1752

## Approach

### Problem Restatement

Given a tree with $n$ nodes and a minimum distance $d$, select the maximum number of nodes such that the distance between any two selected nodes is at least $d$.

### Core idea

Use a greedy DFS processed bottom-up (post-order). At each subtree, prefer keeping the deepest nodes because they lie at the "fringe" of the tree and cause fewer conflicts with other branches than nodes near the root. If two nodes $i$ and $j$ in the subtree of $u$ conflict (distance through $u$ is less than $d$), removing the shallower one is always optimal: the deeper node has more potential conflicts with ancestors, so keeping it cannot decrease the total number of selected nodes.

### Algorithm

1. Root the tree at node 1. Run DFS.
2. At each node $u$, initially mark it as selected and collect the deepest selected nodes from all children's subtrees.
3. Sort the list by depth in descending order.
4. While the two shallowest nodes violate the distance constraint (formula: $depth[i] + depth[j] - 2 \cdot depth[u] < d$), remove the shallowest one.
5. Return the deepest remaining selected node to the parent DFS level.

### Example

$n=5$, $d=3$, tree: 1-2, 2-3, 3-4, 3-5.

- At node 3: collect node 4 (depth 3) and node 5 (depth 3). Node 3 has depth 2.
- Conflict 4-5: $3+3-2\cdot2=2<3$, remove node 5.
- Conflict 4-3: $3+2-2\cdot2=1<3$, remove node 3.
- Continue up to root. Final selection: nodes 1 and 4, distance = 3.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Creating%20Offices.cpp)
