# Sum of Two Values - Solution

**ID:** 1640 | **URL:** https://cses.fi/problemset/task/1640

## Problem Statement

Given an array of $n$ integers $a_1, a_2, \ldots, a_n$ and an integer $x$, find two indices at distinct positions whose sum equals $x$. If several solutions exist, output any; if none exists, output `IMPOSSIBLE`.

## Approach

### 1. Sort the array, preserving original positions

To reduce the search from $O(n^2)$ to near-linear, we need a sorted array. Since the answer requires original positions, we attach the original index to each element as a pair $(\text{value}, \text{original position})$ and sort by value in increasing order. Call the sorted array $A$.

### 2. Two-pointer technique

Thanks to the array being sorted, we use two pointers moving in opposite directions to find a pair summing to $x$:

- **Initialize:** left pointer $i = 1$, right pointer $j = n$.
- At each step, consider the sum $A[i].val + A[j].val$:
  - If $> x$: the sum is too large, decrease $j$ (`--j`).
  - If $< x$: the sum is too small, increase $i$ (`++i`).
  - If $= x$ and $i \neq j$: found the pair; output the two original positions $A[i].pos$ and $A[j].pos$ and stop.
- **Stop** when $i \ge j$.

Because the array is sorted, each step moves only one pointer in one direction, so no pair is skipped; the condition $i \neq j$ ensures two distinct positions.

## Example

Consider $n = 4$, $x = 8$, array $a = [2, 7, 5, 1]$.

After attaching indices and sorting increasingly:

$$A = [(1, 4),\ (2, 1),\ (5, 3),\ (7, 2)]$$

*(each pair is $(\text{value}, \text{original position})$)*.

- $i = 1$ (value $1$), $j = 4$ (value $7$): $1 + 7 = 8 = x$ and $i \neq j$.
- **Result:** found the pair; original positions $4$ and $2$ (i.e., $a_4 + a_2 = 1 + 7 = 8$).

## Complexity

- **Time:** $O(n \log n)$. Sorting dominates at $O(n \log n)$; the two-pointer sweep costs only $O(n)$ since each pointer moves in one direction and never backtracks.
- **Memory:** $O(n)$ to store the array of (value, original position) pairs.
