# Array Division - Solution

**ID:** 1085 | **URL:** https://cses.fi/problemset/task/1085

## Approach

### Problem Restatement

Given an array of $n$ positive integers, divide it into $k$ contiguous subarrays so that the maximum subarray sum is minimized. Find that minimum value.

### Core Idea

Let $g(S)$ be the minimum number of contiguous subarrays needed when limiting each subarray's sum to $\le S$. Since a larger $S$ allows more elements per subarray, $g(S)$ is non-increasing. We need the smallest $S$ with $g(S) \le k$ — a classic binary search on answer.

To evaluate $g(S)$, use a greedy strategy: scan left to right, accumulate elements into the current subarray, and cut whenever adding the next element would exceed $S$. This greedy is optimal because it extends each subarray as far as possible — by induction, every greedy cut point $d_i$ satisfies $d_i \ge c_i$ (where $c_i$ is a cut point of any valid partition), so the greedy never produces more subarrays than needed.

### Algorithm

1. Set $L = \max(a_i)$, $R = \sum a_i$.
2. Binary search on $S$ in $[L, R]$:
   - For each $mid$, greedily count subarrays with sum $\le mid$.
   - If count $\le k$: $S$ is feasible; record answer, search lower half.
   - Otherwise: search upper half.
3. Note: sums can reach $2 \times 10^{14}$, use 64-bit integers.

### Example

$n = 5$, $k = 3$, $a = [2, 4, 7, 3, 5]$.

$L = 7$, $R = 21$. Binary search in $[7, 21]$.

Check $S = 8$: greedy produces $[2,4] \mid [7] \mid [3,5]$ → 3 subarrays $\le k = 3$. Feasible.

Check $S = 7$: greedy produces $[2,4] \mid [7] \mid [3] \mid [5]$ → 4 subarrays $> k = 3$. Not feasible.

Answer: **8**.

## Complexity

- **Time:** $O(n \log(\sum a_i))$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Array%20Division.cpp)
