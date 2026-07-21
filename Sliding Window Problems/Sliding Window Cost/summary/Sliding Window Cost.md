# Sliding Window Cost

**CSES ID:** 1077  
**Full statement:** https://cses.fi/problemset/task/1077  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array, for every window of $k$ consecutive elements you may change each value up or down at unit cost per unit of change, and want all window elements to become equal at minimum total cost.

## Input
First line: $n$ and $k$. Second line: the $n$ array elements $x_1,\dots,x_n$.

## Output
Print $n-k+1$ values, the minimum cost for each window.

## Constraints
- $1 \le k \le n \le 2 \cdot 10^5$
- $1 \le x_i \le 10^9$
