# Graph Paths I

**CSES ID:** 1723  
**Full statement:** https://cses.fi/problemset/task/1723  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed graph with $n$ vertices and $m$ edges, count the number of walks of exactly $k$ edges from vertex $1$ to vertex $n$. Answer modulo $10^9+7$.

## Input
The first line contains $n$, $m$, $k$. The next $m$ lines each describe a directed edge $a \to b$.

## Output
Print the number of length-$k$ walks from $1$ to $n$ modulo $10^9+7$.

## Constraints
- $1 \le n \le 100$
- $1 \le m \le n(n-1)$
- $1 \le k \le 10^9$
- $1 \le a,b \le n$
