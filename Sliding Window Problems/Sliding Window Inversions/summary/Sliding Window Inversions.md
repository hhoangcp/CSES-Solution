# Sliding Window Inversions

**CSES ID:** 3223  
**Full statement:** https://cses.fi/problemset/task/3223  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, count the number of inversions inside each sliding window of size $k$, where an inversion is a pair of positions $i<j$ within the window with $x_i > x_j$.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the inversion count per window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
