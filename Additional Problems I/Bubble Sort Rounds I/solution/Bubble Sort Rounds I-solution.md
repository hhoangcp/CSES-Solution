# Bubble Sort Rounds I - Solution

**ID:** 3151 | **URL:** https://cses.fi/problemset/task/3151

## Problem Statement

Given an array of $n$ integers, compute the number of rounds of left-to-right scanning in Bubble Sort required for the array to become fully sorted.

## Approach

### 1. Displacement mechanism in Bubble Sort

In one round of Bubble Sort scanning from position $0$ to $n-1$:

- **Rightward displacement:** A large element can "sink" continuously toward the end of the array and change many positions in a single round if it is consistently larger than its adjacent successors.
- **Leftward displacement:** An element can shift left by at most 1 position per round. This happens when it is smaller than the element immediately to its left and a swap is performed.

### 2. Key insight

Since each round only allows an element to "nudge" left by 1 unit, the time for the array to be sorted depends on the element that needs to move left the most.

**Formula:**

- Let $pos_{old}$ be the initial position of a value in the unsorted array.
- Let $pos_{new}$ be the position of that value in the sorted array.
- The number of rounds needed for this element to reach its correct position is $(pos_{old} - pos_{new})$.
- The final answer is the maximum of this difference over the entire array: $Ans = \max(0, \max_i(pos_{old_i} - pos_{new_i}))$.

### 3. Proof of correctness

**Lower bound:** An element at position $i$ that needs to reach position $j$ (with $i > j$) must go through at least $i - j$ rounds, since it can only move left 1 step per round.

**Upper bound:** Large elements shifting right are not limited in the number of steps per round, so they are never the "bottleneck" preventing sorting. Small elements (needing to shift left) do not block each other either: if two elements both need to shift left, the one further left reaches its destination first or simultaneously, without slowing down the element behind it.

### Example

Consider the array: `3 2 4 1 4` (0-indexed from $0$ to $4$).

Sorted array: `1 2 3 4 4`.

| Value | Old index ($pos_{old}$) | New index ($pos_{new}$) | Displacement ($pos_{old} - pos_{new}$) |
|-------|------------------------|------------------------|----------------------------------------|
| 3 | 0 | 2 | $-2$ |
| 2 | 1 | 1 | $0$ |
| 4 | 2 | 3 | $-1$ |
| 1 | 3 | 0 | $3$ |
| 4 | 4 | 4 | $0$ |

The maximum displacement is $3$, so 3 rounds are needed to sort the array.

## Complexity

- **Time:** $O(n \log n)$ — Dominated by sorting the initial array to determine each element's destination position.
- **Memory:** $O(n)$ — Storage for the original array and sorted array (or value-index pairs).

## Code (C++)

[Solution Code](../code/Bubble%20Sort%20Rounds%20I.cpp)
