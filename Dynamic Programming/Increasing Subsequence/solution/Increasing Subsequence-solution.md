# Increasing Subsequence - Solution

**ID:** 1145 | **URL:** https://cses.fi/problemset/task/1145

## Approach

### Problem Restatement

Given an array of $n$ integers ($1 \le n \le 2 \times 10^5$), find the length of the longest strictly increasing subsequence (LIS).

### Core Idea

The $O(n^2)$ DP — $dp[i] = 1 + \max_{j<i, a_j<a_i} dp[j]$ — is too slow. We need an $O(n \log n)$ approach.

Maintain an array `tails` where `tails[k]` stores the **smallest possible tail value** of any increasing subsequence of length $k+1$ found so far. The key insight: keeping tails as small as possible maximizes the chance of extending subsequences with future elements.

**Why this works (two invariants):**

1. **`tails` is always strictly increasing.** By induction: appending $a$ preserves it since $a$ exceeds all elements; replacing `tails[p]` with $a$ preserves it since `tails[p-1] < a` (`lower_bound` guarantees this) and $a \le$ old `tails[p]` $\le$ `tails[p+1]`.

2. **After processing $k$ elements, `tails[len-1]` is the smallest tail of any increasing subsequence of length `len` within those $k$ elements.** By induction: if $a$ replaces `tails[p]`, then `tails[p-1] < a` gives a subsequence of length $p$ ending below $a$, so appending $a$ yields length $p+1$ ending at $a$; since `lower_bound` finds the first position $\geq a$, no subsequence of length $p+1$ ends below $a$.

These invariants guarantee the final length of `tails` equals the LIS length.

### Algorithm

For each element $a$ in the array:
1. Find the first position $p$ in `tails` where `tails[p]` $\geq a$ (binary search / `lower_bound`).
2. If found: replace `tails[p]` with $a$.
3. If not found (all values $< a$): append $a$ to `tails`.

The answer is the length of `tails`.

### Example

Input array: $[7, 3, 5, 3, 6, 2, 9, 8]$

| Element | `tails` after processing | Action |
|---------|--------------------------|--------|
| 7 | $[7]$ | Append |
| 3 | $[3]$ | Replace 7 |
| 5 | $[3, 5]$ | Append |
| 3 | $[3, 5]$ | Replace 3 (no change) |
| 6 | $[3, 5, 6]$ | Append |
| 2 | $[2, 5, 6]$ | Replace 3 |
| 9 | $[2, 5, 6, 9]$ | Append |
| 8 | $[2, 5, 6, 8]$ | Replace 9 |

Result: LIS length = $4$ (e.g., $3, 5, 6, 8$).

## Complexity

- **Time:** $O(n \log n)$ — each element performs one binary search in $O(\log n)$.
- **Space:** $O(n)$ for the `tails` array.

## Code (C++)

[Solution Code](../code/Increasing%20Subsequence.cpp)
