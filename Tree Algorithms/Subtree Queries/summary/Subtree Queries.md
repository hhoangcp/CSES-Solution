# Subtree Queries

**CSES ID:** 1137  
**Full statement:** https://cses.fi/problemset/task/1137  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A rooted tree has a value per node. Queries either update a single node's value or ask for the sum of values in a node's subtree.

## Input
First line gives $n$ and $q$. The next line lists node values. Then $n-1$ edges. Finally $q$ queries of form "1 $s$ $x$" (update) or "2 $s$" (subtree sum).

## Output
Print the answer for every type-2 query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
