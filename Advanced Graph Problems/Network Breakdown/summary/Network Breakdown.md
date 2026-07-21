# Network Breakdown

**CSES ID:** 1677  
**Full statement:** https://cses.fi/problemset/task/1677  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A network of $n$ computers and $m$ links is processed over time as $k$ specified links break one by one (and are not repaired). After each breakdown, report the number of connected components of the remaining graph.

## Input
First line: $n$, $m$, $k$. Then $m$ lines of initial links $a,b$ (simple graph). Then $k$ lines naming the link that breaks at each step.

## Output
Print, after each breakdown, the number of components (space-separated in order).

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le k \le m$
- $1 \le a, b \le n$
