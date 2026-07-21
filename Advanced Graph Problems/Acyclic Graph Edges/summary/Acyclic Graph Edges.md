# Acyclic Graph Edges

**CSES ID:** 1756  
**Full statement:** https://cses.fi/problemset/task/1756  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given an undirected graph and must orient every edge so that the resulting directed graph contains no directed cycle.

## Input
First line: $n$ and $m$ (nodes, edges). Then $m$ lines each with two distinct node indices $a,b$ describing an undirected edge.

## Output
Print $m$ lines, each giving the chosen orientation $ab$ (an edge from $a$ to $b$); any valid acyclic orientation is accepted.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
