# List Removals - Solution

**ID:** 1749 | **URL:** https://cses.fi/problemset/task/1749

## Approach

### Problem Restatement

Given a list of $n$ integers, remove $n$ elements one by one at given positions $p_1, p_2, \ldots, p_n$ (the list renumbers after each removal). Report the value of each removed element.

### Core idea

After each removal, elements shift left and their positions change. We need to efficiently find the $k$-th active (not yet deleted) element and mark it as deleted. A **segment tree** where each node stores the count of active elements in its segment supports both operations in $O(\log n)$.

To find the $k$-th active element, traverse the tree top-down. At each internal node: if the left child's count $\ge k$, the target is in the left subtree; otherwise it's in the right subtree at position $k - \text{left count}$. This is correct because the left subtree contains exactly the first $\text{left count}$ active elements in order, so the $k$-th active element is either among them (when $k \le \text{left count}$) or among the right subtree's elements (when $k > \text{left count}$), shifted by the left count. Each step descends one level, giving $O(\log n)$ per query.

Deletion sets the leaf to 0 and propagates up, maintaining the invariant that every node stores the correct active count.

### Algorithm

1. **Build** a segment tree with all leaves initialized to 1.
2. **For each removal position** $p_i$:
   - Find the actual position: `pos = query(root, p_i)` via top-down walk.
   - Output $a[\text{pos}]$.
   - Delete: update leaf `pos` to 0 and propagate.

### Example

Input:
```
5
2 6 1 4 2
3 1 3 1 1
```

List: $[2, 6, 1, 4, 2]$. Tree: all leaves = 1, root total = 5.

- Remove pos 3: walk — left $[1,2]$ count$=2 < 3$ → right, find $(3-2)=1$-st in right → actual position 3. Output $a[3]=1$. Mark leaf 3 = 0. List: $[2, 6, 4, 2]$.
- Remove pos 1: walk — left $[1,2]$ count$=2 \ge 1$ → left → position 1. Output $a[1]=2$. Mark leaf 1 = 0. List: $[6, 4, 2]$.
- Remove pos 3: walk — left $[1,2]$ count$=1 < 3$ → right, find $(3-1)=2$-nd → position 5. Output $a[5]=2$. Mark leaf 5 = 0. List: $[6, 4]$.
- Remove pos 1: walk → position 2. Output $a[2]=6$. Mark leaf 2 = 0. List: $[4]$.
- Remove pos 1: walk → position 4. Output $a[4]=4$. Mark leaf 4 = 0.

Output: `1 2 2 6 4`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/List%20Removals.cpp)
