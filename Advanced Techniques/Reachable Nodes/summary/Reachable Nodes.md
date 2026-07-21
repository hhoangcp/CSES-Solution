# Reachable Nodes

**CSES ID:** 2138  
**Full statement:** https://cses.fi/problemset/task/2138  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed acyclic graph has $n$ nodes and $m$ edges. For each node, compute how many nodes are reachable from it by following directed edges (counting the node itself).

## Input
First line: $n,m$. Then $m$ lines, each with two distinct integers $a,b$ (an edge $a\to b$).

## Output
Print $n$ integers, the number of reachable nodes for each node in order.

## Constraints
- $1 \le n \le 5 \cdot 10^4$
- $1 \le m \le 10^5$
