# Food Division - Solution

**ID:** 1189 | **URL:** https://cses.fi/problemset/task/1189

## Problem Statement

$n$ children sit around a circular table. Each child has a current amount of food and a desired amount. Total food matches. Each step, a child gives 1 unit of food to a neighbor. Find the minimum number of steps.

## Approach

### Linear problem: Cost = Sum of |prefix sums|

Let $d_i = a_i - b_i$ (surplus/deficit). Total $d_i = 0$. For children in a line, food must pass through the boundary between child $i$ and $i{+}1$ in amount $|s_i|$ where $s_i = \sum_{j=1}^{i} d_j$ (accumulated surplus must go right, or deficit must be received from the right). Each unit costs 1 step, so linear cost is $\sum |s_i|$.

### Circular problem: Cut at point $k$, cost = $\sum |s_i - s_k|$

For a circular table, choose a "cut point" after child $k$ where no food passes — the problem becomes linear starting from child $k{+}1$. Shifting prefix sums so $s_k = 0$ (the cut), every $s_i$ decreases by $s_k$, giving cost $\sum |s_i - s_k|$.

### Optimization: Median of $s$

We need $c$ minimizing $f(c) = \sum |s_i - c|$. By the minimum absolute deviation property, $f(c)$ is minimized when **$c$ is the median** of $\{s_1, \ldots, s_n\}$ (every cut $k$ gives $c = s_k$, so pick $k$ with $s_k$ closest to the median; since $c$ is drawn from $s$, there always exists $s_k$ equal to the median).

## Algorithm

1. Compute $a[i] = a[i] + a[i-1] - b_i$ (prefix sum of $d$, in-place).
2. Sort the prefix sum array.
3. Median $m = a[(n{+}1)/2]$.
4. Answer $= \sum_{i=1}^{n} |a[i] - m|$.

## Example

$n = 3$, $a = [3,5,0]$, $b = [2,4,2]$.

- $d = [1,1,-2]$. Prefix sums: $[1,2,0]$.
- Sorted: $[0,1,2]$. Median $= 1$.
- Answer: $|1-1| + |2-1| + |0-1| = 0 + 1 + 1 = 2$.

## Complexity

- **Time:** $O(n \log n)$
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Food%20Division.cpp)
