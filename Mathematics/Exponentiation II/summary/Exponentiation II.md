# Exponentiation II

**CSES ID:** 1712  
**Full statement:** https://cses.fi/problemset/task/1712  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Compute $a^{b^c} \bmod (10^9+7)$ for many queries, with $0^0=1$ assumed.

## Input
The first line is $n$, followed by $n$ lines each containing $a$, $b$, $c$.

## Output
Print $a^{b^c} \bmod (10^9+7)$ for each query on its own line.

## Constraints
- $1 \le n \le 10^5$
- $0 \le a,b,c \le 10^9$
