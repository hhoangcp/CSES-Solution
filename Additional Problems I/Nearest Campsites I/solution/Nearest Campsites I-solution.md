# Nearest Campsites I - Solution

**ID:** 3306 | **URL:** https://cses.fi/problemset/task/3306

## Problem Statement

On a coordinate grid, there are $n$ placed campsites (denoted $R$) and $m$ empty sites (denoted $F$). Find the maximum Manhattan distance from an empty site to its nearest placed campsite.

## Approach

### 1. Geometric analysis: 4 Quadrants

The Manhattan distance $|x_F - x_R| + |y_F - y_R|$ can be decomposed into 4 cases depending on the position of placed point $R$ relative to empty point $F$. To find the nearest point, we divide the plane around each point $F$ into 4 quadrants:

<div align="center"><img src="../../../images/4-quadrants.png" width="400"/></div>

> **Image legend:** With point $F$ as the origin, Quadrant III (signs $-,-$) corresponds to the **Bottom-Left** region, Quadrant II (signs $-,+$) to the **Top-Left** region, Quadrant IV (signs $+,-$) to the **Bottom-Right** region, and Quadrant I (signs $+,+$) to the **Top-Right** region.

- **Bottom-Left quadrant** ($x_R \le x_F, y_R \le y_F$):
  $d = (x_F - x_R) + (y_F - y_R) = (x_F + y_F) - (x_R + y_R)$.
  $\to$ Need the point $R$ with the **largest $(x_R + y_R)$**.
- **Top-Left quadrant** ($x_R \le x_F, y_R > y_F$):
  $d = (x_F - x_R) + (y_R - y_F) = (x_F - y_F) - (x_R - y_R)$.
  $\to$ Need the point $R$ with the **largest $(x_R - y_R)$**.
- **Bottom-Right quadrant** ($x_R > x_F, y_R \le y_F$):
  $d = (x_R - x_F) + (y_F - y_R) = (-x_F + y_F) - (-x_R + y_R)$.
  $\to$ Need the point $R$ with the **largest $(-x_R + y_R)$**.
- **Top-Right quadrant** ($x_R > x_F, y_R > y_F$):
  $d = (x_R - x_F) + (y_R - y_F) = (-x_F - y_F) - (-x_R - y_R)$.
  $\to$ Need the point $R$ with the **largest $(-x_R - y_R)$**.

### 2. Sweep algorithm with Fenwick Tree (BIT)

Since each point $F$ needs to find the nearest point $R$ across all 4 regions, we perform 4 sweep passes. Each pass solves **only the Bottom-Left region** by coordinate transformation:

1. **Sort:** Sort all $R$ and $F$ points by increasing $x$-coordinate. This ensures that when processing $F$, all previously visited $R$ points satisfy $x_R \le x_F$.
2. **Use BIT:** Use a BIT to manage values by $y$-coordinate.
   - When encountering point $R$: Update the BIT at position $y_R$ with value $(x_R + y_R)$. The BIT stores the **maximum** value.
   - When encountering point $F$: Query the BIT for the maximum value in range $[0, y_F]$. The candidate distance is $(x_F + y_F) - \text{BIT.query}(y_F)$.
3. **Coordinate rotation:** After each pass, flip the coordinates (e.g., $y = -y$ or $x = -x$) to map other quadrants to the Bottom-Left position and re-run the algorithm.

### 3. Aggregate results

- For each empty site $F$, after 4 sweep passes, take the minimum of the 4 distances found.
- The final answer is the **maximum** among these minimum distances.

### Proof of correctness

- **Distance decomposition:** Decomposing the absolute value into 4 expressions $f(x_F, y_F) - f(x_R, y_R)$ guarantees that for any position of $R$, at least one sweep pass computes the correct Manhattan distance.
- **BIT optimality:** Within each quadrant, the minimum distance corresponds to finding the largest transformed value $f(x_R, y_R)$. The BIT with `update_max` and `query_max` operations perfectly solves the extremum search on 2D data where one axis has been swept.

## Detailed Example

Suppose there are 2 placed points $R_1(1,1), R_2(5,2)$ and 1 empty point $F(7,5)$.

**Bottom-Left sweep** ($x_R \le 7, y_R \le 5$):

Both $R_1(1,1)$ and $R_2(5,2)$ satisfy the condition of being in the Bottom-Left quadrant of $F$.

Transform value $f(x, y) = x + y$:

- At $R_1$: $f = 1 + 1 = 2$.
- At $R_2$: $f = 5 + 2 = 7$.
- BIT stores $\max(2, 7) = 7$ at indices $y \le 5$.

When processing empty point $F(7,5)$:

- $f(F) = 7 + 5 = 12$.
- Nearest distance from this direction: $12 - 7 = 5$.

**Final result:**

Empty point $F(7,5)$ after sweeping all 4 directions will find its nearest distance is $5$ (to $R_2$). If there were another empty point $F_2$ with nearest distance $2$, the answer would be $\max(5, 2) = 5$.

### Problem Statement Example

4 placed points: $R_1(1,1), R_2(5,2), R_3(2,6), R_4(4,7)$. 2 empty points: $F_1(1,3), F_2(7,5)$.

**Bottom-Left sweep** ($x_R \le x_F, y_R \le y_F$):

Process in increasing $x$ order ($R$ before $F$ at same $x$):

1. $R_1(1,1)$: update BIT at $y=1$, value $1+1=2$.
2. $F_1(1,3)$: query BIT at $y=3$, $\max = 2$. Distance = $(1+3)-2 = 2$.
3. $R_3(2,6)$: update BIT at $y=6$, value $2+6=8$.
4. $R_4(4,7)$: update BIT at $y=7$, value $4+7=11$.
5. $R_2(5,2)$: update BIT at $y=2$, value $5+2=7$.
6. $F_2(7,5)$: query BIT at $y=5$, $\max$ in $[0,5]$ is $7$ (from $R_2$ at $y=2$). Distance = $(7+5)-7 = 5$.

After all 4 sweep passes:
- $F_1(1,3)$: nearest distance = $2$ (to $R_1$).
- $F_2(7,5)$: nearest distance = $5$ (to $R_2$).

Answer: $\max(2, 5) = \mathbf{5}$.

## Complexity

- **Time:** $O((n + m) \log (\max Y))$ — 4 sweep passes total, each requiring sorting and BIT operations.
- **Memory:** $O(n + m)$ — Storing coordinates and results for each empty site.

## Code (C++)

[Solution Code](../code/Nearest%20Campsites%20I.cpp)
