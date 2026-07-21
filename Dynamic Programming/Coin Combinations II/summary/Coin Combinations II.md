# Coin Combinations II

**CSES ID:** 1636  
**Full statement:** https://cses.fi/problemset/task/1636  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ coin denominations, count the number of multisets of coins (order does not matter) whose total value equals $x$.

## Input
Integers $n$ and $x$, then $n$ distinct coin values $c_i$.

## Output
The number of unordered ways modulo $10^9+7$.

## Constraints
- $1 \le n \le 100$
- $1 \le x \le 10^6$
- $1 \le c_i \le 10^6$
