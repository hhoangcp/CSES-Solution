# Subarray Sum Queries - Solution

**ID:** 1190 | **URL:** https://cses.fi/problemset/task/1190

## Approach

### Problem Restatement

Given an array of $n$ integers, after each point update, report the maximum subarray sum. Empty subarray (sum 0) is allowed.

### Core idea

Maximum subarray sum is not composable like sum/min/max — the optimal subarray may cross the boundary between two halves. To handle this, each segment tree node stores **4 values**:

- **`Sum`**: total sum of the segment.
- **`Left`**: maximum prefix sum (best subarray starting at the left boundary).
- **`Right`**: maximum suffix sum (best subarray ending at the right boundary).
- **`Max`**: maximum subarray sum within the segment.

For left child $L$ (segment $[l, mid]$) and right child $R$ (segment $[mid+1, r]$), merge as:

$$\text{Sum} = L.\text{Sum} + R.\text{Sum}$$
$$\text{Left} = \max(L.\text{Left}, L.\text{Sum} + R.\text{Left})$$
$$\text{Right} = \max(R.\text{Right}, R.\text{Sum} + L.\text{Right})$$
$$\text{Max} = \max(L.\text{Max}, R.\text{Max}, L.\text{Right} + R.\text{Left})$$

The `Max` formula is correct because any subarray in $[l, r]$ is either entirely in the left half, entirely in the right half, or crosses the boundary (left suffix + right prefix). These three cases are exhaustive and disjoint. The `Left` and `Right` formulas follow the same logic for contiguous prefixes/suffixes.

Leaves with value $v$: `Sum = Max = Left = Right = v`. Since empty subarrays are allowed, output $\max(0, \text{root.Max})$.

### Algorithm

1. **Build** segment tree, each node storing (Sum, Left, Right, Max). Leaves: all four equal $x_i$.
2. **Update** position $k$ to $x$: modify the leaf, then recompute ancestors using merge formulas.
3. **Output**: $\max(0, \text{root.Max})$ after each update.

### Example

Input:
```
5 3
1 2 -3 5 -1
2 6
3 1
2 -2
```

Array: $[1, 2, -3, 5, -1]$.

- Update position 2 to 6: array becomes $[1, 6, -3, 5, -1]$. Root Max $= 9$ (subarray $[1, 6, -3, 5]$). Answer $= \max(0, 9) = 9$.
- Update position 3 to 1: array becomes $[1, 6, 1, 5, -1]$. Root Max $= 13$ (subarray $[1, 6, 1, 5]$). Answer $= \max(0, 13) = 13$.
- Update position 2 to $-2$: array becomes $[1, -2, 1, 5, -1]$. Root Max $= 6$ (subarray $[1, 5]$). Answer $= \max(0, 6) = 6$.

Output:
```
9
13
6
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Subarray%20Sum%20Queries.cpp)
