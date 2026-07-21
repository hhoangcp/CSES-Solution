# All Subarray Xors

**CSES ID:** 3233  
**Full statement:** https://cses.fi/problemset/task/3233  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an array of integers. For every contiguous subarray, compute the xor of its elements; collect all distinct values that arise this way and report them in increasing order.

## Input
First line: integer $n$. Second line: $n$ integers $x_1,\dots,x_n$.

## Output
First the count $k$ of distinct subarray xor values, then those $k$ values in increasing order.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $0 \le x_i \le 10^6$
