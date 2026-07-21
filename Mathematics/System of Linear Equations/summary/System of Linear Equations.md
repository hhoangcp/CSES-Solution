# System of Linear Equations

**CSES ID:** 3154  
**Full statement:** https://cses.fi/problemset/task/3154  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Solve a system of $n$ linear equations in $m$ variables over the field $\mathbb{Z}/(10^9+7)\mathbb{Z}$. Find any solution $x_1, \dots, x_m$ (with $0 \le x_i < 10^9+7$), or report that none exists.

## Input
The first line has $n$ and $m$. Each of the next $n$ lines has $m+1$ integers $a_{i,1}, \dots, a_{i,m}, b_i$ (coefficients and right-hand side).

## Output
Print $m$ solution values, or just $-1$ if no solution exists.

## Constraints
- $1 \le n, m \le 500$
- $0 \le a_{i,j}, b_i < 10^9+7$
