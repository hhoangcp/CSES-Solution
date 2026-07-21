# Reachability Queries

**CSES ID:** 2143  
**Full statement:** https://cses.fi/problemset/task/2143  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A directed graph has $n$ nodes and $m$ edges. Answer $q$ queries asking whether node $b$ is reachable from node $a$ following directed edges.

## Input
First line: $n,m,q$. Then $m$ lines, each with two distinct integers $a,b$ (an edge $a\to b$). Then $q$ query lines, each with two integers $a,b$.

## Output
For each query print `YES` or `NO`.

## Constraints
- $1 \le n \le 5 \cdot 10^4$
- $1 \le m,q \le 10^5$
