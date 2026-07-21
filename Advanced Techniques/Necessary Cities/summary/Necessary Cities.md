# Necessary Cities

**CSES ID:** 2077  
**Full statement:** https://cses.fi/problemset/task/2077  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a connected undirected graph of $n$ cities and $m$ roads, a city is necessary if deleting it (and its incident roads) disconnects some pair of previously connected cities. Find all necessary cities.

## Input
First line: $n,m$. Then $m$ lines each with two integers $a,b$ (a road). At most one road per pair, no self-loops.

## Output
Print the count $k$ of necessary cities followed by the list of those $k$ cities in any order.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
