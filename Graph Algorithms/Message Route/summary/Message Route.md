# Message Route

**CSES ID:** 1667  
**Full statement:** https://cses.fi/problemset/task/1667  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

An undirected graph has $n$ computers and $m$ connections. Find a shortest path (fewest computers) from computer $1$ to computer $n$ and report its length and sequence.

## Input
$n$ and $m$, then $m$ undirected edges $a, b$.

## Output
The minimum computer count on a route followed by the route, or `IMPOSSIBLE`.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
