# Visiting Cities

**CSES ID:** 1203  
**Full statement:** https://cses.fi/problemset/task/1203  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In a directed weighted graph with one-way flights, find the cities that lie on every minimum-price route from Syrjälä (city 1) to Lehmälä (city $n$).

## Input
First line: $n$ and $m$. Then $m$ lines each with a one-way flight $a \to b$ of price $c$. A route from 1 to $n$ is guaranteed.

## Output
Print the count $k$ of forced cities, then the $k$ city indices sorted increasingly.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
- $1 \le c \le 10^9$
