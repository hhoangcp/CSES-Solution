# Pizzeria Queries

**CSES ID:** 2206  
**Full statement:** https://cses.fi/problemset/task/2206  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

There are $n$ buildings on a street, each with pizza price $p_k$. Ordering from building $a$ to building $b$ costs $p_a + |a-b|$. Queries either update a building's price or, for a given building $k$, ask for the minimum total price across all possible suppliers.

## Input
First line gives $n$ and $q$. Second line lists initial prices $p_1,\dots,p_n$. The $q$ query lines are either "1 $k$ $x$" (set price at $k$) or "2 $k$" (query minimum cost at $k$).

## Output
Print the answer to each type-2 query.

## Constraints
- $1 \le n,q \le 2 \cdot 10^5$
- $1 \le p_i, x \le 10^9$
- $1 \le k \le n$
