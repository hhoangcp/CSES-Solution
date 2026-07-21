# Flight Route Requests

**CSES ID:** 1699  
**Full statement:** https://cses.fi/problemset/task/1699  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ cities with airports but no flights yet. You receive $m$ unique reachability requests of the form "there must be a way to travel from $a$ to $b$". Determine the minimum number of one-way flights to add so every request is satisfied.

## Input
First line: $n$ and $m$. Then $m$ lines each with $a,b$ meaning a route from $a$ to $b$ must exist; requests are unique.

## Output
Print one integer: the minimum number of one-way flights to add.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
