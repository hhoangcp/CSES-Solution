# Eulerian Subgraphs

**CSES ID:** 2078  
**Full statement:** https://cses.fi/problemset/task/2078  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given an undirected graph with $n$ nodes and $m$ edges, count (modulo $10^9+7$) the number of edge subsets whose induced subgraph (keeping all nodes) gives every node even degree. Such subsets are the Eulerian subgraphs.

## Input
First line: $n,m$. Then $m$ lines, each with two integers $a,b$ (an edge). At most one edge per pair, no self-loops.

## Output
Print the count of Eulerian subgraphs modulo $10^9+7$.

## Constraints
- $1 \le n \le 10^5$
- $0 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
