# All Manhattan Distances - Solution

**ID:** 3411 | **URL:** https://cses.fi/problemset/task/3411

## Approach

### Problem Restatement

Given $n$ points on the plane, compute $\sum_{i < j} (|x_i - x_j| + |y_i - y_j|)$, the sum of all Manhattan distances between unordered pairs.

### Core idea

The Manhattan distance splits into independent $x$ and $y$ components:

$$\sum_{i < j} (|x_i - x_j| + |y_i - y_j|) = \sum_{i < j} |x_i - x_j| + \sum_{i < j} |y_i - y_j|$$

So we just need to solve: given array $a$, compute $\sum_{i < j} |a_i - a_j|$.

Sort $a$ in non-decreasing order. For $i > j$, we have $a_i \ge a_j$, so $|a_i - a_j| = a_i - a_j$. The contribution of $a_i$ to the total is:

$$\sum_{j=1}^{i-1} (a_i - a_j) = a_i \cdot (i-1) - \text{prefix\_sum}_{i-1}$$

Summing over all $i$ gives $\sum_{i < j} |a_i - a_j|$. The prefix sum is maintained incrementally, so each element is processed in $O(1)$. Apply this independently to the $x$ and $y$ arrays. With $n \le 2 \cdot 10^5$ and coordinates up to $10^9$, the result can exceed 64-bit range, so `__int128` is needed.

### Algorithm

1. Read all points, store $x$ and $y$ coordinates in separate arrays.
2. Sort the $x$-array and $y$-array independently.
3. Initialize $\text{ans} = 0$, $\text{sumX} = 0$, $\text{sumY} = 0$.
4. For $i$ from 0 to $n-1$:
   - $\text{ans} \mathrel{+}= (x_i + y_i) \cdot i - \text{sumX} - \text{sumY}$
   - $\text{sumX} \mathrel{+}= x_i$, $\text{sumY} \mathrel{+}= y_i$
5. Output $\text{ans}$.

### Example

$n=5$, points: $(1,1), (3,2), (2,4), (2,1), (4,5)$.

Sorted $x$: $[1, 2, 2, 3, 4]$. Sorted $y$: $[1, 1, 2, 4, 5]$.

- $i=0$: $x$-contrib $= 1 \cdot 0 - 0 = 0$, $y$-contrib $= 1 \cdot 0 - 0 = 0$.
- $i=1$: $x$-contrib $= 2 \cdot 1 - 1 = 1$, $y$-contrib $= 1 \cdot 1 - 1 = 0$.
- $i=2$: $x$-contrib $= 2 \cdot 2 - 3 = 1$, $y$-contrib $= 2 \cdot 2 - 2 = 2$.
- $i=3$: $x$-contrib $= 3 \cdot 3 - 5 = 4$, $y$-contrib $= 4 \cdot 3 - 4 = 8$.
- $i=4$: $x$-contrib $= 4 \cdot 4 - 8 = 8$, $y$-contrib $= 5 \cdot 4 - 8 = 12$.

$x$-total: $0+1+1+4+8 = 14$. $y$-total: $0+0+2+8+12 = 22$. Total: $14+22 = 36$.

## Complexity

- **Time:** $O(n \log n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/All%20Manhattan%20Distances.cpp)
