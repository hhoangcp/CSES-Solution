# Reversal Sorting - Solution

**ID:** 2075 | **URL:** https://cses.fi/problemset/task/2075

## Problem Statement

Given a permutation of $1, 2, \ldots, n$, sort it in increasing order by reversing subarrays. Use at most $n$ reversals.

## Approach

### Core idea
Process each position $i = 1, 2, \ldots, n$. If position $i$ already contains value $i$, skip. Otherwise, find the current position $p$ of value $i$ and reverse $[i, p]$. Reversing $[i, p]$ maps position $j$ to $i+p-j$; specifically $p \to i$, so value $i$ moves to position $i$. Elements before $i$ are unaffected, and since subsequent reversals start after position $i$, value $i$ never moves again. After $n$ positions, the array is fully sorted with at most $n$ reversals.

### Data structure: Treap with lazy reversal
Naive array reversal costs $O(n)$ per operation. A treap (randomized BST) supports all operations in $O(\log n)$:
- **Split & Merge:** Split the tree at any position and merge back.
- **Lazy reversal flag (`rev`):** Mark segments for reversal; only swap left/right children when accessed (push down).
- **Find position (`Find_pos`):** Maintain parent pointers (`Par`). Climb from node `Pos[x]` to root, push lazy flags, count left subtree sizes to determine exact position.

### Algorithm
1. Build treap from the input permutation.
2. For $i = 1$ to $n$:
   - Find value at position $i$. If $i$, skip.
   - Find position $p$ of value $i$ using `Find_pos(i)`.
   - Record reversal $(i, p)$.
   - Split treap into 3 parts at $i$ and $p+1$, flip lazy reversal flag on the middle part, merge back.
3. Output the number of reversals and the segment details.

### Example

Permutation $[2,3,1,4]$.

- $i=1$: value 1 at position 3. Reverse $[1,3]$: $[1,3,2,4]$.
- $i=2$: value 2 at position 3. Reverse $[2,3]$: $[1,2,3,4]$.

Result: 2 reversals: `1 3` and `2 3`.

## Complexity

- **Time:** $O(n \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Reversal%20Sorting.cpp)
