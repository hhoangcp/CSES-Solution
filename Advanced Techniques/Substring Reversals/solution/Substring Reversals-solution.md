# Substring Reversals - Solution

**ID:** 2073 | **URL:** https://cses.fi/problemset/task/2073

## Approach

### Problem Restatement

Given a string of length $n$ and $m$ operations, each specifying a range $[a, b]$, reverse the substring from position $a$ to $b$. Output the final string.

### Core Idea

Naive reversal takes $O(n)$ per operation, totaling $O(nm)$. A **treap with lazy reversal** supports each operation in $O(\log n)$:

**Lazy reversal:** To reverse substring $[a, b]$, split the treap into $T_1 [1, a{-}1]$, $T_2 [a, b]$, $T_3 [b{+}1, n]$, toggle `rev` on $T_2$, then merge back. When a node with `rev = true` is encountered during split/merge/traversal, propagate: swap its left/right children, flip `rev` on both children, and clear the current flag. This correctly reverses the in-order traversal of $T_2$'s subtree without modifying each node individually, and `Reverse` is always called before accessing children to ensure structural consistency.

The random priority maintains expected $O(\log n)$ tree height, so split and merge are $O(\log n)$.

### Algorithm

1. Build a treap from the string (each node stores its original character index).
2. For each operation $(u, v)$:
   - Split at position $v+1$ → $T_2, T_3$. Split $T_2$ at $u$ → $T_1, T_2$.
   - Toggle `rev` on $T_2$.
   - Merge: `root = merge(merge(T1, T2), T3)`.
3. Traverse in-order (with lazy propagation) to output the final string.

### Example

String: `AYBABTU`, operations: $(3,4)$ then $(4,7)$.

| Step | Operation | Substring reversed | Result |
|------|-----------|-------------------|--------|
| 1 | Reverse $[3,4]$ | `BA` → `AB` | `AYABBTU` |
| 2 | Reverse $[4,7]$ | `BBTU` → `UTBB` | `AYAUTBB` |

Final string: **AYAUTBB**

## Complexity

- **Time:** $O((n + m) \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Substring%20Reversals.cpp)
