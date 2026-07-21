# Inverse Inversions

**CSES ID:** 2214  
**Full statement:** https://cses.fi/problemset/task/2214  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Construct a permutation of $1,2,\dots,n$ that has exactly $k$ inversions, where an inversion is a pair of positions $a<b$ with $p_a>p_b$. The task is to output any one such permutation.

## Input
A single line with two integers $n$ and $k$.

## Output
Print any permutation of $1,\dots,n$ with exactly $k$ inversions.

## Constraints
- $1 \le n \le 10^6$
- $0 \le k \le \frac{n(n-1)}{2}$
