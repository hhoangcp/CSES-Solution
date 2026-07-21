# Nearest Campsites II - Solution

**ID:** 3307 | **URL:** https://cses.fi/problemset/task/3307

## Problem Statement

On a $10^6 \times 10^6$ coordinate grid, given $n$ placed campsites (Reserved) and $m$ empty sites (Free), find the shortest Manhattan distance from each empty site to any placed campsite. Output the result for each empty site in the order they were given.

## Approach

### 1. Analysis of 4 Quadrants

The Manhattan distance $|x_1 - x_2| + |y_1 - y_2|$ is handled by dividing the space around each empty point into 4 regions (quadrants). In each region, the formula for decomposing the absolute value differs:

<div align="center"><img src="../../../images/4-quadrants.png" width="400"/></div>

> **Image legend:** With point $F$ as the origin, Quadrant III (signs $-,-$) corresponds to the **Bottom-Left** region, Quadrant II (signs $-,+$) to the **Top-Left** region, Quadrant IV (signs $+,-$) to the **Bottom-Right** region, and Quadrant I (signs $+,+$) to the **Top-Right** region.

- **Bottom-Left region** ($x_R \le x_F, y_R \le y_F$): $d = (x_F + y_F) - (x_R + y_R)$.
- **Top-Left region** ($x_R \le x_F, y_R > y_F$): $d = (x_F - y_F) - (x_R - y_R)$.
- **Bottom-Right region** ($x_R > x_F, y_R \le y_F$): $d = (-x_F + y_F) - (-x_R + y_R)$.
- **Top-Right region** ($x_R > x_F, y_R > y_F$): $d = (-x_F - y_F) - (-x_R - y_R)$.

### 2. Sweep algorithm with BIT

We use a **Fenwick Tree (BIT)** to maintain the maximum value of the expression containing $(x_R, y_R)$ within each region.

1. **Coordinate transformation:** Perform 4 sweep passes. In each pass, transform the coordinates (flip the $x$ or $y$ axis) to map the region being examined to the "Bottom-Left" state.
2. **Sweep:** Sort all points by increasing $x$-coordinate.
3. **BIT update and query:**
   - When encountering a placed point $R$: Update the BIT at position $y_R$ with the transform value (e.g., $x_R + y_R$). The BIT is configured to find the **maximum** value.
   - When encountering an empty point $F$: Query the BIT for the maximum value in range $[0, y_F]$. The candidate distance equals $F$'s transform value minus the maximum from the BIT.
4. **Store results:** For each empty point $i$, maintain $ans[i] = \min(ans[i], \text{candidate distance})$ across all 4 sweep passes.

### 3. Difference from Problem I

Unlike Problem I (which only takes the overall maximum), Problem II requires outputting the result for **each** empty site. After all 4 transformations, $ans[i]$ contains the minimum Manhattan distance to the nearest placed campsite.

## Example

With 4 placed points $(1,1), (5,2), (2,6), (4,7)$ and 2 empty points $(1,3), (7,5)$:

- **Empty point (1,3):**
  - Distance to $(1,1)$ is $|1-1| + |3-1| = 2$.
  - This is its shortest distance.
- **Empty point (7,5):**
  - Distance to $(5,2)$ is $|7-5| + |5-2| = 5$.
  - Distance to $(4,7)$ is $|7-4| + |5-7| = 5$.
  - Its shortest distance is 5.

**Result:** `2 5`.

## Complexity

- **Time:** $O((n + m) \log (n + m))$ — 4 sweep passes, each involving sorting and BIT operations.
- **Memory:** $O(n + m)$ — Storing coordinates, event arrays, and result arrays for each empty site.

## Code (C++)

[Solution Code](../code/Nearest%20Campsites%20II.cpp)
