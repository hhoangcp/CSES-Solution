# Hamiltonian Flights

**CSES ID:** 1690  
**Full statement:** https://cses.fi/problemset/task/1690  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed graph of $n$ cities, count the number of paths from city $1$ to city $n$ that visit each city exactly once, modulo $10^9+7$.

## Input
$n$ and $m$, then $m$ directed edges $a \to b$.

## Output
One integer: the count modulo $10^9+7$.

## Constraints
- $2 \le n \le 20$
- $1 \le m \le n^2$
- $1 \le a,b \le n$
