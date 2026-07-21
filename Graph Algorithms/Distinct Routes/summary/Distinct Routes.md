# Distinct Routes

**CSES ID:** 1711  
**Full statement:** https://cses.fi/problemset/task/1711  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed graph has $n$ rooms and $m$ teleporters; each day you travel from room $1$ to room $n$, using each teleporter at most once overall. Maximize the number of days and list the routes.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$ (no duplicate edges).

## Output
The maximum count $k$, followed by each route's length and vertex list.

## Constraints
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le a,b \le n$
