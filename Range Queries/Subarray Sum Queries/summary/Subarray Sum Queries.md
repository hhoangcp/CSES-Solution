# Subarray Sum Queries

**CSES ID:** 1190  
**Full statement:** https://cses.fi/problemset/task/1190  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array of integers under point updates. After every update you must report the maximum sum of any contiguous subarray of the whole array (the empty subarray, sum 0, is allowed).

## Input
First line gives $n$ (size) and $m$ (updates). Second line lists the initial array. The following $m$ lines each give a position $k$ and new value $x$.

## Output
After each update, print the maximum subarray sum.

## Constraints
- $1 \le n, m \le 2 \cdot 10^5$
- $-10^9 \le x_i \le 10^9$
- $1 \le k \le n$
- $-10^9 \le x \le 10^9$
