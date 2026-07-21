# Flight Discount

**CSES ID:** 1195  
**Full statement:** https://cses.fi/problemset/task/1195  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed weighted graph, find the cheapest path from city $1$ to city $n$. You may use one coupon to halve (floor) the price of a single edge on the route.

## Input
$n$ and $m$, then $m$ lines each giving a directed flight $a \to b$ with price $c$.

## Output
One integer: the minimum total price achievable using the coupon once.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
