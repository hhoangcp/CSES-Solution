# Sliding Window Mex

**CSES ID:** 3219  
**Full statement:** https://cses.fi/problemset/task/3219  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, output the mex of every sliding window of size $k$, where mex is the smallest nonnegative integer not present in the window.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the mex of each window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $0 \le x_i \le 10^9$
