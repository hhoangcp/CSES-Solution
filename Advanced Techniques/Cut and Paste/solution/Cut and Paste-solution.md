# Cut and Paste - Solution

**ID:** 2072 | **URL:** https://cses.fi/problemset/task/2072

## Approach

### Problem Restatement

Given a string of length $n$ and $m$ operations, each specifying a range $[a, b]$ (1-indexed). Cut the substring from position $a$ to $b$ and paste it at the end. Output the final string.

### Core Idea

Each cut-paste operation naively takes $O(n)$, totaling $O(nm)$ — too slow. We need a data structure that supports splitting and merging sequences in $O(\log n)$ expected time. A **Treap** (randomized BST) provides exactly this through its `Split` and `Merge` operations.

Each "cut $[a,b]$ and paste at end" decomposes into two splits and two merges. Splitting at $b+1$ separates the prefix $[1,b]$ from the suffix $[b+1, \text{end}]$. Splitting the prefix at $a$ further separates $[1,a-1]$ from $[a,b]$. Merging $[1,a-1]$ with $[b+1,\text{end}]$ reconstructs the string without the cut segment, then merging the result with $[a,b]$ appends it at the end. This correctly produces the string after the cut-paste by construction: the middle segment is removed from its original position and placed at the end, while all other characters retain their relative order.

### Algorithm

1. Build a treap from the string: insert each character at its corresponding position.
2. For each operation $(a, b)$:
   - Split treap at position $b+1$ → $T_{\text{prefix}}$ (positions 1 to $b$), $T_{\text{suffix}}$ (positions $b+1$ to end).
   - Split $T_{\text{prefix}}$ at position $a$ → $T_{\text{left}}$ (positions 1 to $a-1$), $T_{\text{cut}}$ (positions $a$ to $b$).
   - Merge $T_{\text{left}}$ and $T_{\text{suffix}}$, then merge the result with $T_{\text{cut}}$.
3. Traverse the treap in-order to output the final string.

### Example

String: `AYBABTU`, operations: $(3,5)$, $(3,5)$.

**Operation 1 — cut [3,5] (`BAB`), paste at end:**
- Split at 6: `T_prefix` = `[A,Y,B,A,B]`, `T_suffix` = `[T,U]`
- Split `T_prefix` at 3: `T_left` = `[A,Y]`, `T_cut` = `[B,A,B]`
- Merge `T_left` + `T_suffix` = `[A,Y,T,U]`, then + `T_cut` = `[A,Y,T,U,B,A,B]`

Result: `AYTUBAB`

**Operation 2 — cut [3,5] (`TUB`), paste at end:**
- Split at 6: `T_prefix` = `[A,Y,T,U,B]`, `T_suffix` = `[A,B]`
- Split `T_prefix` at 3: `T_left` = `[A,Y]`, `T_cut` = `[T,U,B]`
- Merge `T_left` + `T_suffix` = `[A,Y,A,B]`, then + `T_cut` = `[A,Y,A,B,T,U,B]`

Result: `AYABTUB`

## Complexity

- **Time:** $O((n + m) \log n)$ — each split/merge takes $O(\log n)$ expected.
- **Memory:** $O(n)$ — one treap node per character.

## Code (C++)

[Solution Code](../code/Cut%20and%20Paste.cpp)
