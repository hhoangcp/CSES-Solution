# Fixed Length Walk Queries

**CSES ID:** 3357  
**Full statement:** https://cses.fi/problemset/task/3357  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

You are given a connected simple undirected graph and a sequence of queries. Each query asks whether a walk of exactly $x$ edges exists from node $a$ to node $b$.

## Input
First line: $n$, $m$, $q$. Then $m$ undirected edges, each as two nodes $a,b$. Finally $q$ query lines, each with $a, b, x$.

## Output
For each query, print `YES` or `NO` on its own line.

## Constraints
- $2 \le n \le 2500$
- $1 \le m \le 5000$
- $1 \le q \le 10^5$
- $0 \le x \le 10^9$
