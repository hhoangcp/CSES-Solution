# MST Edge Set Check

**CSES ID:** 3408  
**Full statement:** https://cses.fi/problemset/task/3408  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a connected simple undirected weighted graph and several sets of edges. For each set, decide whether all of its edges can simultaneously appear in some minimum spanning tree.

## Input
First line: $n$, $m$, $q$. Then $m$ weighted edges, numbered $1,\dots,m$. Then $2q$ lines: for each set, its size on one line and the edge indices on the next; total edge mentions $\le m$.

## Output
For each edge set, print `YES` if all its edges can be in an MST together, otherwise `NO`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m, q \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
