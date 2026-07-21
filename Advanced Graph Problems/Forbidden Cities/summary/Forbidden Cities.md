# Forbidden Cities

**CSES ID:** 1705  
**Full statement:** https://cses.fi/problemset/task/1705  
**Time limit:** 1.00s | **Memory limit:** 512MB

> Problem summary.

In an undirected connected graph, process $q$ queries each asking whether one can travel from city $a$ to city $b$ without passing through city $c$.

## Input
First line: $n$, $m$, $q$. Then $m$ bidirectional roads each as $a,b$. Then $q$ query lines, each with $a,b,c$. The graph is connected.

## Output
For each query print `YES` if such a route exists, otherwise `NO`.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le q \le 10^5$
- $1 \le a, b, c \le n$
