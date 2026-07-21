# Path Queries II

**CSES ID:** 2134  
**Full statement:** https://cses.fi/problemset/task/2134  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Each node of a tree carries a value. Queries either set a node's value to a new number or ask for the maximum value along the path between two given nodes.

## Input
First line gives $n$ and $q$. The next line lists node values. Then $n-1$ edges. Finally $q$ queries of form "1 $s$ $x$" (update) or "2 $a$ $b$" (max on the path).

## Output
Print the answer for every type-2 query.

## Constraints
- $1 \le n, q \le 2 \cdot 10^5$
- $1 \le a,b, s \le n$
- $1 \le v_i, x \le 10^9$
