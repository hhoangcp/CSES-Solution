# New Flight Routes

**CSES ID:** 1685  
**Full statement:** https://cses.fi/problemset/task/1685  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed graph of $n$ cities and $m$ one-way flights, add the minimum number of new one-way flights so that the resulting graph becomes strongly connected.

## Input
First line: $n$ and $m$. Then $m$ lines each with a one-way flight $a \to b$.

## Output
Print the minimum number of new flights $k$, followed by $k$ lines describing the new flights; any valid solution is accepted.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
