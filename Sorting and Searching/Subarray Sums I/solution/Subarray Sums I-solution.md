# Subarray Sums I - Solution

**ID:** 1660 | **URL:** https://cses.fi/problemset/task/1660

## Problem Statement

Given an array of $n$ positive integers $a_1, a_2, \ldots, a_n$ and a positive integer $x$, count the number of contiguous subarrays whose element sum equals $x$.

## Approach

### Core idea

Since every $a_i \ge 1$, the sum of a segment strictly increases as we extend it to the right and strictly decreases as we shrink it from the left. This monotonicity lets us use **two pointers**:

- For each right endpoint $r$, sliding the left pointer `left` rightward only decreases the segment sum $[\text{left}, r]$, so there is at most one `left` giving sum exactly $x$ — no frequency table or duplicate handling is needed.
- As $r$ grows, the valid `left` never moves leftward (adding an element only increases the sum, so `left` stays put or advances). Thus both pointers sweep the array in a single pass.

### Algorithm

Maintain the current window sum `sum` and a left pointer `left`:

1. Initialize `left = 1`, `sum = 0`, `ans = 0`.
2. For each $r$ from $1$ to $n$:
   - Add $a_r$ to `sum`.
   - While `sum > x` and `left <= r`: subtract $a_{\text{left}}$ from `sum`, then increment `left`.
   - If `sum == x`: increment `ans`.
3. Output `ans`.

Each valid subarray is counted exactly once, at its right endpoint.

## Example

Consider $n = 5$, $x = 7$, array $a = [2, 4, 1, 2, 7]$.

| $r$ | $a_r$ | `sum` after add | after shrink | `left` | `ans` |
| --- | --- | --- | --- | --- | --- |
| 1 | 2 | 2 | 2 | 1 | 0 |
| 2 | 4 | 6 | 6 | 1 | 0 |
| 3 | 1 | 7 | 7 | 1 | 1 |
| 4 | 2 | 9 | 7 | 2 | 2 |
| 5 | 7 | 14 | 7 | 5 | 3 |

At $r=4$, adding $a_4=2$ raises the sum to $9>7$, so we drop $a_1=2$ (`left` $\to 2$), bringing the sum back to $7$. At $r=5$, the sum reaches $14>7$, so we drop $a_2, a_3, a_4$ in turn (`left` $\to 5$), sum returns to $7$. The three matching subarrays are $[1,3]$, $[2,4]$, and $[5,5]$, each summing to $7$.

## Complexity

- **Time:** $O(n)$ — each element is added to `sum` once (by $r$) and removed at most once (by `left`); at most $2n$ operations total.
- **Memory:** $O(n)$ to store the array.
