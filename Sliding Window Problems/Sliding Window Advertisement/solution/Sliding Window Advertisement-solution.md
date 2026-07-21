# Sliding Window Advertisement - Solution

**ID:** 3227 | **URL:** https://cses.fi/problemset/task/3227

## Approach

### Problem Restatement

Given $n$ boards with heights $h_1, h_2, \ldots, h_n$, for each sliding window of $k$ consecutive boards, find the largest rectangle area that fits inside the histogram formed by that window. Output all $n-k+1$ results.

### Core Idea

The largest rectangle in a histogram is always bounded by some bar $i$ as the limiting height, with base equal to the maximal contiguous segment around $i$ where all bars have height $\ge h_i$. For each bar $i$, this base within a window is the overlap between its dominance range $[L[i], R[i]]$ and the current window. As the window slides, this overlap varies as a piecewise linear function of the window's right endpoint — increasing, then flat, then decreasing. Each bar contributes at most 3 line segments, which we insert into a Li Chao segment tree and query the maximum at each position.

### Algorithm

**Step 1: Dominance ranges via monotonic stack.** For each position $i$, compute $L[i]$ (first index to the left with $h_j < h_i$; default 1) and $R[i]$ (first index to the right with $h_j < h_i$; default $n$) using a monotonic stack in two passes, $O(n)$. The dominance range of $i$ is $[L[i], R[i]]$ with length $len_i = R[i] - L[i] + 1$.

Every rectangle in a histogram has some bar as its shortest bar, so maximizing over all bars' contributions covers all possible rectangles. A bar $i$ outside the current window contributes zero overlap (or only the part inside the window), so no contribution violates the window boundary.

**Step 2: Piecewise linear area function.** For element $i$ with dominance range $[l, r]$ and window right endpoint $x$ (window $[x-k+1, x]$), the contribution is $h_i \cdot w(x)$ where $w(x) = \text{overlap}([l, r], [x-k+1, x])$. As $x$ increases from $l$ to $r+k-1$, $w(x)$ has three phases:

1. **Increasing** (slope $+1$): The window enters the dominance range. $w(x) = x - l + 1$.
2. **Flat** (slope $0$): The window fully contains the range (or the range fits within the window). $w(x) = \min(k, len_i)$.
3. **Decreasing** (slope $-1$): The window exits the dominance range. $w(x) = r + k - x$.

Since $\text{overlap}([l, r], [x-k+1, x])$ is continuous and piecewise linear in $x$, each phase is a line $y = ax + b$ on a specific interval $[u, v]$, so each element inserts at most 3 line segments. The exact phase boundaries depend on whether $len_i \ge k$ or $len_i < k$, but the three-phase structure is the same.

**Step 3: Li Chao segment tree.** Insert all line segments into a Li Chao tree over $[1, n]$. Query at each $x = k, k+1, \ldots, n$. The Li Chao tree maintains the upper envelope of all inserted lines, so each query returns $\max_i \text{Area}_i(x)$ — the largest rectangle area for the window ending at $x$.

### Example

With $n=8$, $k=3$, heights $[4,1,5,3,3,2,4,1]$:

Dominance ranges:
| $i$ | $h_i$ | $L[i]$ | $R[i]$ | $len_i$ |
|-----|-------|---------|---------|---------|
| 1   | 4     | 1       | 1       | 1       |
| 2   | 1     | 1       | 8       | 8       |
| 3   | 5     | 3       | 3       | 1       |
| 4   | 3     | 3       | 5       | 3       |
| 5   | 3     | 3       | 5       | 3       |
| 6   | 2     | 3       | 7       | 5       |
| 7   | 4     | 7       | 7       | 1       |
| 8   | 1     | 1       | 8       | 8       |

For element $i=4$ ($h=3$, range $[3,5]$, $len=3$), since $len = k$, there is no flat phase:
- Increasing: $x \in [3,5]$, area $= 3(x-2) = 3x - 6$. At $x=3$: area 3; at $x=5$: area 9.
- Decreasing: $x \in [6,7]$, area $= 3(8-x) = 24-3x$. At $x=6$: area 6; at $x=7$: area 3.

Query results:
- $x=3$ (window $[1,3]$): max = 5 (bar 3, height 5, width 1)
- $x=4$ (window $[2,4]$): max = 6 (bar 4, height 3, width 2)
- $x=5$ (window $[3,5]$): max = 9 (bar 4, height 3, width 3)
- $x=6$ (window $[4,6]$): max = 6 (bar 6, height 2, width 3)
- $x=7$ (window $[5,7]$): max = 6 (bar 6, height 2, width 3)
- $x=8$ (window $[6,8]$): max = 4 (bar 7, height 4, width 1)

Output: `5 6 9 6 6 4`

## Complexity

- **Time:** $O(n \log^2 n)$
- **Space:** $O(n)$

## Code (C++)

[Solution Code](../code/Sliding%20Window%20Advertisement.cpp)
