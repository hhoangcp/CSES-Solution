# Building Roads

**CSES ID:** 1666  
**Full statement:** https://cses.fi/problemset/task/1666  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

A country has $n$ cities connected by $m$ existing roads. Add the fewest new roads so the network becomes connected. You choose which pairs to link.

## Input
Two integers $n, m$, then $m$ lines each with two city indices describing an existing road.

## Output
The minimum count of new roads $k$, followed by $k$ lines giving the endpoints of those roads.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
