# Divisor Analysis

**CSES ID:** 2182  
**Full statement:** https://cses.fi/problemset/task/2182  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a large integer via its prime factorization, compute the number of its divisors, their sum, and their product. All three answers are reported modulo $10^9+7$.

## Input
The first line is $n$, the number of distinct prime factors. Each of the next $n$ lines gives a prime $x$ and its exponent $k$.

## Output
Print three integers modulo $10^9+7$: divisor count, divisor sum, divisor product.

## Constraints
- $1 \le n \le 10^5$
- $2 \le x \le 10^6$
- each $x$ is a distinct prime
- $1 \le k \le 10^9$
