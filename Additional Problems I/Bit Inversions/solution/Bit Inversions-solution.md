# Bit Inversions - Solution

**ID:** 1188 | **URL:** https://cses.fi/problemset/task/1188

## Problem Statement

Given a bit string of length $n$ and $m$ requests to flip a bit (0 to 1, 1 to 0) at position $x_i$, find the length of the longest consecutive substring of identical bits (all 0s or all 1s) after each flip.

## Approach

### 1. Data Structure: Segment Tree

To manage the longest identical-bit substring within a range, each node in the segment tree stores the following information to support merging two child nodes:

- `longest`: Length of the longest run of identical bits entirely within the segment.
- `Left_0`, `Left_1`: Length of the longest consecutive all-0 (or all-1) run starting from the left boundary.
- `Right_0`, `Right_1`: Length of the longest consecutive all-0 (or all-1) run ending at the right boundary.
- `all_0`, `all_1`: Boolean flags indicating whether the entire segment is all 0s or all 1s.

### 2. Merge operation for two child nodes

When merging left child $A$ and right child $B$ into parent $P$, the longest run can occur in 3 positions:

- Entirely within $A$ ($A.\text{longest}$).
- Entirely within $B$ ($B.\text{longest}$).
- Spanning the boundary between $A$ and $B$. This happens when $A$ ends with the same bit that $B$ starts with:
  - If bit 0: Length is $A.\text{Right\_0} + B.\text{Left\_0}$.
  - If bit 1: Length is $A.\text{Right\_1} + B.\text{Left\_1}$.

Thus $P.\text{longest} = \max(A.\text{longest}, B.\text{longest}, A.\text{Right\_0} + B.\text{Left\_0}, A.\text{Right\_1} + B.\text{Left\_1})$.

For boundary attributes: if $A$ is entirely one type of bit, the run starting from the left boundary can extend into $B$. For example, if $A$ is all 0s, then $P.\text{Left\_0} = A.\text{longest} + B.\text{Left\_0}$; otherwise $P.\text{Left\_0} = A.\text{Left\_0}$. Similarly for `Left_1`, `Right_0`, `Right_1`.

### 3. Update and Query

- **Update (Modify):** When flipping the bit at position $p$, navigate to the corresponding leaf on the segment tree and swap `all_0`/`all_1`. Then propagate changes upward to all ancestor nodes using the merge function. Flipping a leaf changes exactly one position, and all ancestor nodes are correctly recomputed by the merge function.
- **Query:** The answer after each flip is simply the `longest` value at the root node (covering range $[1, n]$).

Instead of rescanning the entire string in $O(n)$ after each flip, the Segment Tree processes each query in $O(\log n)$.

### Example

Initial string: `001011`. Longest identical-bit run: `00` (or `11`), length 2.

| Operation | String after flip | Longest run | Length |
|-----------|-------------------|-------------|--------|
| Flip position 3 | `000011` | `0000` | 4 |
| Flip position 2 | `010011` | `00` or `11` | 2 |
| Flip position 5 | `010001` | `000` | 3 |

## Complexity

- **Time:** $O((n + m) \log n)$, where $n$ is the string length and $m$ is the number of queries.
- **Memory:** $O(n)$ (typically $4n$ for the segment tree array).

## Code (C++)

[Solution Code](../code/Bit%20Inversions.cpp)
