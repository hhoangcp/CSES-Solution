# Array Division

**CSES ID:** 1085  
**Full statement:** https://cses.fi/problemset/task/1085  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of $n$ positive integers, split it into exactly $k$ contiguous subarrays so that the largest subarray sum is as small as possible.

## Input
First line: two integers $n$ and $k$. Next line: $n$ integers $x_1,\ldots,x_n$.

## Output
Print one integer: the smallest possible value of the largest subarray sum.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le k \le n$
- $1 \le x_i \le 10^9$
