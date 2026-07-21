# Maximum Average Subarrays - Solution

**ID:** 3301 | **URL:** https://cses.fi/problemset/task/3301

## Problem Statement

For each position $i$ from $1$ to $n$, find the subarray ending at $i$ with the largest average. If multiple subarrays share the same maximum average, choose the one with the greatest length.

## Approach

### 1. Geometric modeling

The average of a subarray from $j+1$ to $i$ is computed as:
$$\text{Average}(j+1, i) = \frac{S[i] - S[j]}{i - j}$$

where $S[i]$ is the prefix sum up to position $i$.

Geometrically, this value is the **slope** of the line segment connecting two points $P_j(j, S[j])$ and $P_i(i, S[i])$ on the coordinate plane. The problem becomes: for each point $P_i$, find the point $P_j$ ($0 \le j < i$) such that the slope $P_j P_i$ is maximized.

### 2. Maintaining the Lower Convex Hull

To maximize the slope to a point $P_i$ on the right, we only need to consider points $P_j$ that lie on the **lower convex hull** of the set of preceding points.

- As we iterate through each $i$, we add the point $P_{i-1}(i-1, S[i-1])$ to the hull.
- If the new point creates a "concave angle", we remove the vertex points to maintain convexity.

### 3. Binary search on the convex hull

An important property is that the slopes from points on the lower convex hull to the query point $P_i$ are **unimodal** — they increase to a maximum value and then decrease.

- This allows us to use **binary search** on the hull points to find the optimal point $P_j$ in $O(\log n)$ time.
- To prefer the longest subarray when slopes are equal, we choose the point $P_j$ with the smaller index $j$ (farther to the left of $P_i$).

## Example walkthrough

Array: `1 6 4 6 2 5 5`, examining $i=5$ ($S[5]=19$):

- Current hull points: $P_0(0,0), P_1(1,1), P_3(3,11), P_4(4,17)$.
- Slopes to $P_5(5, 19)$:
  - From $P_0$: $(19-0)/(5-0) = 3.8$
  - From $P_1$: $(19-1)/(5-1) = 4.5$
  - From $P_3$: $(19-11)/(5-3) = 4.0$
  - From $P_4$: $(19-17)/(5-4) = 2.0$
- Optimal result at $i=5$ is $j=1$, subarray length $= 5 - 1 = 4$.

## Complexity

- **Time:** $O(n \log n)$ — Adding points to the hull takes $O(n)$ total, and each binary search query takes $O(\log n)$.
- **Memory:** $O(n)$ for the prefix sum array and hull points.

## Code (C++)

[Solution Code](../code/Maximum%20Average%20Subarrays.cpp)
