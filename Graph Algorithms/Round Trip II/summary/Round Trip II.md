# Round Trip II

**CSES ID:** 1678  
**Full statement:** https://cses.fi/problemset/task/1678  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed graph, find a simple cycle (start equals end, intermediate vertices distinct) and output its vertex sequence, or report none exists.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$.

## Output
The cycle length $k$ followed by $k$ vertices, or `IMPOSSIBLE`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
