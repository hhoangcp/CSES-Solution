# Path Queries

**CSES ID:** 1138  
**Full statement:** https://cses.fi/problemset/task/1138  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A rooted tree has a value on each node. Two query types are supported: point-update a node's value, and ask for the sum of values along the root-to-node path.

## Input
First line gives $n$ and $q$. The next line lists node values. Then $n-1$ edges. Finally $q$ queries of form "1 $s$ $x$" (update) or "2 $s$" (path sum from root).

## Output
Print the answer for every type-2 query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
