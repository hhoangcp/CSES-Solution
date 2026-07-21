# K Subset Sums I

**CSES ID:** 3108  
**Full statement:** https://cses.fi/problemset/task/3108  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ integers, consider the sums of all $2^n$ subsets (including the empty subset with sum 0). Output the $k$ smallest such subset sums in increasing order.

## Input
First line: $n$ and $k$. Next line: $n$ integers $x_1,\dots,x_n$.

## Output
Print $k$ integers: the $k$ smallest subset sums in increasing order.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k \le \min(2^n, 2 \cdot 10^5)$
- $-10^9 \le x_i \le 10^9$
