# Shortest Routes II

**CSES ID:** 1672  
**Full statement:** https://cses.fi/problemset/task/1672  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An undirected weighted graph has $n$ cities and $m$ roads. Answer $q$ queries asking for the shortest path length between two cities, or $-1$ if unreachable.

## Input
$n$, $m$, $q$, then $m$ undirected edges $a, b$ with length $c$, then $q$ lines each giving a query pair $a, b$.

## Output
The shortest distance per query, or $-1$.

## Constraints
- $1 \le n \le 500$
- $1 \le m \le n^2$
- $1 \le q \le 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
