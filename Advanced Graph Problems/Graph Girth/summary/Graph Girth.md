# Graph Girth

**CSES ID:** 1707  
**Full statement:** https://cses.fi/problemset/task/1707  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Find the length of the shortest cycle (the girth) of an undirected graph; output $-1$ if the graph is acyclic.

## Input
First line: $n$ and $m$. Then $m$ lines each with an undirected edge between nodes $a,b$; at most one edge per pair.

## Output
Print one integer: the girth, or $-1$ if there is no cycle.

## Constraints
- $1 \le n \le 2500$
- $1 \le m \le 5000$
