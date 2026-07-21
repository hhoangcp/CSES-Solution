# Signal Processing

**CSES ID:** 2113  
**Full statement:** https://cses.fi/problemset/task/2113  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a signal sequence of length $n$ and a mask of length $m$. Slide the mask across the signal from left to right; at each alignment, sum the products of overlapping signal and mask values.

## Input
First line: $n,m$. Second line: $n$ integers $a_1,\ldots,a_n$ (the signal). Third line: $m$ integers $b_1,\ldots,b_m$ (the mask).

## Output
Print $n+m-1$ integers, the alignment sums from leftmost to rightmost mask position.

## Constraints
- $1 \le n,m \le 2 \cdot 10^5$
- $1 \le a_i,b_i \le 100$
