# Planets and Kingdoms

**CSES ID:** 1683  
**Full statement:** https://cses.fi/problemset/task/1683  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed graph has $n$ planets and $m$ teleporters. Two planets are in the same kingdom iff each is reachable from the other. Assign each planet a kingdom label.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$.

## Output
The kingdom count $k$, then $n$ labels in $[1, k]$.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
