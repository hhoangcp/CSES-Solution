# K-th Highest Score - Solution

**ID:** 3305 | **URL:** https://cses.fi/problemset/task/3305

## Approach

### Problem Restatement

There are $n$ Finnish programmers and $n$ Swedish programmers, each with distinct scores. Find the $k$-th highest score overall by querying the $i$-th highest score of the Finnish (`F i`) or Swedish (`S i`), using at most 100 queries.

### Core Idea

This is a variant of "finding the $k$-th element in two sorted arrays." Let $F_1 > F_2 > \cdots > F_n$ and $S_1 > S_2 > \cdots > S_n$. If the top $k$ contains $i$ Finnish and $k-i$ Swedish, the boundary score is $\min(F_i, S_{k-i})$.

**Monotonicity:** As $i$ increases, $F_i$ decreases and $S_{k-i}$ increases (since $k-i$ decreases). So $F_i - S_{k-i}$ is monotonically decreasing in $i$. Binary search finds the transition point $l$: the smallest $i$ where $F_i \le S_{k-i}$.

**Boundary handling:** When $i = 0$, treat $F_0 = +\infty$ (always $F_0 > S_k$, so the comparison says "need more Finnish"). When $k-i = 0$, treat $S_0 = +\infty$ (always $F_i < S_0$, so the comparison says "sufficient Finnish").

**Result:** The $k$-th highest is the max of the two boundary cases at $l$ and $l-1$:

$$\max\bigl(\min(F_l, S_{k-l}),\min(F_{l-1}, S_{k-l+1})\bigr)$$

### Algorithm

1. Set $l = \max(0, k-n)$, $r = \min(k, n)$.
2. Binary search for the smallest $l$ where $F_l \le S_{k-l}$:
   - $mid = \lfloor(l+r)/2\rfloor$. Query $F_{mid}$ and $S_{k-mid}$.
   - If $F_{mid} \le S_{k-mid}$: $r = mid$.
   - Otherwise: $l = mid + 1$.
3. Compute $\min(F_l, S_{k-l})$. If $l > 0$, also compute $\min(F_{l-1}, S_{k-l+1})$.
4. Output the max of these values.

**Query count:** $\lceil\log_2 n\rceil$ steps, each with at most 2 queries, plus 2 final queries. For $n \le 10^5$: under 40 queries, well within 100.

### Example

$n = 3, k = 3$. Finnish: $[9, 4, 3]$, Swedish: $[8, 6, 1]$ (same data as the problem statement). Merged: $[9, 8, 6, 4, 3, 1]$. The 3rd highest is **6**.

- Range: $i \in [0, 3]$.
- $l=0, r=3, mid=1$: $F_1 = 9$, $S_2 = 6$. $9 > 6$ → $l = 2$.
- $l=2, r=3, mid=2$: $F_2 = 4$, $S_1 = 8$. $4 \le 8$ → $r = 2$.
- $l = r = 2$.
- At $l=2$: $\min(F_2, S_1) = \min(4, 8) = 4$.
- At $l-1=1$: $\min(F_1, S_2) = \min(9, 6) = 6$.
- Answer: $\max(4, 6) = \mathbf{6}$. ✓

## Complexity

- **Time:** $O(\log n)$ queries
- **Space:** $O(1)$

## Code (C++)

[Solution Code](../code/K-th%20Highest%20Score.cpp)
