# Range Update Queries - Solution

**ID:** 1651 | **URL:** https://cses.fi/problemset/task/1651

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries:
1. Increase each value in range $[a, b]$ by $u$.
2. What is the value at position $k$?

### Core idea

The problem has **range updates** and **point queries** — the ideal pattern for **lazy propagation** on a segment tree. A naive segment tree would need $O(n)$ per range update; lazy propagation reduces this to $O(\log n)$ by deferring updates.

Each node stores `SNode[idx]` (sum of the segment) and `Lazy[idx]` (pending per-element addition to propagate). When adding $u$ to range $[a, b]$:

- If segment $[l, r] \subseteq [a, b]$: add $u \cdot (r-l+1)$ to `SNode[idx]` and $u$ to `Lazy[idx]`. No need to recurse further — every element in this segment increases by $u$, so the sum increases by $u$ times the segment length.
- Otherwise: push lazy down to children, then recurse into both. After recursion, `SNode[idx] = SNode[2*idx] + SNode[2*idx+1]`.

**Push down** distributes `Lazy[idx]` to children: each child receives `Lazy[idx]` added to its lazy value and `Lazy[idx] * (child_length)` added to its sum. The total addition is conserved: $u \cdot (r-l+1) = u \cdot (mid-l+1) + u \cdot (r-mid)$, so splitting a lazy node preserves correctness.

For **point queries**, traverse from root to the leaf at position $k$, pushing lazy down along the way. The leaf's `SNode` value is the answer.

### Algorithm

1. **Build** a segment tree storing segment sums.
2. **Range update** $[a, b]$ add $u$: standard lazy propagation — at fully covered nodes, update `SNode` and `Lazy`; at partial overlaps, push down and recurse.
3. **Point query** at $k$: traverse to leaf, pushing lazy along the path. Return the leaf value.

### Example

Input:
```
8 3
3 2 4 5 1 1 5 3
2 4
1 2 5 1
2 4
```

Array: $[3, 2, 4, 5, 1, 1, 5, 3]$.

- Query position 4: value $= 5$.
- Update add 1 to $[2, 5]$: array becomes $[3, 3, 5, 6, 2, 1, 5, 3]$.
- Query position 4: value $= 5 + 1 = 6$.

Output:
```
5
6
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Range%20Update%20Queries.cpp)
