# Fixed-Length Paths II

**CSES ID:** 2081  
**Full statement:** https://cses.fi/problemset/task/2081  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Count the distinct simple paths in a tree whose length (in edges) lies in the inclusive range $[k_1, k_2]$.

## Input
First line gives $n$, $k_1$, $k_2$. Then $n-1$ edges.

## Output
Print one integer: the number of paths with length between $k_1$ and $k_2$.

## Constraints
- $1 \le k_1 \le k_2 \le n \le 2 \cdot 10^5$
- $1 \le a,b \le n$
