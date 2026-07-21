# Distinct Values Subarrays - Solution

**ID:** 3420 | **URL:** https://cses.fi/problemset/task/3420

## Approach

### Problem Restatement

Given an array of $n$ integers, count the number of subarrays where all elements are distinct.

### Core Idea

If subarray $[l, r]$ has all distinct elements then so does every subarray within it — this monotonicity enables two pointers. Scan right endpoint $i$ from left to right, maintaining `maxLeft`: the strict left boundary such that any subarray ending at $i$ must start at $j > \text{maxLeft}$. When encountering $a[i]$, update `maxLeft = max(maxLeft, Left[a[i]])` where `Left[a[i]]` is the previous occurrence of value $a[i]$. This is correct because: if $j \le \text{maxLeft}$, some value appears twice in $[j, i]$; if $j > \text{maxLeft}$, every value in $[j, i]$ appears exactly once. The count of valid subarrays ending at $i$ is $i - \text{maxLeft}$, and each valid subarray is counted exactly once at its right endpoint.

### Algorithm

1. Initialize `maxLeft = 0`, `ans = 0`, maps `Pos` and `Left`.
2. For $i$ from $1$ to $n$:
   - `Left[a[i]] = Pos[a[i]]`, `Pos[a[i]] = i`.
   - `maxLeft = max(maxLeft, Left[a[i]])`.
   - `ans += i - maxLeft`.
3. Output `ans`.

### Example

Array $[1, 2, 1, 3]$, $n = 4$.

| $i$ | $a_i$ | $\text{Left}[a_i]$ | $\text{maxLeft}$ | Subarrays | Notes |
|-----|-------|---------------------|-------------------|------------|-------|
| 1 | 1 | 0 | 0 | 1 | $\{1\}$ |
| 2 | 2 | 0 | 0 | 2 | $\{2\}, \{1,2\}$ |
| 3 | 1 | 1 | 1 | 2 | $\{1\}, \{2,1\}$ |
| 4 | 3 | 0 | 1 | 3 | $\{3\}, \{1,3\}, \{2,1,3\}$ |

Total: $1 + 2 + 2 + 3 = \mathbf{8}$.

## Complexity

- **Time:** $O(n \log n)$ — map query/update $O(\log n)$ per element
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Distinct%20Values%20Subarrays.cpp)
