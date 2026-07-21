# Longest Flight Route

**CSES ID:** 1680  
**Full statement:** https://cses.fi/problemset/task/1680  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed acyclic graph, find the longest path from city $1$ to city $n$ in terms of number of cities visited, and output that path.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$ (the graph is acyclic).

## Output
The maximum number of cities on the route followed by the route's vertex list, or `IMPOSSIBLE`.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
