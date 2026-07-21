# Game Routes

**CSES ID:** 1681  
**Full statement:** https://cses.fi/problemset/task/1681  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed acyclic graph with $n$ levels and $m$ teleporters, count the number of distinct paths from level $1$ to level $n$, modulo $10^9+7$.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$ (no cycles exist).

## Output
One integer: the path count modulo $10^9+7$.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
