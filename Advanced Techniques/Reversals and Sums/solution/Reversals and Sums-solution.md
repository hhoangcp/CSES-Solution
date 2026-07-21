# Reversals and Sums - Solution

**ID:** 2074 | **URL:** https://cses.fi/problemset/task/2074

## Approach

### Problem Restatement

Given an array of $n$ integers, process $m$ operations: (1) reverse a subarray $[a, b]$, or (2) compute the sum of a subarray $[a, b]$.

### Core Idea

A standard array or segment tree cannot handle reversals efficiently. A **treap with lazy propagation** supports both operations in $O(\log n)$:

**Node fields:** `key` (value), `pri` (random priority), `siz` (subtree size), `sum` (subtree sum), `rev` (lazy reversal flag).

**Lazy reversal:** To reverse range $[a, b]$, split the treap into $T_1 [1, a{-}1]$, $T_2 [a, b]$, $T_3 [b{+}1, n]$. Toggle `rev` on $T_2$'s root, then merge back. When a node $v$ with `rev = true` is encountered during split/merge, propagate: swap its left/right children, flip `rev` on both children, and clear $v$'s flag. This correctly reverses the in-order traversal — if $T(v) = T(L) \circ [k] \circ T(R)$, then after swapping children and pushing `rev` to both, the traversal becomes $T^R(R) \circ [k] \circ T^R(L) = T^R(v)$. The `sum` field is unaffected since reversal only reorders elements without changing the multiset.

**Sum query:** Split similarly; $T_2 \to \text{sum}$ gives the answer directly.

### Algorithm

1. Build a treap from the array (insert elements one by one).
2. For each operation:
   - **Type 1 (reverse $[u, v]$):** Split into $T_1, T_2, T_3$. Set $T_2 \to \text{rev} \mathrel{\wedge}= \text{true}$. Merge back.
   - **Type 2 (sum $[u, v]$):** Split into $T_1, T_2, T_3$. Output $T_2 \to \text{sum}$. Merge back.
3. Always call `Reverse(P)` before accessing children in split/merge, and `Update_node` after structural changes.

### Example

Array: $[2, 1, 3, 4, 5, 3, 4, 4]$.

| Step | Operation | Result |
|------|-----------|--------|
| 1 | Sum $[2, 4]$: $1 + 3 + 4$ | **8** |
| 2 | Reverse $[3, 6]$: $[3,4,5,3] \to [3,5,4,3]$ | Array: $[2, 1, 3, 5, 4, 3, 4, 4]$ |
| 3 | Sum $[2, 4]$: $1 + 3 + 5$ | **9** |

## Complexity

- **Time:** $O((n + m) \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Reversals%20and%20Sums.cpp)
