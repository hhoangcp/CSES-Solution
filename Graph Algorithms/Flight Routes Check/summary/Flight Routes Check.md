# Flight Routes Check

**CSES ID:** 1682  
**Full statement:** https://cses.fi/problemset/task/1682  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed graph, determine whether every city is reachable from every other city. If not, report a pair $a, b$ where $b$ is unreachable from $a$.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$.

## Output
`YES` if the graph is strongly connected, otherwise `NO` followed by a pair $a, b$.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
