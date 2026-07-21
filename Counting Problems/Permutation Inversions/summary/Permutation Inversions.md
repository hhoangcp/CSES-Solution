# Permutation Inversions

**CSES ID:** 2229  
**Full statement:** https://cses.fi/problemset/task/2229  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An inversion is a pair of entries in a permutation that appear in the wrong order. Given $n$ and $k$, count how many permutations of $1,2,\dots,n$ have exactly $k$ inversions, modulo $10^9+7$.

## Input
A single line with two integers $n$ and $k$.

## Output
Print the answer modulo $10^9+7$.

## Constraints
- $1 \le n \le 500$
- $0 \le k \le \frac{n(n-1)}{2}$
