# Investigation

**CSES ID:** 1202  
**Full statement:** https://cses.fi/problemset/task/1202  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed weighted graph, travel from city $1$ to city $n$. Report four values: the minimum route price, the count of minimum-price routes (mod $10^9+7$), the fewest flights among such routes, and the most flights among such routes.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$ with price $c$.

## Output
Four integers: min price, route count mod $10^9+7$, min flight count, max flight count.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
