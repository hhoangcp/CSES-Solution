# Coin Combinations I

**CSES ID:** 1635  
**Full statement:** https://cses.fi/problemset/task/1635  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given $n$ coin denominations, count the number of ordered sequences of coins (order matters) whose total value equals $x$.

## Input
Integers $n$ and $x$, then $n$ distinct coin values $c_i$.

## Output
The number of ordered ways modulo $10^9+7$.

## Constraints
- $1 \le n \le 100$
- $1 \le x \le 10^6$
- $1 \le c_i \le 10^6$
