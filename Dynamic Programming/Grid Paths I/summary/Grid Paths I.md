# Grid Paths I

**CSES ID:** 1638  
**Full statement:** https://cses.fi/problemset/task/1638  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An $n \times n$ grid has some trapped cells. Starting from the top-left corner and moving only right or down (never into a trap), count the number of ways to reach the bottom-right corner.

## Input
An integer $n$, then $n$ rows of $n$ characters (`.` empty, `*` trap).

## Output
The number of valid paths modulo $10^9+7$.

## Constraints
- $1 \le n \le 1000$
