# Distinct Values Subarrays II - Solution

**ID:** 2428 | **URL:** https://cses.fi/problemset/task/2428

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of subarrays with at most $k$ distinct values.

### Core Idea

If subarray $[l, r]$ has $\le k$ distinct values then every subarray within it also does — this monotonicity enables two pointers. Maintain a sliding window $[l, i]$ where $l$ is the leftmost position such that the window has $\le k$ distinct values. Use map `M` for frequencies and variable `diff` for the count of distinct values. When adding $a[i]$ causes `diff` to exceed $k$, advance $l$ rightward and decrement frequencies until `diff ≤ k`. At that point, $l$ is the leftmost valid position because shifting it left would produce a window with $> k$ distinct values. The number of valid subarrays ending at $i$ is $i - l + 1$ (all segments $[j, i]$ with $l \le j \le i$), and each valid subarray is counted exactly once at its right endpoint.

### Algorithm

1. Initialize `l = 1`, `diff = 0`, `res = 0`, empty map `M`.
2. For $i$ from $1$ to $n$:
   - Add $a[i]$ to `M`, update `diff`.
   - While `diff > k`: decrement frequency of $a[l]$, erase from map and decrement `diff` if frequency reaches 0; increment $l$.
   - `res += i - l + 1`.
3. Output `res`.

### Example

Array $[1, 2, 3, 1, 1]$, $k = 2$.

| $i$ | $a_i$ | Window | `diff` | $l$ | Subarrays | Note |
|-----|-------|--------|--------|-----|-----------|------|
| 1 | 1 | $[1,1]$ | 1 | 1 | 1 | |
| 2 | 2 | $[1,2]$ | 2 | 1 | 2 | |
| 3 | 3 | $[2,3]$ | 2 | 2 | 2 | remove $a_1=1$ |
| 4 | 1 | $[3,4]$ | 2 | 3 | 2 | remove $a_2=2$ |
| 5 | 1 | $[3,5]$ | 2 | 3 | 3 | |

Total: $1 + 2 + 2 + 2 + 3 = \mathbf{10}$.

## Complexity

- **Time:** $O(n \log n)$ — each element added/removed from map exactly once
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Subarrays%20II.cpp)
