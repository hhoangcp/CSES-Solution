# Polynomial Queries

**CSES ID:** 1736  
**Full statement:** https://cses.fi/problemset/task/1736  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You maintain an array under two operations: a range update that adds $1,2,3,\dots$ (an arithmetic progression with difference 1) to positions $[a,b]$, and a range-sum query.

## Input
First line gives $n$ and $q$. Second line lists the initial array. The $q$ query lines are either "1 $a$ $b$" (progressive add) or "2 $a$ $b$" (range sum).

## Output
Print the answer to each sum query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le t_i \le 10^6$
- $1 \le a \le b \le n$
