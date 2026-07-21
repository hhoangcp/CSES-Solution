# Critical Cities

**CSES ID:** 1703  
**Full statement:** https://cses.fi/problemset/task/1703  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

Given a directed graph of $n$ cities and $m$ one-way flights, a city is critical if it lies on every route from Syrjälä (city 1) to Lehmälä (city $n$). List all such cities in increasing order.

## Input
First line: $n$ and $m$. Then $m$ lines each with a one-way flight $a \to b$. A route from 1 to $n$ is guaranteed.

## Output
Print the count $k$ followed by the $k$ critical cities in increasing order.

## Constraints
- $2 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a, b \le n$
