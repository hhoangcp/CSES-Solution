# Increasing Array Queries - Solution

**ID:** 2416 | **URL:** https://cses.fi/problemset/task/2416

## Approach

### Problem Restatement

Given an array of $n$ integers, process $q$ queries: minimum number of increment-by-1 operations to make subarray $[a, b]$ non-decreasing?

### Core idea

To make subarray $[l, r]$ non-decreasing, scan left to right maintaining the running maximum $\text{cur}_i = \max_{j=l}^{i} x_j$. The cost is:

$$\sum_{i=l}^{r} (\text{cur}_i - x_i) = \sum_{i=l}^{r} \text{cur}_i - \sum_{i=l}^{r} x_i$$

The second sum is a standard prefix sum query. The challenge is computing $\sum_{i=l}^{r} \text{cur}_i$ efficiently.

We process queries **offline**, scanning left boundary $l$ from $n$ down to $1$, and maintain a **monotonic stack** of positions with strictly decreasing values. When adding position $i$:

1. Pop all positions $j$ from the stack where $x_j \le x_i$ (since $x_i$ dominates them), removing their deltas from the BIT.
2. Let $\text{next}[i]$ be the next position on the stack with value $> x_i$. Position $i$ is the running maximum for all positions in $[i, \text{next}[i] - 1]$. The contribution is:
   $$\text{delta}[i] = (\text{next}[i] - i - 1) \cdot x_i - \sum_{j=i+1}^{\text{next}[i]-1} x_j$$
   This equals the total operations to raise all elements between $i$ and $\text{next}[i]$ to at least $x_i$.
3. Push $i$ onto the stack and add $\text{delta}[i]$ to the BIT at position $i$.

For a query $(l, r)$ when $l$ is the current boundary: find on the stack the position $p$ that covers $r$ (the last stack entry $\le r$). The answer is the BIT range sum over full blocks before $p$, plus the partial contribution from $p$ to $r$:

$$(r - p) \cdot x_p - \sum_{j=p+1}^{r} x_j$$

### Algorithm

1. **Preprocess:** Compute prefix sums. Group queries by left boundary $l$. Initialize sentinel $x_{n+1} = \infty$ on the stack.
2. **Scan** $i$ from $n$ down to $1$: maintain monotonic stack and BIT as described above. For each query $(l, r)$ with $l = i$, compute the answer using binary search on the stack for partial contributions and BIT for full-block contributions.
3. **Output** results in original query order.

### Example

Input:
```
5 3
2 10 4 2 5
3 5
2 2
1 4
```

Array: $[2, 10, 4, 2, 5]$.

- Query $[3, 5]$: subarray $[4, 2, 5]$. Running max: $4, 4, 5$. Cost: $(4-4) + (4-2) + (5-5) = 2$.
- Query $[2, 2]$: subarray $[10]$. Already non-decreasing. Cost: 0.
- Query $[1, 4]$: subarray $[2, 10, 4, 2]$. Running max: $2, 10, 10, 10$. Cost: $0 + 0 + 6 + 8 = 14$.

Output:
```
2
0
14
```

## Complexity

- **Time:** $O((n + q) \log n)$
- **Space:** $O(n + q)$

## Code (C++)

[Solution Code](../code/Increasing%20Array%20Queries.cpp)
