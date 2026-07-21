# Necessary Roads

**CSES ID:** 2076  
**Full statement:** https://cses.fi/problemset/task/2076  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a connected undirected graph of $n$ cities and $m$ roads, a road is necessary if removing it disconnects some previously connected pair of cities. Find all necessary roads.

## Input
First line: $n,m$. Then $m$ lines each with two integers $a,b$ (a road). At most one road per pair, no self-loops.

## Output
Print the count $k$ of necessary roads followed by $k$ lines describing those roads, in any order.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
