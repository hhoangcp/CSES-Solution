# Tree Isomorphism II - Solution

**ID:** 1701 | **URL:** https://cses.fi/problemset/task/1701

## Approach

### Problem Restatement

Given two unrooted trees, determine if they are isomorphic — i.e., they can be drawn to look the same when node labels are ignored.

### Core idea

For unrooted trees, we reduce to the rooted case by rooting at **centroids**. A centroid is a node whose removal leaves no component larger than $\lfloor n/2 \rfloor$; every tree has exactly 1 or 2 adjacent centroids. Any isomorphism must map centroids to centroids (since centroid-ness is structural), so we only need to check rooted isomorphism at centroid pairings. Root the first tree at its first centroid, then try rooting the second tree at each of its centroids — if any match via the recursive hashing from Tree Isomorphism I, the trees are isomorphic.

### Algorithm

1. **Find centroids** of both trees via DFS (compute subtree sizes; a node is centroid iff all its subtree sizes and $n - \text{sz}[u]$ are $\leq n/2$).
2. Root the first tree at its first centroid and compute its hash ID.
3. For each centroid of the second tree, root and compute hash. If any matches, output YES.
4. Otherwise, output NO.

### Example

$n=3$. Tree 1: path 1-2-3 (centroid {2}). Tree 2: star 1-{2,3} (centroid {1}). Root both at centroids: each has 2 leaf children → same hash → YES.

## Complexity

- **Time:** $O(n \log n)$ — centroid finding $O(n)$, hashing $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Tree%20Isomorphism%20II.cpp)
