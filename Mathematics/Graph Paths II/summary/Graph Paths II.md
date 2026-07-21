# Graph Paths II

**CSES ID:** 1724  
**Full statement:** https://cses.fi/problemset/task/1724  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed weighted graph, find the minimum total weight of a walk from vertex $1$ to vertex $n$ that uses exactly $k$ edges. Print $-1$ if no such walk exists.

## Input
The first line has $n$, $m$, $k$. The next $m$ lines give edges $a \to b$ with weight $c$.

## Output
Print the minimum path length, or $-1$ if impossible.

## Constraints
- $1 \le n \le 100$
- $1 \le m \le n(n-1)$
- $1 \le k \le 10^9$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
