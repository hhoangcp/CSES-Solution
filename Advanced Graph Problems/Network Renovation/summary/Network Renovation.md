# Network Renovation

**CSES ID:** 1704  
**Full statement:** https://cses.fi/problemset/task/1704  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A tree of $n$ computers is connected, but removing any single edge disconnects it. Add the minimum number of new edges so the network stays connected after any single edge failure (i.e., becomes 2-edge-connected).

## Input
First line: $n$. Then $n-1$ lines each describing a tree edge with endpoints $a,b$.

## Output
Print the minimum number of new connections $k$, followed by $k$ lines each describing a new connection; any valid solution is accepted.

## Constraints
- $3 \le n \le 10^5$
- $1 \le a, b \le n$
