# Programmers and Artists - Solution

**ID:** 2426 | **URL:** https://cses.fi/problemset/task/2426

## Problem Statement

A company wants to hire $a$ programmers and $b$ artists. There are $n$ applicants, each can become either a programmer or an artist. You know the programming skill $x$ and artistic skill $y$ of each applicant. Maximize the total skill.

## Approach

### Sort by difference: programmers at the front, artists at the back

Sort applicants by $x_i - y_i$ in decreasing order. Applicants with higher difference should be programmers (more benefit), those with lower difference should be artists.

**An optimal split point exists:** Suppose applicant $i$ (higher difference) is an artist and $j$ (lower difference, $j > i$) is a programmer. Swapping roles: change in total = $(x_i + y_j) - (y_i + x_j) = (x_i - y_i) - (x_j - y_j) \ge 0$. Swapping never decreases the total, so there always exists an optimal configuration where all programmers are among the first $p$ applicants.

### Two-pass scan: Min-heap for top $a$ and top $b$

**Forward scan (prefix):** Maintain a min-heap of size $a$ containing programming skills. $dp[i]$ = sum of top $a$ programming skills among first $i$ applicants.

**Backward scan (suffix):** Maintain a min-heap of size $b$ containing artistic skills. For each split point $i$, compute the sum of top $b$ artistic skills among applicants from $i$ to $n$.

**Answer:** $\max(dp[i-1] + \text{artist\_sum}_i)$ over all valid split points $i$.

## Algorithm

1. Sort applicants by $x - y$ in decreasing order.
2. Forward scan: compute $dp[i]$ for $i = a \ldots n$.
3. Backward scan: maintain `artist_sum`, update answer at each split point.

## Example

$a = 2, b = 1, n = 4$. Applicants: $(3,7), (9,8), (1,5), (4,2)$.

Sorted by $x - y$ decreasing: $(4,2) \to 2$, $(9,8) \to 1$, $(3,7) \to -4$, $(1,5) \to -4$.

- Forward scan: $dp[2] = 4 + 9 = 13$.
- Backward scan: at $i = 3$, best artist = 7.
- Answer: $13 + 7 = 20$.

Programmers: applicant 1 (skill 4) and 2 (skill 9). Artist: applicant 3 (skill 7).

## Complexity

- **Time:** $O(n \log n)$ — sorting + heap traversal
- **Memory:** $O(n)$

## Code (C++)

[Solution Code](../code/Programmers%20and%20Artists.cpp)
