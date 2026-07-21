# GCD Subsets

**CSES ID:** 3161  
**Full statement:** https://cses.fi/problemset/task/3161  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an array of $n$ integers, for each $k$ from $1$ to $n$ count the non-empty subsets whose elements have greatest common divisor exactly $k$, modulo $10^9+7$.

## Input
First line: $n$. Next line: $n$ integers $x_i$.

## Output
Print $n$ integers modulo $10^9+7$, the counts for $k=1,\dots,n$.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le x_i \le n$
