# Creating Offices

**CSES ID:** 1752  
**Full statement:** https://cses.fi/problemset/task/1752  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A tree of $n$ cities is given (edge count = $n-1$, unique path between any two cities, distance = number of edges on that path). A company wants to open offices in a subset of cities such that the distance between any two chosen cities is at least $d$. Find the maximum number of offices and one such subset.

## Input
First line: $n$ and $d$. Then $n-1$ lines each describing a tree edge with endpoints $a,b$.

## Output
Print the maximum count $k$ followed by the chosen cities (any optimal subset is accepted).

## Constraints
- $1 \le n, d \le 2 \cdot 10^5$
- $1 \le a, b \le n$
