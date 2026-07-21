# Sliding Window Mode

**CSES ID:** 3224  
**Full statement:** https://cses.fi/problemset/task/3224  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, output the mode of every sliding window of size $k$, i.e. the value occurring most often inside the window; ties are broken by choosing the smallest value.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the mode of each window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
