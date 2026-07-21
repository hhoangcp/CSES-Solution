# Sliding Window Cost - Solution

**ID:** 1077 | **URL:** https://cses.fi/problemset/task/1077

## Approach

### Problem Restatement

Given an array of $n$ integers, for each sliding window of $k$ consecutive elements, compute the minimum total cost of making all elements equal, where the cost is $\sum |a_i - m|$.

### Core Idea

The cost $\sum |a_i - m|$ is minimized when $m$ equals the median. Maintain a dynamic median as the window slides, using an order-statistic segment tree over coordinate-compressed values. Update the total cost incrementally rather than recomputing from scratch.

### Algorithm

**Step 1: Median minimizes cost.** The function $f(m) = \sum |a_i - m|$ is convex and piecewise linear, minimized at the median. Moving $m$ away from the median increases the number of elements on the "heavier" side, raising the total. Thus the problem reduces to maintaining the median dynamically.

**Step 2: Order-statistic segment tree with coordinate compression.** Since values can be up to $10^9$, first compress all values to the range $[0, n-1]$. Build a segment tree where each node stores the count of elements in its value range. This supports:
- Insert/delete an element in $O(\log n)$
- Find the $\lfloor(k+1)/2\rfloor$-th smallest element (lower median) in $O(\log n)$

**Step 3: Incremental cost update.** Maintain a running cost `res`. When the window slides right — removing $r$ and adding $s$, with median changing from $pre$ to $now$ — the cost change has two components:

1. **Element swap:** Adding $s$ costs $|pre - s|$ relative to the old median; removing $r$ saves $|now - r|$ relative to the new median.
2. **Median shift:** The $k-1$ remaining elements shift their reference from $pre$ to $now$. For odd $k$, this cancels by symmetry (equal elements on each side). For even $k$, the lower median creates an asymmetry (one more element on the right), requiring correction $pre - now$.

Combined formula:
$$\text{res} \mathrel{+}= |pre - s| - |now - r|$$
If $k$ is even, additionally: $\text{res} \mathrel{+}= pre - now$.

### Example

With $n=8$, $k=3$, array $[2, 4, 3, 5, 8, 1, 2, 1]$:

- Window $[2,4,3]$: median = 3, cost = $|2-3|+|4-3|+|3-3| = 2$
- Window $[4,3,5]$: remove $r=2$, add $s=5$, median $3 \to 4$. $\text{res} = 2 + |3-5| - |4-2| = 2+2-2 = 2$
- Window $[3,5,8]$: remove $r=4$, add $s=8$, median $4 \to 5$. $\text{res} = 2 + |4-8| - |5-4| = 2+4-1 = 5$
- Window $[5,8,1]$: remove $r=3$, add $s=1$, median $5 \to 5$. $\text{res} = 5 + |5-1| - |5-3| = 5+4-2 = 7$
- Window $[8,1,2]$: remove $r=5$, add $s=2$, median $5 \to 2$. $\text{res} = 7 + |5-2| - |2-5| = 7+3-3 = 7$
- Window $[1,2,1]$: remove $r=8$, add $s=1$, median $2 \to 1$. $\text{res} = 7 + |2-1| - |1-8| = 7+1-7 = 1$

Output: `2 2 5 7 7 1`

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Cost.cpp)
