# Sliding Window Median

**CSES ID:** 1076  
**Full statement:** https://cses.fi/problemset/task/1076  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, output the median of every sliding window of size $k$ moving left to right. The median is the middle element of the sorted window; for even $k$ the smaller of the two middle elements is used.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the median of each window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
