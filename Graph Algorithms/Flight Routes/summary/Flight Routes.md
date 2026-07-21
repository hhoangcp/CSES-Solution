# Flight Routes

**CSES ID:** 1196  
**Full statement:** https://cses.fi/problemset/task/1196  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed weighted graph, list the prices of the $k$ cheapest routes from city $1$ to city $n$, counting multiplicities when several routes tie. Cities may be revisited.

## Input
$n$, $m$, and $k$, then $m$ directed edges $a \to b$ with price $c$.

## Output
$k$ integers: the prices of the $k$ cheapest routes in nondecreasing order.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
- $1 \le k \le 10$
