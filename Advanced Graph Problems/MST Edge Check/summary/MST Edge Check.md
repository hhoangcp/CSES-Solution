# MST Edge Check

**CSES ID:** 3407  
**Full statement:** https://cses.fi/problemset/task/3407  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a connected simple undirected weighted graph, decide for each input edge whether it can belong to some minimum spanning tree of the graph.

## Input
First line: $n$ and $m$. Then $m$ lines each with $a, b, w$ (an undirected weighted edge).

## Output
For each edge in input order, print `YES` if it can be in some MST, otherwise `NO`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
