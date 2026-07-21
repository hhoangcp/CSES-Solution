# Nearest Shops

**CSES ID:** 3303  
**Full statement:** https://cses.fi/problemset/task/3303  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In an undirected graph of $n$ cities with $m$ bidirectional roads, $k$ cities host an anime shop. For every city, find the shortest distance to a different city that also has a shop (the local shop, if any, does not count). Output $-1$ for cities with no such reachable shop.

## Input
First line: $n$, $m$, $k$. Second line: $k$ shop cities. Then $m$ roads, each as $a,b$.

## Output
Print $n$ integers: for each city the minimum distance to another shop city, or $-1$ if none exists.

## Constraints
- $1 \le k \le n \le 10^5$
- $0 \le m \le 2 \cdot 10^5$
