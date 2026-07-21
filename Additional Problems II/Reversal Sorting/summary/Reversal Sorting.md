# Reversal Sorting

**CSES ID:** 2075  
**Full statement:** https://cses.fi/problemset/task/2075  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a permutation of $1,\dots,n$. Sort it into increasing order by reversing contiguous subarrays, using at most $n$ reversals. Output any valid sequence of reversals.

## Input
First line: $n$. Next line: $n$ integers $x_1,\dots,x_n$.

## Output
First the count $k$ of reversals, then $k$ lines each with two indices $a$ and $b$ (the reversed subarray bounds).

## Constraints
- $1 \le n \le 2 \cdot 10^5$
