# Sliding Window Distinct Values

**CSES ID:** 3222  
**Full statement:** https://cses.fi/problemset/task/3222  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of $n$ integers, count how many distinct values appear inside each sliding window of size $k$ as it moves left to right.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the number of distinct values per window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
