# Police Chase

**CSES ID:** 1695  
**Full statement:** https://cses.fi/problemset/task/1695  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In an undirected graph, find the minimum number of streets to remove so that crossing $n$ (the harbor) is unreachable from crossing $1$ (the bank). Report the chosen edges.

## Input
$n$ and $m$, then $m$ undirected edges $a, b$.

## Output
The minimum count $k$, then $k$ edges (as pairs) to remove.

## Constraints
- $2 \le n \le 500$
- $1 \le m \le 1000$
- $1 \le a,b \le n$
