# Point in Polygon

**CSES ID:** 2192  
**Full statement:** https://cses.fi/problemset/task/2192  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a simple polygon of $n$ vertices and a list of $m$ query points. For each query point classify it as inside the polygon, outside it, or exactly on its boundary.

## Input
First two integers $n$ and $m$, then $n$ lines each giving a polygon vertex $(x_i, y_i)$, followed by $m$ lines each giving a query point $(x, y)$.

## Output
For each query point print "INSIDE", "OUTSIDE", or "BOUNDARY".

## Constraints
- $3 \le n \le 1000$
- $1 \le m \le 1000$
- $-10^9 \le x_i, y_i \le 10^9$
- $-10^9 \le x, y \le 10^9$
