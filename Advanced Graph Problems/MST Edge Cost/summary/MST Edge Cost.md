# MST Edge Cost

**CSES ID:** 3409  
**Full statement:** https://cses.fi/problemset/task/3409  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

For each edge of a connected simple undirected weighted graph, compute the cost of a minimum spanning tree that is forced to include that edge.

## Input
First line: $n$ and $m$. Then $m$ lines each with $a, b, w$ describing a weighted undirected edge.

## Output
For each edge in input order, print the minimum spanning tree cost when that edge is included.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le w \le 10^9$
