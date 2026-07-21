# Road Reparation

**CSES ID:** 1675  
**Full statement:** https://cses.fi/problemset/task/1675  
**Time limit:** 1.00s | **Memory limit:** 128MB

> Problem summary.

An undirected weighted graph has $n$ cities and $m$ candidate roads, each with a repair cost. Choose roads to repair so the cities become connected at minimum total cost.

## Input
$n$ and $m$, then $m$ lines each giving an edge $a, b$ with cost $c$.

## Output
The minimum total repair cost, or `IMPOSSIBLE` if the graph cannot be connected.

## Constraints
- $1 \le n \le 10^5$
- $1 \le m \le 2 \cdot 10^5$
- $1 \le a,b \le n$
- $1 \le c \le 10^9$
