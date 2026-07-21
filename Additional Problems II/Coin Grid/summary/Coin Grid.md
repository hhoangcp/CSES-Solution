# Coin Grid

**CSES ID:** 1709  
**Full statement:** https://cses.fi/problemset/task/1709  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An $n \times n$ grid has cells that are empty or hold a coin. In one move you may clear all coins in a single row or a single column. Find the minimum number of moves to empty the grid.

## Input
First line: $n$. Then $n$ lines of $n$ characters each, `.` (empty) or `o` (coin).

## Output
First the minimum count $k$, then $k$ lines each listing `1` (row) or `2` (column) followed by the index. Any valid solution is accepted.

## Constraints
- $1 \le n \le 100$
