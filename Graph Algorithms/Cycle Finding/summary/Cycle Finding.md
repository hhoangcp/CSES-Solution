# Cycle Finding

**CSES ID:** 1197  
**Full statement:** https://cses.fi/problemset/task/1197  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed weighted graph, determine whether it has a negative-weight cycle and, if so, print one such cycle as a sequence of vertices.

## Input
$n$ and $m$, then $m$ lines each giving an edge $a \to b$ with weight $c$.

## Output
`YES` followed by the cycle's vertices in order, or `NO` if no negative cycle exists.

## Constraints
- $1 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le a,b \le n$
- $-10^9 \le c \le 10^9$
