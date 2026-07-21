# Finding a Centroid

**CSES ID:** 2079  
**Full statement:** https://cses.fi/problemset/task/2079  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A centroid of a tree is a node that, when chosen as root, leaves every resulting subtree with at most $\lfloor n/2 \rfloor$ nodes. Find any such node.

## Input
First line gives $n$, then $n-1$ edges.

## Output
Print one node index that is a centroid.

## Constraints
- $1 \le n \le 2 \cdot 10^5$
- $1 \le a,b \le n$
