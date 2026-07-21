# K Subset Xors

**CSES ID:** 3192  
**Full statement:** https://cses.fi/problemset/task/3192  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of integers, consider the xor of every subset (the empty subset contributes $0$). You must report the $k$ smallest values among these subset xors in increasing order.

## Input
First line: integers $n$ and $k$. Second line: $n$ integers $x_1,\dots,x_n$.

## Output
Print $k$ integers: the $k$ smallest subset xors in increasing order.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k \le \min(2^n, 2 \cdot 10^5)$
- $0 \le x_i \le 10^9$
