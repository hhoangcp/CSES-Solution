# Sliding Window Inversions - Solution

**ID:** 3223 | **URL:** https://cses.fi/problemset/task/3223

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, count the number of inversions (pairs $(i,j)$ with $i < j$ and $a_i > a_j$).

### Core Idea

When the window slides right by one position, only one element enters and one leaves. Maintain a running inversion count and update it incrementally using a Fenwick tree (BIT). Each inversion $(p,q)$ is added when $q$ enters the window and removed when $p$ leaves — no double-counting or missing.

### Algorithm

**Step 1: Coordinate compression.** Since values can be up to $10^9$, sort and deduplicate all values, then map each element to its rank in $[1, sz]$. This allows using a BIT over the range $[1, n]$.

**Step 2: Incremental update with BIT.** Maintain running count `tot`. Process each position $i$ from left to right:

1. **Add** $a[i]$: new inversions are elements already in the window greater than $a[i]$. $\Delta_+ = \min(i-1, k) - \text{query}(a[i])$, where $\text{query}(v)$ returns the count of elements $\le v$. Then $\text{update}(a[i], 1)$.
2. **Remove** $a[i-k]$ (when $i > k$): lost inversions are elements still in the window smaller than $a[i-k]$. $\Delta_- = \text{query}(a[i-k] - 1)$. Then $\text{update}(a[i-k], -1)$.
3. **Output** `tot` when $i \ge k$.

Each inversion $(p,q)$ exists only when both $p$ and $q$ are in the window. It is added when $q$ enters (counted by $\Delta_+$) and removed when $p$ leaves (counted by $\Delta_-$). Thus `tot` always equals the current inversion count.

### Example

With $n=8$, $k=3$, array $[1, 2, 3, 2, 5, 2, 4, 4]$ (compressed to $[1, 2, 3, 2, 5, 2, 4, 4]$):

- $i=1$: add 1, tot=0
- $i=2$: add 2, $\Delta_+ = 1 - 1 = 0$. tot=0
- $i=3$: add 3, $\Delta_+ = 2 - 2 = 0$. tot=0. Output **0**
- $i=4$: add 2, $\Delta_+ = 3 - 2 = 1$. Remove $a[1]=1$, $\Delta_- = \text{query}(0) = 0$. tot=1. Output **1**
- $i=5$: add 5, $\Delta_+ = 3 - 3 = 0$. Remove $a[2]=2$, $\Delta_- = \text{query}(1) = 0$. tot=1. Output **1**
- $i=6$: add 2, $\Delta_+ = 3 - 1 = 2$. Remove $a[3]=3$, $\Delta_- = \text{query}(2) = 2$. tot=1. Output **1**
- $i=7$: add 4, $\Delta_+ = 3 - 2 = 1$. Remove $a[4]=2$, $\Delta_- = \text{query}(1) = 0$. tot=2. Output **2**
- $i=8$: add 4, $\Delta_+ = 3 - 2 = 1$. Remove $a[5]=5$, $\Delta_- = \text{query}(4) = 3$. tot=0. Output **0**

Output: `0 1 1 1 2 0`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Inversions.cpp)
