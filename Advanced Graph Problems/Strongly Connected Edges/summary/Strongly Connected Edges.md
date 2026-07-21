# Strongly Connected Edges

**CSES ID:** 2177  
**Full statement:** https://cses.fi/problemset/task/2177  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Orient each edge of an undirected simple graph so that the resulting directed graph is strongly connected.

## Input
First line: $n$ and $m$. Then $m$ lines each with an undirected edge between distinct nodes $a,b$; the graph is simple.

## Output
Print $m$ lines giving each edge's orientation $a \to b$; if impossible, print only `IMPOSSIBLE`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
