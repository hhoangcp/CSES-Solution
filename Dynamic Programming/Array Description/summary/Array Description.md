# Array Description

**CSES ID:** 1746  
**Full statement:** https://cses.fi/problemset/task/1746  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a partially known array where each entry lies in $[1,m]$ and adjacent entries differ by at most one (with `0` marking unknown slots), count how many complete arrays are consistent with the constraints.

## Input
Two integers $n$ and $m$, then $n$ values $x_1,\dots,x_n$ where `0` means unknown.

## Output
The number of valid arrays modulo $10^9+7$.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 100$
- $0 \le x_i \le m$
