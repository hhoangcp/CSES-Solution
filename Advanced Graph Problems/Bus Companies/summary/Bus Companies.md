# Bus Companies

**CSES ID:** 3158  
**Full statement:** https://cses.fi/problemset/task/3158  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ cities and $m$ bus companies, each operating in a fixed subset of cities and selling a single ticket at a fixed price. Buying a ticket lets you move freely between any two cities that company serves. Find the cheapest total cost to reach every city from city 1 (Syrjälä).

## Input
First line: $n$ and $m$. Second line: $m$ ticket costs $c_i$. Then for each company, a line with $k$ followed by a line listing its $k$ cities. Reachability from city 1 to all others is guaranteed.

## Output
Print $n$ integers: the minimum cost to reach cities $1,2,\dots,n$ from Syrjälä.

## Constraints
- $1 \le n, m \le 10^5$
- $1 \le c \le 10^9$
- $2 \le k \le n$
- $1 \le a \le n$
- total of all $k$ is at most $2 \cdot 10^5$
