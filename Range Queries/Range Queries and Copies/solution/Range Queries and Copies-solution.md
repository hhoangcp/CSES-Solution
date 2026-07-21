# Range Queries and Copies - Solution

**ID:** 1737 | **URL:** https://cses.fi/problemset/task/1737

## Approach

### Problem Restatement

Maintain a list of arrays, initially with one array of $n$ elements. Process $q$ queries:
1. Set value at position $a$ in array $k$ to $x$.
2. Calculate sum of range $[a, b]$ in array $k$.
3. Create a copy of array $k$ and append it to the list.

### Core idea

Copying a regular segment tree costs $O(n)$, giving $O(qn)$ worst case — too slow and too much memory. A **persistent segment tree** allows copying in $O(1)$ by sharing unchanged subtrees.

Each node stores `Left`, `Right` pointers and `sum`. Maintain an array `ver[]` of root pointers, where `ver[k]` is the root of array $k$.

**Copy** (type 3): simply `ver[++cur] = ver[k]` — copy the root pointer. Since persistent tree nodes are never modified after creation, both arrays share the same tree safely. If array $k$ is later updated, a new root is created for `ver[k]` but `ver[new]` still points to the old root — unaffected.

**Update** (type 1): use **path copying**. Create new nodes only on the path from root to leaf $p$, setting the leaf to the new value and recomputing `sum = Left->sum + Right->sum` upward. Unchanged branches are shared with the old version. Replace `ver[k] = new_root`. This is an in-place update to array $k$, but other arrays sharing the old root are unaffected since old nodes are never modified.

**Query** (type 2): standard segment tree range sum on the tree rooted at `ver[k]` — $O(\log n)$.

### Algorithm

1. **Build** persistent segment tree for the initial array. Set `ver[1]` to its root.
2. **Update** $x_k = x$: path-copy from `ver[k]` to leaf $p$, set leaf to $x$, recompute sums upward. Replace `ver[k]` with the new root.
3. **Query** sum $[a, b]$ on `ver[k]`: standard range sum query — $O(\log n)$.
4. **Copy** array $k$: `ver[++cur] = ver[k]` — $O(1)$.

### Example

Input:
```
5 6
2 3 1 2 5
3 1
2 1 1 5
2 2 1 5
1 2 2 5
2 1 1 5
2 2 1 5
```

Initial array: $[2, 3, 1, 2, 5]$.

- Copy array 1 → array 2: `ver[2] = ver[1]`. Both share the same tree.
- Query $[1,5]$ on array 1: $2+3+1+2+5 = 13$.
- Query $[1,5]$ on array 2: $13$ (shared tree).
- Update position 2 in array 2 to 5: path-copy creates new root for `ver[2]`. Array 2 becomes $[2, 5, 1, 2, 5]$. Array 1's tree is unchanged.
- Query $[1,5]$ on array 1: still $13$ (old root untouched).
- Query $[1,5]$ on array 2: $2+5+1+2+5 = 15$.

Output:
```
13
13
13
15
```

## Complexity

- **Time:** $O(n + q \log n)$
- **Space:** $O(n + q \log n)$

## Code (C++)

[Solution Code](../code/Range%20Queries%20and%20Copies.cpp)
