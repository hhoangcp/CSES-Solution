# Counting LCM Arrays

**CSES ID:** 3169  
**Full statement:** https://cses.fi/problemset/task/3169  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Count arrays $a_1,\ldots,a_n$ of positive integers such that the LCM of every adjacent pair equals a fixed value $k$. Only divisors of $k$ can appear.

## Input
An integer $t$, then $t$ lines each with $n$ and $k$.

## Output
Print the answer for each test case modulo $10^9 + 7$.

## Constraints
- $1 \le t \le 1000$
- $2 \le n \le 10^9$
- $1 \le k \le 10^9$
