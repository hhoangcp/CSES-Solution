# Round Trip

**CSES ID:** 1669  
**Full statement:** https://cses.fi/problemset/task/1669  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In an undirected graph, find a simple cycle of length at least 3 (start equals end, intermediate vertices distinct) and output its vertex sequence, or report none exists.

## Input
$n$ and $m$, then $m$ undirected edges $a, b$.

## Output
The cycle length $k$ followed by $k$ vertices, or `IMPOSSIBLE`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
