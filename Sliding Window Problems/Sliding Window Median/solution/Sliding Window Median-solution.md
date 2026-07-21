# Sliding Window Median - Solution

**ID:** 1076 | **URL:** https://cses.fi/problemset/task/1076

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, find the median — the $\lfloor(k+1)/2\rfloor$-th smallest element (lower median when $k$ is even).

### Core Idea

Use an order-statistic segment tree over coordinate-compressed values. Each node stores the count of elements in its value range, supporting insert/delete and rank-based lookup in $O(\log n)$. As the window slides, remove the departing element and add the new one, then query the $\lfloor(k+1)/2\rfloor$-th smallest.

### Algorithm

**Step 1: Coordinate compression.** Sort and deduplicate all values, then map each element to its rank in $[0, n-1]$. This allows building a segment tree over $[0, n-1]$ instead of $[0, 10^9]$.

**Step 2: Order-statistic segment tree.** Each node stores the count of elements in its value range. Two operations:
- **Update** $(p, val)$: Add ($val = 1$) or remove ($val = -1$) an element at compressed position $p$.
- **Find by rank** $(pos)$: Walk down from the root. If the left child has $\ge pos$ elements, the $pos$-th smallest must be in the left subtree (all left values are smaller). Otherwise, recurse right with $pos - \text{count\_left}$. At a leaf, return the original value.

**Step 3: Slide the window.** For each position $i$:
1. Remove departing element: `Update(a[i-k], -1)` when $i > k$.
2. Add new element: `Update(a[i], 1)`.
3. Query median when $i \ge k$: `Find((k+1)/2)`. Integer division automatically gives the lower median for even $k$.

### Example

With $n=8$, $k=3$, array $[2, 4, 3, 5, 8, 1, 2, 1]$:

Compressed values: $\{1,2,3,4,5,8\}$ → ranks $0,1,2,3,4,5$.

- Window $[2,4,3]$: 2nd smallest = **3**
- Window $[4,3,5]$: 2nd smallest = **4**
- Window $[3,5,8]$: 2nd smallest = **5**
- Window $[5,8,1]$: 2nd smallest = **5**
- Window $[8,1,2]$: 2nd smallest = **2**
- Window $[1,2,1]$: 2nd smallest = **1**

Output: `3 4 5 5 2 1`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Median.cpp)
