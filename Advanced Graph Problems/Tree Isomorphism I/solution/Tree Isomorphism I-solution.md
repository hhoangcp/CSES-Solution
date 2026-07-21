# Tree Isomorphism I - Solution

**ID:** 1700 | **URL:** https://cses.fi/problemset/task/1700

## Approach

### Problem Restatement

Given two rooted trees (rooted at node 1), determine if they are isomorphic — i.e., they have the same structure when node labels are ignored.

### Core idea

Two rooted trees are isomorphic iff their children's subtrees can be paired up isomorphically. This gives a recursive hashing scheme: compute a unique ID for each subtree based on the sorted list of its children's IDs. Two subtrees get the same ID iff isomorphic (provable by structural induction: leaves share the empty-list ID; for internal nodes, equal sorted multisets of child IDs ↔ bijective pairing of isomorphic children). Since child order doesn't matter, sort the ID list before lookup. Use a global `map<vector<int>, int>` to assign IDs — same sorted list always maps to same ID.

### Algorithm

1. For each tree, run DFS from the root.
2. At each node: collect children's IDs into a vector, sort it, look up or create a new ID in the global map.
3. The trees are isomorphic iff the roots have the same ID.

### Example

Tree 1: path 1-2-3. Tree 2: star 1-{2,3}. Node 2 in tree 1 is internal (has child), node 2 in tree 2 is a leaf — different IDs at root → NO.

Tree 1: path 1-2-3. Tree 2: path 1-3-2. Same structure → YES.

## Complexity

- **Time:** $O(n \log n)$ — sorting children IDs at each node; total cost $\sum O(d_u \log d_u) \leq O(n \log n)$
- **Space:** $O(n)$ for the tree and hash map

## Code (C++)

[Solution Code](../code/Tree%20Isomorphism%20I.cpp)
