# Counting Bishops

**CSES ID:** 2176  
**Full statement:** https://cses.fi/problemset/task/2176  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Count the number of ways to place $k$ bishops on an $n \times n$ chessboard so that no two share a diagonal. The result is taken modulo $10^9+7$.

## Input
A single line with two integers $n$ and $k$: the board size and the number of bishops.

## Output
Print one integer, the number of valid placements modulo $10^9+7$.

## Constraints
- $1 \le n \le 500$
- $1 \le k \le n^2$
